//
// EPITECH PROJECT, 2026
// state.rs
// File description:
// app state and persistence
//

use std::collections::{HashMap, HashSet};
use std::fs;
use std::io::Read;
use std::path::Path;
use std::time::{SystemTime, UNIX_EPOCH};

const SAVE_FILE: &str = "myteams.save";
const LEGACY_SAVE_FILE: &str = "myteams_save.db";

#[derive(Clone)]
pub struct User {
    pub id: String,
    pub name: String,
}

#[derive(Clone)]
pub struct DirectMessage {
    pub from: String,
    pub to: String,
    pub body: String,
    pub ts: i64,
}

#[derive(Clone)]
pub struct Team {
    pub id: String,
    pub name: String,
    pub description: String,
    pub channels: HashMap<String, Channel>,
}

#[derive(Clone)]
pub struct Channel {
    pub id: String,
    pub name: String,
    pub description: String,
    pub threads: HashMap<String, Thread>,
}

#[derive(Clone)]
pub struct Thread {
    pub id: String,
    pub title: String,
    pub initial_body: String,
    pub creator_id: String,
    pub created_at: i64,
    pub replies: Vec<ThreadReply>,
}

#[derive(Clone)]
pub struct ThreadReply {
    pub author_id: String,
    pub body: String,
    pub created_at: i64,
}

pub struct AppState {
    pub users_by_id: HashMap<String, User>,
    pub users_by_name: HashMap<String, String>,
    pub messages: Vec<DirectMessage>,
    pub teams: HashMap<String, Team>,
    /// utilisateur_id -> equipes abonnees
    pub subscriptions: HashMap<String, HashSet<String>>,
}

impl AppState {
    pub fn new() -> Self {
        Self {
            users_by_id: HashMap::new(),
            users_by_name: HashMap::new(),
            messages: Vec::new(),
            teams: HashMap::new(),
            subscriptions: HashMap::new(),
        }
    }

