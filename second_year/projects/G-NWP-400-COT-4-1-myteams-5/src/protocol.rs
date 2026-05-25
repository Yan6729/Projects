//
// EPITECH PROJECT, 2026
// protocol.rs
// File description:
// command parsing and handling
//

use crate::log_server;
use crate::state::{
    gen_id, now_secs, AppState, Channel, DirectMessage, Team, Thread, ThreadReply, User,
};
use crate::types::ClientState;
use std::collections::{HashMap, HashSet};

pub enum OutEvt {
    ToAllLoggedExcept { except_id: u64, line: String },
    ToTeamSubscribersExcept { team_id: String, except_id: u64, line: String },
    ToUserUuid { user: String, line: String },
}

pub struct HandleOutcome {
    pub self_lines: Vec<String>,
    pub events: Vec<OutEvt>,
}

impl HandleOutcome {
    fn ok(mut self, line: impl Into<String>) -> Self {
        self.self_lines.push(line.into());
        self
    }
    fn empty() -> Self {
        Self { self_lines: Vec::new(), events: Vec::new() }
    }
}

pub fn handle_command(
    state: &mut AppState,
    clients: &mut HashMap<u64, ClientState>,
    client_id: u64,
    line: &str,
    connected_users: &HashSet<String>,
) {
    let outcome = {
        let Some(client) = clients.get_mut(&client_id) else { return; };
        process_command(state, client, client_id, line, connected_users)
    };
    apply_outcome(state, clients, client_id, outcome);
    // Persist eagerly so abrupt SIGINT after a command still leaves a save file.
    state.save();
}

fn apply_outcome(
    app: &AppState,
    clients: &mut HashMap<u64, ClientState>,
    client_id: u64,
    outcome: HandleOutcome,
) {
    if let Some(c) = clients.get_mut(&client_id) {
        for l in &outcome.self_lines { send_line(c, l); }
    }
    for ev in outcome.events {
        match ev {
            OutEvt::ToAllLoggedExcept { except_id, line } => {
                for (&id, c) in clients.iter_mut() {
                    if c.user_id.is_none() || id == except_id { continue; }
                    send_line(c, &line);
                }
            }
            OutEvt::ToTeamSubscribersExcept { team_id, except_id, line } => {
                for (&id, c) in clients.iter_mut() {
                    if id == except_id { continue; }
                    let Some(uid) = c.user_id.as_ref() else { continue; };
                    if !app.subscribed_to_team(uid, &team_id) { continue; }
                    send_line(c, &line);
                }
            }
            OutEvt::ToUserUuid { user, line } => {
                for (_id, c) in clients.iter_mut() {
                    if c.user_id.as_deref() == Some(user.as_str()) {
                        send_line(c, &line);
                    }
                }
            }
        }
    }
}

fn process_command(
    state: &mut AppState,
    client: &mut ClientState,
    client_id: u64,
    line: &str,
    connected_users: &HashSet<String>,
) -> HandleOutcome {
    if !line.starts_with('/') {
        return HandleOutcome::empty().ok("ERR usage: command must start with '/'");
    }
    let mut split = line.splitn(2, ' ');
    let cmd = split.next().unwrap_or_default();
    let rest = split.next().unwrap_or_default().trim();
    let args = match parse_quoted_args(rest) {
        Ok(v) => v,
        Err(e) => return HandleOutcome::empty().ok(format!("ERR {e}")),
    };
    match cmd {
        "/help"        => HandleOutcome::empty().ok("OK /help /login /logout /users /user /send /messages /subscribe /subscribed /unsubscribe /create /list /info"),
        "/login"       => handle_login(state, client, client_id, &args),
        "/logout"      => handle_logout(state, client, client_id, &args),
        "/users"       => handle_users(state, client, connected_users, &args),
        "/user"        => handle_user(state, client, connected_users, &args),
        "/send"        => handle_send(state, client, &args),
        "/messages"    => handle_messages(state, client, &args),
        "/subscribe"   => handle_subscribe(state, client, &args),
        "/subscribed"  => handle_subscribed(state, client, connected_users, &args),
        "/unsubscribe" => handle_unsubscribe(state, client, &args),
        "/create"      => handle_create(state, client, client_id, &args),
        "/list"        => handle_list(state, client, &args),
        "/info"        => handle_info(state, client, connected_users, &args),
        _              => HandleOutcome::empty().ok("ERR unknown command"),
    }
}

