//! Page de connexion : nom d’utilisateur + URL du pont WebSocket (optionnelle).

use crate::connection::{start_session, AppConn, DEFAULT_WS_URL};
use crate::Route;
use dioxus::prelude::*;


#[component]
pub fn LoginPage() -> Element {
    let nav = use_navigator();
    let mut conn = use_context::<AppConn>();
    let mut name = use_signal(|| String::new());
    let mut ws_url = use_signal(|| DEFAULT_WS_URL.to_string());
    let mut session_ready = use_signal(|| false);

    use_effect(move || {
        if session_ready() {
            session_ready.set(false);
            let _ = nav.push(Route::Teams {});
        }
    });

    rsx! {
        div {
                div {
                    class: "login-page",
                div {
                    class: "login-wrap",
                    h1 { "MyTeams (web)" }
                    p { class: "login-hint",
                        "Lance le serveur : ./myteams_server 4242 puis le pont : cargo run --manifest-path myTeams/ws-bridge/Cargo.toml"
                    }
                    label { "Nom (comme le CLI) :" }
                    input {
                        r#type: "text",
                        placeholder: "alice",
                        value: "{name}",
                        oninput: move |e| name.set(e.value()),
                    }
                    label { "WebSocket du pont :" }
                    input {
                        r#type: "text",
                        value: "{ws_url}",
                        oninput: move |e| ws_url.set(e.value()),
                    }
                    button {
                        class: "login-btn",
                        onclick: move |_| {
                            let n = name.read().trim().to_string();
                            if n.is_empty() {
                                conn.status.set("Entre un nom.".into());
                                return;
                            }
                            let u = ws_url.read().clone();
                            let c = conn;
                            start_session(u, n, c, session_ready);
                        },
                        "Se connecter"
                    }
                }
            }
        }
    }
}
