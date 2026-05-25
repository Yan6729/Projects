//
// EPITECH PROJECT, 2026
// types.rs
// File description:
// server shared types
//

use std::collections::VecDeque;
use std::net::TcpStream;

pub struct ClientState {
    pub stream: TcpStream,
    pub in_buf: Vec<u8>,
    pub out_buf: VecDeque<u8>,
    pub user_id: Option<String>,
}