// FIX: reject double login
fn handle_login(state: &mut AppState, client: &mut ClientState, client_id: u64, args: &[String]) -> HandleOutcome {
    if args.len() != 1 {
        return HandleOutcome::empty().ok("ERR usage: /login requires exactly one quoted argument");
    }
    if client.user_id.is_some() {
        return HandleOutcome::empty().ok("ERR vous etes deja connecte");
    }
    let name = &args[0];
    if !validate_len(name, 32) {
        return HandleOutcome::empty().ok("ERR longueur du nom utilisateur invalide (1..32)");
    }
    let created_new = state.users_by_name.get(name).is_none();
    let user_id = if let Some(existing) = state.users_by_name.get(name) {
        existing.clone()
    } else {
        let id = gen_id();
        let user = User { id: id.clone(), name: name.clone() };
        state.users_by_name.insert(name.clone(), id.clone());
        state.users_by_id.insert(id.clone(), user);
        id
    };
    client.user_id = Some(user_id.clone());
    if created_new { log_server::user_created(&user_id, name); }
    log_server::user_logged_in(&user_id);
    let name_wire = name.replace('\t', " ");
    HandleOutcome {
        self_lines: vec![format!("OK logged_in\t{user_id}\t{name_wire}")],
        events: vec![OutEvt::ToAllLoggedExcept {
            except_id: client_id,
            line: format!("SYS_LOGIN\t{user_id}\t{name_wire}"),
        }],
    }
}

fn handle_logout(state: &mut AppState, client: &mut ClientState, client_id: u64, args: &[String]) -> HandleOutcome {
    if !args.is_empty() {
        return HandleOutcome::empty().ok("ERR /logout ne prend pas d'argument");
    }
    let Some(uid) = client.user_id.clone() else {
        return HandleOutcome::empty().ok("ERR vous devez etre connecte");
    };
    let uname = state.users_by_id.get(&uid).map(|u| u.name.clone()).unwrap_or_default();
    let uname_wire = uname.replace('\t', " ");
    log_server::user_logged_out(&uid);
    client.user_id = None;
    HandleOutcome {
        self_lines: vec![format!("OK logged_out\t{uid}\t{uname_wire}")],
        events: vec![OutEvt::ToAllLoggedExcept {
            except_id: client_id,
            line: format!("SYS_LOGOUT\t{uid}\t{uname_wire}"),
        }],
    }
}

fn handle_users(state: &mut AppState, client: &mut ClientState, connected_users: &HashSet<String>, args: &[String]) -> HandleOutcome {
    if !args.is_empty() { return HandleOutcome::empty().ok("ERR /users ne prend pas d'argument"); }
    if client.user_id.is_none() { return HandleOutcome::empty().ok("ERR vous devez etre connecte"); }
    let mut self_lines: Vec<String> = state.users_by_id.values()
        .map(|user| {
            let st = if connected_users.contains(&user.id) { 1 } else { 0 };
            format!("USER\t{}\t{}\t{}", user.id, user.name, st)
        })
        .collect();
    self_lines.push("OK fin de la liste".to_string());
    HandleOutcome { self_lines, events: vec![] }
}

fn handle_user(state: &mut AppState, client: &mut ClientState, connected_users: &HashSet<String>, args: &[String]) -> HandleOutcome {
    if client.user_id.is_none() { return HandleOutcome::empty().ok("ERR vous devez etre connecte"); }
    if args.len() != 1 {
        return HandleOutcome::empty().ok("ERR usage: /user requires exactly one quoted argument");
    }
    let user_id = &args[0];
    match state.users_by_id.get(user_id) {
        Some(u) => {
            let st = if connected_users.contains(user_id) { 1 } else { 0 };
            HandleOutcome { self_lines: vec![format!("INFO_USER\t{}\t{}\t{}", u.id, u.name, st)], events: vec![] }
        }
        None => HandleOutcome::empty().ok(format!("ERR utilisateur inconnu\t{user_id}")),
    }
}