    pub fn load_or_empty() -> Self {
        let save_path = if Path::new(SAVE_FILE).exists() {
            SAVE_FILE
        } else if Path::new(LEGACY_SAVE_FILE).exists() {
            LEGACY_SAVE_FILE
        } else {
            return Self::new();
        };
        let raw = match fs::read_to_string(save_path) {
            Ok(v) => v,
            Err(_) => return Self::new(),
        };
        let mut app = Self::new();
        for line in raw.lines() {
            let parts: Vec<&str> = line.split('\t').collect();
            if parts.is_empty() {
                continue;
            }
            match parts[0] {
                "USER" if parts.len() >= 3 => {
                    let id = parts[1].to_string();
                    let name = unescape(parts[2]);
                    app.users_by_name.insert(name.clone(), id.clone());
                    app.users_by_id.insert(id.clone(), User { id, name });
                }
                "DM" if parts.len() >= 4 => {
                    let (ts, body) = if parts.len() >= 5 {
                        (
                            parts[3].parse::<i64>().unwrap_or(0),
                            unescape(parts[4]),
                        )
                    } else {
                        (0, unescape(parts[3]))
                    };
                    app.messages.push(DirectMessage {
                        from: parts[1].to_string(),
                        to: parts[2].to_string(),
                        body,
                        ts,
                    });
                }
                "TEAM" if parts.len() >= 4 => {
                    let id = parts[1].to_string();
                    let name = unescape(parts[2]);
                    let description = unescape(parts[3]);
                    app.teams.insert(
                        id.clone(),
                        Team {
                            id,
                            name,
                            description,
                            channels: HashMap::new(),
                        },
                    );
                }
                "CH" if parts.len() >= 5 => {
                    let team_id = parts[1].to_string();
                    let ch_id = parts[2].to_string();
                    let name = unescape(parts[3]);
                    let description = unescape(parts[4]);
                    if let Some(team) = app.teams.get_mut(&team_id) {
                        team.channels.insert(
                            ch_id.clone(),
                            Channel {
                                id: ch_id,
                                name,
                                description,
                                threads: HashMap::new(),
                            },
                        );
                    }
                }
                "TH" if parts.len() >= 6 => {
                    let team_id = parts[1].to_string();
                    let ch_id = parts[2].to_string();
                    let th_id = parts[3].to_string();
                    let title = unescape(parts[4]);
                    let initial = unescape(parts[5]);
                    let creator_id = parts.get(6).unwrap_or(&"").to_string();
                    let created_at = if parts.len() >= 8 {
                        parts[7].parse::<i64>().unwrap_or(0)
                    } else {
                        0
                    };
                    if let Some(team) = app.teams.get_mut(&team_id) {
                        if let Some(ch) = team.channels.get_mut(&ch_id) {
                            ch.threads.insert(
                                th_id.clone(),
                                Thread {
                                    id: th_id,
                                    title,
                                    initial_body: initial,
                                    creator_id,
                                    created_at,
                                    replies: Vec::new(),
                                },
                            );
                        }
                    }
                }
                "REP" if parts.len() >= 6 => {
                    let team_id = parts[1].to_string();
                    let ch_id = parts[2].to_string();
                    let th_id = parts[3].to_string();
                    let author = parts[4].to_string();
                    let (body, ts) = if parts.len() >= 7 {
                        (
                            unescape(parts[5]),
                            parts[6].parse::<i64>().unwrap_or(0),
                        )
                    } else {
                        (unescape(parts[5]), 0)
                    };
                    if let Some(team) = app.teams.get_mut(&team_id) {
                        if let Some(ch) = team.channels.get_mut(&ch_id) {
                            if let Some(th) = ch.threads.get_mut(&th_id) {
                                th.replies.push(ThreadReply {
                                    author_id: author,
                                    body,
                                    created_at: ts,
                                });
                            }
                        }
                    }
                }
                "SUB" if parts.len() >= 3 => {
                    let user_id = parts[1].to_string();
                    let team_id = parts[2].to_string();
                    app.subscriptions
                        .entry(user_id)
                        .or_default()
                        .insert(team_id);
                }
                _ => {}
            }
        }
        app
    }

    pub fn save(&self) {
        let mut out = String::new();
        for user in self.users_by_id.values() {
            out.push_str("USER\t");
            out.push_str(&user.id);
            out.push('\t');
            out.push_str(&escape(&user.name));
            out.push('\n');
        }
        for dm in &self.messages {
            out.push_str("DM\t");
            out.push_str(&dm.from);
            out.push('\t');
            out.push_str(&dm.to);
            out.push('\t');
            out.push_str(&dm.ts.to_string());
            out.push('\t');
            out.push_str(&escape(&dm.body));
            out.push('\n');
        }
        for team in self.teams.values() {
            out.push_str("TEAM\t");
            out.push_str(&team.id);
            out.push('\t');
            out.push_str(&escape(&team.name));
            out.push('\t');
            out.push_str(&escape(&team.description));
            out.push('\n');
            for ch in team.channels.values() {
                out.push_str("CH\t");
                out.push_str(&team.id);
                out.push('\t');
                out.push_str(&ch.id);
                out.push('\t');
                out.push_str(&escape(&ch.name));
                out.push('\t');
                out.push_str(&escape(&ch.description));
                out.push('\n');
                for th in ch.threads.values() {
                    out.push_str("TH\t");
                    out.push_str(&team.id);
                    out.push('\t');
                    out.push_str(&ch.id);
                    out.push('\t');
                    out.push_str(&th.id);
                    out.push('\t');
                    out.push_str(&escape(&th.title));
                    out.push('\t');
                    out.push_str(&escape(&th.initial_body));
                    out.push('\t');
                    out.push_str(&th.creator_id);
                    out.push('\t');
                    out.push_str(&th.created_at.to_string());
                    out.push('\n');
                    for r in &th.replies {
                        out.push_str("REP\t");
                        out.push_str(&team.id);
                        out.push('\t');
                        out.push_str(&ch.id);
                        out.push('\t');
                        out.push_str(&th.id);
                        out.push('\t');
                        out.push_str(&r.author_id);
                        out.push('\t');
                        out.push_str(&escape(&r.body));
                        out.push('\t');
                        out.push_str(&r.created_at.to_string());
                        out.push('\n');
                    }
                }
            }
        }
        for (user_id, teams) in &self.subscriptions {
            for team_id in teams {
                out.push_str("SUB\t");
                out.push_str(user_id);
                out.push('\t');
                out.push_str(team_id);
                out.push('\n');
            }
        }
        let _ = fs::write(SAVE_FILE, out);
    }

