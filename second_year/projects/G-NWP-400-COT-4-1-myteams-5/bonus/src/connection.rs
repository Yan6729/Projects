use dioxus::prelude::*;
use futures::channel::mpsc::{unbounded, UnboundedSender};
use futures::future::{select, Either};
use futures::{SinkExt, StreamExt};
use gloo_net::websocket::futures::WebSocket;
use gloo_net::websocket::Message;
use wasm_bindgen_futures::spawn_local;

pub const DEFAULT_WS_URL: &str = "ws://127.0.0.1:8765";

#[derive(Clone, Copy)]
pub struct AppConn {
    pub log: Signal<Vec<String>>,
    pub status: Signal<String>,
    pub cmd: Signal<Option<UnboundedSender<String>>>,
    pub shutdown: Signal<Option<UnboundedSender<()>>>,
}

impl AppConn {
    pub fn send_cmd(&self, line: &str) {
        let line = line.trim();
        if line.is_empty() {
            return;
        }
        let with_nl = if line.ends_with('\n') {
            line.to_string()
        } else {
            format!("{line}\n")
        };
        if let Some(ref tx) = self.cmd.peek().as_ref() {
            let _ = tx.unbounded_send(with_nl);
        }
    }

    pub fn disconnect(&self) {
        if let Some(ref tx) = self.shutdown.peek().as_ref() {
            let _ = tx.unbounded_send(());
        }
    }
}

pub fn start_session(ws_url: String, user_name: String, mut conn: AppConn, mut ready: Signal<bool>) {
    spawn_local(async move {
        conn.log.set(Vec::new());
        conn.status.set("Connexion WebSocket…".to_string());
        let ws = match WebSocket::open(&ws_url) {
            Ok(w) => w,
            Err(e) => {
                conn.status
                    .set(format!("Échec WebSocket (lance ws-tcp-bridge ?): {e:?}"));
                return;
            }
        };

        let (mut write, mut read) = ws.split();
        let login = format!("/login \"{}\"\n", user_name.replace('"', ""));
        if write.send(Message::Text(login)).await.is_err() {
            conn.status.set("Échec envoi /login".into());
            return;
        }

        let (cmd_tx, mut cmd_rx) = unbounded::<String>();
        let (shutdown_tx, mut shutdown_rx) = unbounded::<()>();
        conn.cmd.set(Some(cmd_tx));
        conn.shutdown.set(Some(shutdown_tx));
        conn.status.set(format!("Connecté en tant que {user_name}"));
        ready.set(true);

        let write = futures::lock::Mutex::new(write);
        let write_clone = std::sync::Arc::new(write);
        let wc = write_clone.clone();
        spawn_local(async move {
            while let Some(cmd) = cmd_rx.next().await {
                let mut w = wc.lock().await;
                if w.send(Message::Text(cmd)).await.is_err() {
                    break;
                }
            }
        });

        loop {
            let read_fut = read.next();
            let shut_fut = shutdown_rx.next();
            match select(read_fut, shut_fut).await {
                Either::Left((opt_msg, _)) => match opt_msg {
                    Some(Ok(Message::Text(t))) => {
                        conn.log.with_mut(|l| {
                            for line in t.split('\n') {
                                if !line.is_empty() {
                                    l.push(line.to_string());
                                }
                            }
                        });
                    }
                    Some(Ok(Message::Bytes(b))) => {
                        let t = String::from_utf8_lossy(&b);
                        conn.log.with_mut(|l| l.push(t.to_string()));
                    }
                    Some(Err(_)) | None => break,
                },
                Either::Right(_) => break,
            }
        }

        conn.status.set("Déconnecté".into());
        conn.cmd.set(None);
        conn.shutdown.set(None);
    });
}