fn handle_send(state: &mut AppState, client: &mut ClientState, args: &[String]) -> HandleOutcome {
    if args.len() != 2 { return HandleOutcome::empty().ok("ERR /send attend 2 arguments entre guillemets"); }
    let Some(from_id) = client.user_id.clone() else { return HandleOutcome::empty().ok("ERR vous devez etre connecte"); };
    let to = &args[0];
    let body = &args[1];
    if !state.users_by_id.contains_key(to) {
        return HandleOutcome::empty().ok(format!("ERR destinataire inconnu\t{to}"));
    }
    if !validate_len(body, 512) { return HandleOutcome::empty().ok("ERR longueur du message invalide (1..512)"); }
    let ts = now_secs();
    state.messages.push(DirectMessage { from: from_id.clone(), to: to.clone(), body: body.clone(), ts });
    log_server::private_message_sended(&from_id, to, body);
    let body_wire = body.replace('\t', " ");
    let mut events = Vec::new();
    if from_id != *to {
        events.push(OutEvt::ToUserUuid {
            user: to.clone(),
            line: format!("SYS_DM\t{from_id}\t{to}\t{ts}\t{body_wire}"),
        });
    }
    HandleOutcome {
        self_lines: vec![format!("OK_DM_SENT\t{from_id}\t{to}\t{ts}\t{body_wire}")],
        events,
    }
}

fn handle_messages(state: &mut AppState, client: &mut ClientState, args: &[String]) -> HandleOutcome {
    if args.len() != 1 { return HandleOutcome::empty().ok("ERR /messages attend 1 argument entre guillemets"); }
    let Some(me) = client.user_id.clone() else { return HandleOutcome::empty().ok("ERR vous devez etre connecte"); };
    let other = &args[0];
    if !state.users_by_id.contains_key(other.as_str()) {
        return HandleOutcome::empty().ok(format!("ERR utilisateur inconnu\t{other}"));
    }
    let mut self_lines: Vec<String> = state.messages.iter()
        .filter(|m| (m.from == me && m.to == *other) || (m.from == *other && m.to == me))
        .map(|m| format!("DM\t{}\t{}\t{}\t{}", m.from, m.to, m.ts, m.body.replace('\t', " ")))
        .collect();
    self_lines.push("OK fin des messages".to_string());
    HandleOutcome { self_lines, events: vec![] }
}

fn handle_subscribe(state: &mut AppState, client: &mut ClientState, args: &[String]) -> HandleOutcome {
    if args.len() != 1 { return HandleOutcome::empty().ok("ERR /subscribe attend 1 argument entre guillemets"); }
    let Some(uid) = client.user_id.clone() else { return HandleOutcome::empty().ok("ERR vous devez etre connecte"); };
    let team_id = &args[0];
    if !state.teams.contains_key(team_id) {
        return HandleOutcome::empty().ok(format!("ERR equipe inconnue\t{team_id}"));
    }
    state.subscriptions.entry(uid.clone()).or_default().insert(team_id.clone());
    log_server::user_subscribed(team_id, &uid);
    HandleOutcome::empty().ok(format!("OK_SUBSCRIBED\t{uid}\t{team_id}"))
}

fn handle_subscribed(state: &mut AppState, client: &mut ClientState, connected_users: &HashSet<String>, args: &[String]) -> HandleOutcome {
    if args.len() > 1 { return HandleOutcome::empty().ok("ERR /subscribed attend 0 ou 1 argument entre guillemets"); }
    let Some(uid) = client.user_id.clone() else { return HandleOutcome::empty().ok("ERR vous devez etre connecte"); };
    if args.is_empty() {
        let mut self_lines: Vec<String> = state.subscriptions.get(&uid)
            .map(|s| {
                let mut v: Vec<&Team> = s.iter().filter_map(|tid| state.teams.get(tid.as_str())).collect();
                v.sort_by(|a, b| a.id.cmp(&b.id));
                v
            })
            .unwrap_or_default()
            .into_iter()
            .map(|t| format!("LIST_TEAM\t{}\t{}\t{}", t.id, t.name.replace('\t', " "), t.description.replace('\t', " ")))
            .collect();
        self_lines.push("OK fin des equipes abonnees".to_string());
        return HandleOutcome { self_lines, events: vec![] };
    }
    let team_id = &args[0];
    if !state.teams.contains_key(team_id) { return HandleOutcome::empty().ok(format!("ERR equipe inconnue\t{team_id}")); }
    if !state.subscribed_to_team(&uid, team_id) { return HandleOutcome::empty().ok("ERR vous n'etes pas abonne a cette equipe"); }
    let subscribed_ids = state.users_subscribed_to_team(team_id);
    let mut self_lines: Vec<String> = subscribed_ids.into_iter()
        .filter_map(|user_id| {
            state.users_by_id.get(&user_id).map(|u| {
                let st = if connected_users.contains(&u.id) { 1 } else { 0 };
                format!("USER\t{}\t{}\t{}", u.id, u.name, st)
            })
        })
        .collect();
    self_lines.push("OK fin des membres de l'equipe".to_string());
    HandleOutcome { self_lines, events: vec![] }
}

