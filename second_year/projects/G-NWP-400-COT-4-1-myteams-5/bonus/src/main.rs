//! Interface web MyTeams (Dioxus) reliée au serveur TCP via `ws-tcp-bridge`.

use dioxus::prelude::*;

mod auth;
mod connection;

use auth::LoginPage;
use connection::AppConn;
use futures::channel::mpsc::UnboundedSender;
use gloo_timers::future::TimeoutFuture;

const FAVICON: Asset = asset!("/assets/favicon.ico");
const MAIN_CSS: Asset = asset!("/assets/main.css");
const DOTS: Asset = asset!("/assets/dots_.png");
const TEAMS: Asset = asset!("/assets/people.png");
const NOTIFICATION: Asset = asset!("/assets/ringing.png");
const CHAT: Asset = asset!("/assets/chat.png");

fn main() {
    dioxus::launch(App);
}

#[component]
fn App() -> Element {
    let log = use_signal(Vec::new);
    let status = use_signal(|| "Hors ligne".to_string());
    let cmd = use_signal(|| None::<UnboundedSender<String>>);
    let shutdown = use_signal(|| None::<UnboundedSender<()>>);
    use_context_provider(|| AppConn {
        log,
        status,
        cmd,
        shutdown,
    });

    rsx! {
        document::Link { rel: "icon", href: FAVICON }
        document::Link { rel: "stylesheet", href: MAIN_CSS }
        Router::<Route> {}
    }
}

#[derive(Routable, Clone, PartialEq)]
#[rustfmt::skip]
pub enum Route {
    #[route("/")]
    Login {},
    #[layout(MainLayout)]
        #[route("/teams")]
        Teams {},
        #[route("/chat")]
        Chat {},
        #[route("/notifications")]
        Notification {},
}

#[component]
fn Login() -> Element {
    rsx! {
        document::Link { rel: "stylesheet", href: asset!("/assets/auth.css") }
        LoginPage {}
    }
}

#[component]
fn Notification() -> Element {
    let conn = use_context::<AppConn>();
    if conn.cmd.peek().is_none() {
        return session_required_gate();
    }
    rsx! {
        div { class: "panel",
            h2 { "Notifications (flux serveur)" }
            ServerLog {}
        }
    }
}

#[component]
fn Teams() -> Element {
    let conn = use_context::<AppConn>();
    if conn.cmd.peek().is_none() {
        return session_required_gate();
    }
    rsx! {
        div { class: "panel",
            h2 { "Équipes" }
            p { class: "panel-hint", "Raccourcis (protocole myteams) :" }
            div { class: "quick-cmds",
                button { onclick: move |_| conn.send_cmd("/list"), "/list (toutes les équipes)" }
                button { onclick: move |_| conn.send_cmd("/subscribed"), "/subscribed" }
            }
            ServerLog {}
            CommandInput {}
        }
    }
}

#[component]
fn Chat() -> Element {
    let conn = use_context::<AppConn>();
    if conn.cmd.peek().is_none() {
        return session_required_gate();
    }
    rsx! {
        div { class: "panel",
            h2 { "Chat / commandes" }
            p { class: "panel-hint",
                "Exemples : /users , /send \"UUID\" \"message\" , /messages \"UUID\""
            }
            ServerLog {}
            CommandInput {}
        }
    }
}

fn session_required_gate() -> Element {
    rsx! {
        div { class: "panel",
            p { class: "panel-hint",
                Link { to: Route::Login {}, "← Connexion" }
                " — aucune session WebSocket (connecte-toi depuis l’accueil)."
            }
        }
    }
}

#[component]
fn ServerLog() -> Element {
    let conn = use_context::<AppConn>();
    rsx! {
        pre { class: "server-log",
            {conn.log.read().join("\n")}
        }
    }
}

#[component]
fn CommandInput() -> Element {
    let conn = use_context::<AppConn>();
    let mut line = use_signal(|| String::new());
    rsx! {
        div { class: "cmd-row",
            input {
                r#type: "text",
                class: "cmd-input",
                placeholder: "/create \"...\" \"...\" (guillemets doubles)",
                value: "{line}",
                oninput: move |e| line.set(e.value()),
            }
            button {
                onclick: move |_| {
                    conn.send_cmd(&line.read());
                    line.set(String::new());
                },
                "Envoyer"
            }
        }
    }
}

#[component]
pub fn SlideBar() -> Element {
    rsx! {
        div { class: "choose-part",
            Link { class: "sidebar-link", to: Route::Notification {},
                button { class: "sidebar-icon-btn",
                    img { src: NOTIFICATION, alt: "Notifications" }
                }
            }
            Link { class: "sidebar-link", to: Route::Chat {},
                button { class: "sidebar-icon-btn",
                    img { src: CHAT, alt: "Chat" }
                }
            }
            Link { class: "sidebar-link", to: Route::Teams {},
                button { class: "sidebar-icon-btn",
                    img { src: TEAMS, alt: "Équipes" }
                }
            }
        }
    }
}

#[component]
pub fn MainLayout() -> Element {
    let conn = use_context::<AppConn>();
    let nav = use_navigator();
    rsx! {
        div { class: "container-box",
            div { class: "head-part",
                p { class: "conn-status", "{conn.status}" }
                input { placeholder: "🔍️ Recherche (UI seule)", r#type: "text" }
                button {
                    class: "logout-btn",
                    onclick: move |_| {
                        conn.send_cmd("/logout");
                        conn.disconnect();
                        spawn(async move {
                            TimeoutFuture::new(0).await;
                            let _ = nav.replace(Route::Login {});
                        });
                    },
                    "Déconnexion"
                }
                button { class: "head-menu-btn",
                    img { src: DOTS, id: "menu_info", alt: "" }
                }
            }
            div { class: "main-container",
                SlideBar {}
                Outlet::<Route> {}
            }
        }
    }
}
