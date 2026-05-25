//
// EPITECH PROJECT, 2026
// server.rs
// File description:
// myteams server entry point
//

mod log_server;
mod protocol;
mod runtime;
mod state;
mod types;

use std::env;

fn usage() {
    println!("USAGE: ./myteams_server port");
    println!("port is the port number on which the server socket listens");
}

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() == 2 && (args[1] == "-help" || args[1] == "--help") {
        usage();
        return;
    }
    if args.len() != 2 {
        usage();
        std::process::exit(84);
    }
    let port: u16 = match args[1].parse::<u16>() {
        Ok(p) if p != 0 => p,
        _ => {
            usage();
            std::process::exit(84);
        }
    };
    runtime::run_server(port);
}