fn handle_unsubscribe(state: &mut AppState, client: &mut ClientState, args: &[String]) -> HandleOutcome {
    if args.len() != 1 { return HandleOutcome::empty().ok("ERR /unsubscribe attend 1 argument entre guillemets"); }
    let Some(uid) = client.user_id.clone() else { return HandleOutcome::empty().ok("ERR vous devez etre connecte"); };
    let team_id = &args[0];
    if !state.teams.contains_key(team_id) { return HandleOutcome::empty().ok(format!("ERR equipe inconnue\t{team_id}")); }
    if let Some(set) = state.subscriptions.get_mut(&uid) { set.remove(team_id); }
    log_server::user_unsubscribed(team_id, &uid);
    HandleOutcome::empty().ok(format!("OK_UNSUBSCRIBED\t{uid}\t{team_id}"))
}

// FIX: 4-arg ambiguity resolved by checking if args[2] is an existing thread_id
fn handle_create(state: &mut AppState, client: &mut ClientState, client_id: u64, args: &[String]) -> HandleOutcome {
    let Some(uid) = client.user_id.clone() else {
        return HandleOutcome::empty().ok("ERR vous devez etre connecte");
    };
    match args.len() {
        2 => create_team(state, client_id, &uid, &args[0], &args[1]),
        3 => create_channel(state, client_id, &uid, &args[0], &args[1], &args[2]),
        4 => {
            // depth 2: args = [team_id, chan_id, title, body]      → thread
            // depth 3: args = [team_id, chan_id, thread_id, body]  → reply
            // Distinguish by checking if args[2] is an existing thread inside chan
            let is_reply = state.thread_exists(&args[0], &args[1], &args[2]);
            if is_reply {
                create_reply(state, client_id, &uid, &args[0], &args[1], &args[2], &args[3])
            } else {
                create_thread(state, client_id, &uid, &args[0], &args[1], &args[2], &args[3])
            }
        }
        _ => HandleOutcome::empty().ok(
            "ERR usage: /create invalid arguments for this context (see /help)",
        ),
    }
}

fn create_team(state: &mut AppState, client_id: u64, uid: &str, name: &str, desc: &str) -> HandleOutcome {
    if !validate_len(name, 32) || !validate_len(desc, 512) {
        return HandleOutcome::empty().ok("ERR longueur nom (1..32) ou description (1..512) invalide");
    }
    if state.teams.values().any(|t| t.name == name) {
        return HandleOutcome::empty().ok("ERR already_exist");
    }
    let id = gen_id();
    state.teams.insert(id.clone(), Team { id: id.clone(), name: name.to_string(), description: desc.to_string(), channels: HashMap::new() });
    state.subscriptions.entry(uid.to_string()).or_default().insert(id.clone());
    log_server::team_created(&id, name, uid);
    log_server::user_subscribed(&id, uid);
    let nm = name.replace('\t', " ");
    let dc = desc.replace('\t', " ");
    // FIX: creator gets OK_TEAM_CREATED (print_team_created), other logged users
    // get SYS_TEAM (event_team_created). Do NOT send SYS_TEAM to creator too.
    HandleOutcome {
        self_lines: vec![format!("OK_TEAM_CREATED\t{id}\t{nm}\t{dc}")],
        events: vec![OutEvt::ToAllLoggedExcept {
            except_id: client_id,
            line: format!("SYS_TEAM\t{id}\t{nm}\t{dc}"),
        }],
    }
}

