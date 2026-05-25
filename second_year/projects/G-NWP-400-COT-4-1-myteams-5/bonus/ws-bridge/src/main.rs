//! Relays WebSocket text frames <-> TCP lines to `myteams_server`.
//!
//! Usage: ws-tcp-bridge [TCP_HOST:PORT] [WS_BIND]
//! Defaults: 127.0.0.1:4242  127.0.0.1:8765

use futures_util::{SinkExt, StreamExt};
use std::io;
use tokio::io::{AsyncReadExt, AsyncWriteExt};
use tokio::net::{TcpListener, TcpStream};
use tokio_tungstenite::accept_async;
use tokio_tungstenite::tungstenite::Message;
use tokio_tungstenite::WebSocketStream;

async fn relay(ws: WebSocketStream<TcpStream>, tcp: TcpStream) {
    let (mut tcp_read, mut tcp_write) = tcp.into_split();
    let (mut ws_write, mut ws_read) = ws.split();

    let mut tcp_buf = vec![0u8; 8192];
    let mut line_buf: Vec<u8> = Vec::new();

    loop {
        tokio::select! {
            n = tcp_read.read(&mut tcp_buf) => {
                match n {
                    Ok(0) => break,
                    Ok(n) => {
                        line_buf.extend_from_slice(&tcp_buf[..n]);
                        while let Some(pos) = line_buf.iter().position(|&b| b == b'\n') {
                            let line =
                                String::from_utf8_lossy(&line_buf[..pos].to_vec()).into_owned();
                            line_buf.drain(..=pos);
                            if ws_write.send(Message::Text(line)).await.is_err() {
                                return;
                            }
                        }
                    }
                    Err(_) => break,
                }
            }
            msg = ws_read.next() => {
                let msg = match msg {
                    Some(Ok(m)) => m,
                    _ => break,
                };
                match msg {
                    Message::Text(t) => {
                        for line in t.lines() {
                            if line.trim().is_empty() {
                                continue;
                            }
                            if tcp_write.write_all(line.as_bytes()).await.is_err() {
                                return;
                            }
                            if tcp_write.write_all(b"\n").await.is_err() {
                                return;
                            }
                        }
                    }
                    Message::Binary(b) => {
                        if tcp_write.write_all(&b).await.is_err() {
                            return;
                        }
                        if !b.ends_with(&[b'\n']) && tcp_write.write_all(b"\n").await.is_err() {
                            return;
                        }
                    }
                    Message::Close(_) => break,
                    Message::Ping(p) => {
                        let _ = ws_write.send(Message::Pong(p)).await;
                    }
                    Message::Pong(_) => {}
                    Message::Frame(_) => {}
                }
            }
        }
    }
}

#[tokio::main]
async fn main() -> io::Result<()> {
    let tcp_target = std::env::args()
        .nth(1)
        .unwrap_or_else(|| "127.0.0.1:4242".to_string());
    let ws_bind = std::env::args()
        .nth(2)
        .unwrap_or_else(|| "127.0.0.1:8765".to_string());

    let listener = TcpListener::bind(&ws_bind).await?;
    eprintln!("ws-tcp-bridge: WebSocket ws://{ws_bind} -> TCP {tcp_target}");

    while let Ok((stream, addr)) = listener.accept().await {
        let tcp_target = tcp_target.clone();
        tokio::spawn(async move {
            let ws = match accept_async(stream).await {
                Ok(w) => w,
                Err(e) => {
                    eprintln!("accept ws from {addr}: {e}");
                    return;
                }
            };
            let tcp = match TcpStream::connect(&tcp_target).await {
                Ok(t) => t,
                Err(e) => {
                    eprintln!("connect TCP {tcp_target}: {e}");
                    return;
                }
            };
            relay(ws, tcp).await;
        });
    }

    Ok(())
}
