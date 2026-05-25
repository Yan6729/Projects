//
// EPITECH PROJECT, 2026
// runtime.rs
// File description:
// server runtime event loop
//

use crate::log_server;
use crate::protocol::handle_command;
use crate::state::AppState;
use crate::types::ClientState;
use std::collections::{HashMap, HashSet, VecDeque};
use std::io::{ErrorKind, Read, Write};
use std::net::{Shutdown, TcpListener};
use std::sync::atomic::{AtomicBool, Ordering};

static RUNNING: AtomicBool = AtomicBool::new(true);

extern "C" fn handle_sigint(_: i32) {
    RUNNING.store(false, Ordering::Relaxed);
}

unsafe extern "C" {
    fn signal(sig: i32, handler: extern "C" fn(i32)) -> usize;
}

#[repr(C)]
struct Timespec {
    tv_sec: i64,
    tv_nsec: i64,
}

unsafe extern "C" {
    fn nanosleep(req: *const Timespec, rem: *mut Timespec) -> i32;
}

fn sleep_ms(ms: u64) {
    let sec = (ms / 1000) as i64;
    let nsec = ((ms % 1000) * 1_000_000) as i64;
    let ts = Timespec { tv_sec: sec, tv_nsec: nsec };
    unsafe {
        let _ = nanosleep(&ts, std::ptr::null_mut());
    }
}

fn install_sigint_handler() {
    const SIGINT: i32 = 2;
    unsafe {
        let _ = signal(SIGINT, handle_sigint);
    }
}

pub fn run_server(port: u16) {
    install_sigint_handler();
    let listener = match TcpListener::bind(("0.0.0.0", port)) {
        Ok(v) => v,
        Err(_) => {
            std::process::exit(84);
        }
    };
    if listener.set_nonblocking(true).is_err() {
        std::process::exit(84);
    }

    let mut app = AppState::load_or_empty();
    for u in app.users_by_id.values() {
        log_server::user_loaded(&u.id, &u.name);
    }
    let mut clients: HashMap<u64, ClientState> = HashMap::new();
    let mut next_client_id: u64 = 1;

    while RUNNING.load(Ordering::Relaxed) {
        loop {
            match listener.accept() {
                Ok((stream, _)) => {
                    if stream.set_nonblocking(true).is_err() {
                        continue;
                    }
                    let id = next_client_id;
                    next_client_id = next_client_id.saturating_add(1);
                    clients.insert(
                        id,
                        ClientState {
                            stream,
                            in_buf: Vec::new(),
                            out_buf: VecDeque::new(),
                            user_id: None,
                        },
                    );
                }
                Err(e) if e.kind() == ErrorKind::WouldBlock => break,
                Err(_) => break,
            }
        }

        let mut to_remove: Vec<u64> = Vec::new();
        let ids: Vec<u64> = clients.keys().cloned().collect();

        for id in ids {
            // --- READ PHASE ---
            let mut pending_lines: Vec<String> = Vec::new();
            let mut disconnect = false;

            {
                let Some(client) = clients.get_mut(&id) else {
                    continue;
                };
                let mut buf = [0u8; 4096];
                loop {
                    match client.stream.read(&mut buf) {
                        Ok(0) => {
                            disconnect = true;
                            break;
                        }
                        Ok(n) => {
                            client.in_buf.extend_from_slice(&buf[..n]);
                            while let Some(pos) = client.in_buf.iter().position(|&b| b == b'\n') {
                                let line =
                                    String::from_utf8_lossy(&client.in_buf[..pos]).to_string();
                                let line = line.trim_end_matches('\r').to_string();
                                client.in_buf.drain(..=pos);
                                pending_lines.push(line);
                            }
                        }
                        Err(e) if e.kind() == ErrorKind::WouldBlock => break,
                        Err(_) => {
                            disconnect = true;
                            break;
                        }
                    }
                }
            }

            if disconnect {
                to_remove.push(id);
                continue;
            }

            for line in pending_lines {
                let connected_users: HashSet<String> = clients
                    .values()
                    .filter_map(|c| c.user_id.clone())
                    .collect();
                handle_command(&mut app, &mut clients, id, &line, &connected_users);
            }

            {
                let Some(client) = clients.get_mut(&id) else {
                    continue;
                };
                while !client.out_buf.is_empty() {
                    let mut chunk = Vec::with_capacity(4096);
                    while chunk.len() < 4096 {
                        if let Some(b) = client.out_buf.pop_front() {
                            chunk.push(b);
                        } else {
                            break;
                        }
                    }
                    if chunk.is_empty() {
                        break;
                    }
                    match client.stream.write(&chunk) {
                        Ok(0) => {
                            to_remove.push(id);
                            break;
                        }
                        Ok(written) if written < chunk.len() => {
                            for b in chunk[written..].iter().rev() {
                                client.out_buf.push_front(*b);
                            }
                            break;
                        }
                        Ok(_) => {}
                        Err(e) if e.kind() == ErrorKind::WouldBlock => {
                            for b in chunk.iter().rev() {
                                client.out_buf.push_front(*b);
                            }
                            break;
                        }
                        Err(_) => {
                            to_remove.push(id);
                            break;
                        }
                    }
                }
            }
        }

        to_remove.sort_unstable();
        to_remove.dedup();
        for id in to_remove {
            if let Some(c) = clients.remove(&id) {
                if let Some(uid) = &c.user_id {
                    log_server::user_logged_out(uid);
                    let user_name = app
                        .users_by_id
                        .get(uid)
                        .map(|u| u.name.clone())
                        .unwrap_or_default();
                    let sys_line = format!(
                        "SYS_LOGOUT\t{}\t{}",
                        uid,
                        user_name.replace('\t', " ")
                    );
                    for other in clients.values_mut() {
                        if other.user_id.is_some() {
                            crate::protocol::send_line(other, &sys_line);
                        }
                    }
                }
                let _ = c.stream.shutdown(Shutdown::Both);
            }
        }

        sleep_ms(10);
    }

    app.save();
}