fn create_channel(state: &mut AppState, client_id: u64, uid: &str, team_id: &str, name: &str, desc: &str) -> HandleOutcome {
    if !state.teams.contains_key(team_id) { return HandleOutcome::empty().ok(format!("ERR equipe inconnue\t{team_id}")); }
    if !state.subscribed_to_team(uid, team_id) { return HandleOutcome::empty().ok("ERR vous devez etre abonne a l'equipe"); }
    if !validate_len(name, 32) || !validate_len(desc, 512) {
        return HandleOutcome::empty().ok("ERR longueur nom (1..32) ou description (1..512) invalide");
    }
    let dup = state.teams.get(team_id).map(|t| t.channels.values().any(|c| c.name == name)).unwrap_or(false);
    if dup { return HandleOutcome::empty().ok("ERR already_exist"); }
    let ch_id = gen_id();
    if let Some(team) = state.teams.get_mut(team_id) {
        team.channels.insert(ch_id.clone(), Channel { id: ch_id.clone(), name: name.to_string(), description: desc.to_string(), threads: HashMap::new() });
    }
    log_server::channel_created(team_id, &ch_id, name);
    let nm = name.replace('\t', " ");
    let dc = desc.replace('\t', " ");
    HandleOutcome {
        self_lines: vec![format!("OK_CH_CREATED\t{ch_id}\t{nm}\t{dc}")],
        events: vec![OutEvt::ToTeamSubscribersExcept { team_id: team_id.to_string(), except_id: client_id, line: format!("SYS_CH\t{ch_id}\t{nm}\t{dc}") }],
    }
}

fn create_thread(state: &mut AppState, client_id: u64, uid: &str, team_id: &str, channel_id: &str, title: &str, body: &str) -> HandleOutcome {
    if !state.teams.contains_key(team_id) { return HandleOutcome::empty().ok(format!("ERR equipe inconnue\t{team_id}")); }
    if !state.subscribed_to_team(uid, team_id) { return HandleOutcome::empty().ok("ERR vous devez etre abonne a l'equipe"); }
    let ch_exists = state.teams.get(team_id).map(|t| t.channels.contains_key(channel_id)).unwrap_or(false);
    if !ch_exists { return HandleOutcome::empty().ok(format!("ERR canal inconnu\t{channel_id}")); }
    if !validate_len(title, 32) || !validate_len(body, 255) {
        return HandleOutcome::empty().ok("ERR longueur titre (1..32) ou message initial (1..255) invalide");
    }
    let dup = state.teams.get(team_id).and_then(|t| t.channels.get(channel_id))
        .map(|ch| ch.threads.values().any(|th| th.title == title)).unwrap_or(false);
    if dup { return HandleOutcome::empty().ok("ERR already_exist"); }
    let th_id = gen_id();
    let ts = now_secs();
    if let Some(team) = state.teams.get_mut(team_id) {
        if let Some(ch) = team.channels.get_mut(channel_id) {
            ch.threads.insert(th_id.clone(), Thread { id: th_id.clone(), title: title.to_string(), initial_body: body.to_string(), creator_id: uid.to_string(), created_at: ts, replies: Vec::new() });
        }
    }
    log_server::thread_created(channel_id, &th_id, uid, title, body);
    let ti = title.replace('\t', " ");
    let bo = body.replace('\t', " ");
    HandleOutcome {
        self_lines: vec![format!("OK_TH_CREATED\t{th_id}\t{uid}\t{ts}\t{ti}\t{bo}")],
        events: vec![OutEvt::ToTeamSubscribersExcept { team_id: team_id.to_string(), except_id: client_id, line: format!("SYS_TH\t{th_id}\t{uid}\t{ts}\t{ti}\t{bo}") }],
    }
}