    pub fn subscribed_to_team(&self, user_id: &str, team_id: &str) -> bool {
        self.subscriptions
            .get(user_id)
            .map(|s| s.contains(team_id))
            .unwrap_or(false)
    }

    pub fn thread_exists(&self, team_id: &str, channel_id: &str, thread_id: &str) -> bool {
        self.teams
            .get(team_id)
            .and_then(|t| t.channels.get(channel_id))
            .and_then(|c| c.threads.get(thread_id))
            .is_some()
    }

    pub fn users_subscribed_to_team(&self, team_id: &str) -> Vec<String> {
        let mut v: Vec<String> = self
            .subscriptions
            .iter()
            .filter(|(_, teams)| teams.contains(team_id))
            .map(|(uid, _)| uid.clone())
            .collect();
        v.sort();
        v
    }
}

pub fn now_secs() -> i64 {
    SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .map(|d| d.as_secs() as i64)
        .unwrap_or(0)
}

fn fill_random_fallback(buf: &mut [u8; 16]) {
    let mut x = now_secs() as u64;
    for (i, slot) in buf.iter_mut().enumerate() {
        x = x.wrapping_mul(6364136223846793005).wrapping_add(i as u64 + 1);
        *slot = (x ^ (x >> 33)) as u8;
    }
}

/// New resource ids are RFC 4122 UUID v4 strings (36 chars with hyphens).
pub fn gen_id() -> String {
    let mut b = [0u8; 16];
    #[cfg(unix)]
    {
        if let Ok(mut f) = std::fs::File::open("/dev/urandom") {
            if f.read_exact(&mut b).is_err() {
                fill_random_fallback(&mut b);
            }
        } else {
            fill_random_fallback(&mut b);
        }
    }
    #[cfg(not(unix))]
    {
        fill_random_fallback(&mut b);
    }
    b[6] = (b[6] & 0x0f) | 0x40;
    b[8] = (b[8] & 0x3f) | 0x80;
    format!(
        "{:02x}{:02x}{:02x}{:02x}-{:02x}{:02x}-{:02x}{:02x}-{:02x}{:02x}-{:02x}{:02x}{:02x}{:02x}{:02x}{:02x}",
        b[0],
        b[1],
        b[2],
        b[3],
        b[4],
        b[5],
        b[6],
        b[7],
        b[8],
        b[9],
        b[10],
        b[11],
        b[12],
        b[13],
        b[14],
        b[15],
    )
}

fn escape(s: &str) -> String {
    s.replace('\\', "\\\\")
        .replace('\t', "\\t")
        .replace('\n', "\\n")
}

fn unescape(s: &str) -> String {
    let mut out = String::new();
    let mut chars = s.chars();
    while let Some(c) = chars.next() {
        if c == '\\' {
            match chars.next() {
                Some('t') => out.push('\t'),
                Some('n') => out.push('\n'),
                Some('\\') => out.push('\\'),
                Some(other) => {
                    out.push('\\');
                    out.push(other);
                }
                None => out.push('\\'),
            }
        } else {
            out.push(c);
        }
    }
    out
}