fn create_reply(state: &mut AppState, client_id: u64, uid: &str, team_id: &str, channel_id: &str, thread_id: &str, body: &str) -> HandleOutcome {
    if !state.teams.contains_key(team_id) { return HandleOutcome::empty().ok(format!("ERR equipe inconnue\t{team_id}")); }
    if !state.subscribed_to_team(uid, team_id) { return HandleOutcome::empty().ok("ERR vous devez etre abonne a l'equipe"); }
    let ch_exists = state.teams.get(team_id).map(|t| t.channels.contains_key(channel_id)).unwrap_or(false);
    if !ch_exists { return HandleOutcome::empty().ok(format!("ERR canal inconnu\t{channel_id}")); }
    if !state.thread_exists(team_id, channel_id, thread_id) {
        return HandleOutcome::empty().ok(format!("ERR fil inconnu\t{thread_id}"));
    }
    if !validate_len(body, 512) { return HandleOutcome::empty().ok("ERR longueur du commentaire invalide (1..512)"); }
    let ts = now_secs();
    if let Some(team) = state.teams.get_mut(team_id) {
        if let Some(ch) = team.channels.get_mut(channel_id) {
            if let Some(th) = ch.threads.get_mut(thread_id) {
                th.replies.push(ThreadReply { author_id: uid.to_string(), body: body.to_string(), created_at: ts });
            }
        }
    }
    log_server::reply_created(thread_id, uid, body);
    let body_wire = body.replace('\t', " ");
    HandleOutcome {
        self_lines: vec![format!("OK_RP_CREATED\t{thread_id}\t{uid}\t{ts}\t{body_wire}")],
        events: vec![OutEvt::ToTeamSubscribersExcept {
            team_id: team_id.to_string(),
            except_id: client_id,
            line: format!("SYS_REPLY\t{team_id}\t{channel_id}\t{thread_id}\t{uid}\t{body_wire}"),
        }],
    }
}

fn handle_list(state: &mut AppState, client: &mut ClientState, args: &[String]) -> HandleOutcome {
    if client.user_id.is_none() { return HandleOutcome::empty().ok("ERR vous devez etre connecte"); }
    let mut self_lines: Vec<String> = Vec::new();
    match args.len() {
        0 => {
            for t in state.teams.values() {
                self_lines.push(format!("LIST_TEAM\t{}\t{}\t{}", t.id, t.name.replace('\t', " "), t.description.replace('\t', " ")));
            }
            self_lines.push("OK fin de la liste".to_string());
        }
        1 => {
            let team_id = &args[0];
            let Some(team) = state.teams.get(team_id) else { return HandleOutcome::empty().ok(format!("ERR equipe inconnue\t{team_id}")); };
            for ch in team.channels.values() {
                self_lines.push(format!("LIST_CH\t{}\t{}\t{}", ch.id, ch.name.replace('\t', " "), ch.description.replace('\t', " ")));
            }
            self_lines.push("OK fin de la liste".to_string());
        }
        2 => {
            let team_id = &args[0];
            let channel_id = &args[1];
            let Some(team) = state.teams.get(team_id) else { return HandleOutcome::empty().ok(format!("ERR equipe inconnue\t{team_id}")); };
            let Some(ch) = team.channels.get(channel_id) else { return HandleOutcome::empty().ok(format!("ERR canal inconnu\t{channel_id}")); };
            for th in ch.threads.values() {
                self_lines.push(format!("LIST_TH\t{}\t{}\t{}\t{}\t{}", th.id, th.creator_id, th.created_at, th.title.replace('\t', " "), th.initial_body.replace('\t', " ")));
            }
            self_lines.push("OK fin de la liste".to_string());
        }
        3 => {
            let team_id = &args[0];
            let channel_id = &args[1];
            let thread_id = &args[2];
            let Some(team) = state.teams.get(team_id) else { return HandleOutcome::empty().ok(format!("ERR equipe inconnue\t{team_id}")); };
            let Some(ch) = team.channels.get(channel_id) else { return HandleOutcome::empty().ok(format!("ERR canal inconnu\t{channel_id}")); };
            let Some(th) = ch.threads.get(thread_id) else { return HandleOutcome::empty().ok(format!("ERR fil inconnu\t{thread_id}")); };
            self_lines.push(format!("LIST_RP\t{}\t{}\t{}\t{}", thread_id, th.creator_id, th.created_at, th.initial_body.replace('\t', " ")));
            for r in &th.replies {
                self_lines.push(format!("LIST_RP\t{}\t{}\t{}\t{}", thread_id, r.author_id, r.created_at, r.body.replace('\t', " ")));
            }
            self_lines.push("OK fin de la liste".to_string());
        }
        _ => return HandleOutcome::empty().ok("ERR /list attend 0 a 3 arguments entre guillemets"),
    }
    HandleOutcome { self_lines, events: vec![] }
}

fn handle_info(state: &mut AppState, client: &mut ClientState, connected_users: &HashSet<String>, args: &[String]) -> HandleOutcome {
    let Some(me) = client.user_id.clone() else { return HandleOutcome::empty().ok("ERR vous devez etre connecte"); };
    match args.len() {
        0 => {
            let Some(u) = state.users_by_id.get(&me) else { return HandleOutcome::empty().ok("ERR utilisateur inconnu"); };
            let st = if connected_users.contains(&me) { 1 } else { 0 };
            HandleOutcome {
                self_lines: vec![format!("INFO_USER\t{}\t{}\t{}", u.id, u.name.replace('\t', " "), st), "OK fin des informations".to_string()],
                events: vec![],
            }
        }
        1 => {
            let team_id = &args[0];
            let Some(t) = state.teams.get(team_id) else { return HandleOutcome::empty().ok(format!("ERR equipe inconnue\t{team_id}")); };
            HandleOutcome {
                self_lines: vec![format!("INFO_TEAM\t{}\t{}\t{}", t.id, t.name.replace('\t', " "), t.description.replace('\t', " ")), "OK fin des informations".to_string()],
                events: vec![],
            }
        }
        2 => {
            let team_id = &args[0];
            let channel_id = &args[1];
            let Some(team) = state.teams.get(team_id) else { return HandleOutcome::empty().ok(format!("ERR equipe inconnue\t{team_id}")); };
            let Some(ch) = team.channels.get(channel_id) else { return HandleOutcome::empty().ok(format!("ERR canal inconnu\t{channel_id}")); };
            HandleOutcome {
                self_lines: vec![format!("INFO_CH\t{}\t{}\t{}", ch.id, ch.name.replace('\t', " "), ch.description.replace('\t', " ")), "OK fin des informations".to_string()],
                events: vec![],
            }
        }
        3 => {
            let team_id = &args[0];
            let channel_id = &args[1];
            let thread_id = &args[2];
            let Some(team) = state.teams.get(team_id) else { return HandleOutcome::empty().ok(format!("ERR equipe inconnue\t{team_id}")); };
            let Some(ch) = team.channels.get(channel_id) else { return HandleOutcome::empty().ok(format!("ERR canal inconnu\t{channel_id}")); };
            let Some(th) = ch.threads.get(thread_id) else { return HandleOutcome::empty().ok(format!("ERR fil inconnu\t{thread_id}")); };
            HandleOutcome {
                self_lines: vec![format!("INFO_TH\t{}\t{}\t{}\t{}\t{}", th.id, th.creator_id, th.created_at, th.title.replace('\t', " "), th.initial_body.replace('\t', " ")), "OK fin des informations".to_string()],
                events: vec![],
            }
        }
        _ => HandleOutcome::empty().ok("ERR /info attend 0 a 3 arguments entre guillemets"),
    }
}

pub fn send_line(client: &mut ClientState, line: &str) {
    client.out_buf.extend(line.as_bytes());
    client.out_buf.push_back(b'\n');
}

fn validate_len(s: &str, max: usize) -> bool {
    !s.is_empty() && s.chars().count() <= max
}

fn parse_quoted_args(raw: &str) -> Result<Vec<String>, String> {
    let mut args = Vec::new();
    let bytes = raw.as_bytes();
    let mut i = 0usize;
    while i < bytes.len() {
        while i < bytes.len() && bytes[i].is_ascii_whitespace() { i += 1; }
        if i >= bytes.len() { break; }
        if bytes[i] != b'"' {
            return Err("quote: every argument must be wrapped in double quotes".to_string());
        }
        i += 1;
        let start = i;
        while i < bytes.len() && bytes[i] != b'"' { i += 1; }
        if i >= bytes.len() {
            return Err("quote: missing closing double quote".to_string());
        }
        args.push(raw[start..i].to_string());
        i += 1;
    }
    Ok(args)
}
