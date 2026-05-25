//
// EPITECH PROJECT, 2026
// log_client.rs
// File description:
// FFI vers libs/myteams (affichage client)
//

use std::ffi::CString;
use std::os::raw::c_char;

pub type TimeT = i64;

#[link(name = "myteams")]
unsafe extern "C" {
    fn client_event_logged_in(user_uuid: *const c_char, user_name: *const c_char) -> i32;
    fn client_event_logged_out(user_uuid: *const c_char, user_name: *const c_char) -> i32;
    fn client_event_private_message_received(user_uuid: *const c_char, message_body: *const c_char) -> i32;
    fn client_event_thread_reply_received(
        team_uuid: *const c_char,
        thread_uuid: *const c_char,
        user_uuid: *const c_char,
        reply_body: *const c_char,
    ) -> i32;
    fn client_event_team_created(
        team_uuid: *const c_char,
        team_name: *const c_char,
        team_description: *const c_char,
    ) -> i32;
    fn client_event_channel_created(
        channel_uuid: *const c_char,
        channel_name: *const c_char,
        channel_description: *const c_char,
    ) -> i32;
    fn client_event_thread_created(
        thread_uuid: *const c_char,
        user_uuid: *const c_char,
        thread_timestamp: TimeT,
        thread_title: *const c_char,
        thread_body: *const c_char,
    ) -> i32;
    fn client_print_users(user_uuid: *const c_char, user_name: *const c_char, user_status: i32) -> i32;
    fn client_print_teams(
        team_uuid: *const c_char,
        team_name: *const c_char,
        team_description: *const c_char,
    ) -> i32;
    fn client_team_print_channels(
        channel_uuid: *const c_char,
        channel_name: *const c_char,
        channel_description: *const c_char,
    ) -> i32;
    fn client_channel_print_threads(
        thread_uuid: *const c_char,
        user_uuid: *const c_char,
        thread_timestamp: TimeT,
        thread_title: *const c_char,
        thread_body: *const c_char,
    ) -> i32;
    fn client_thread_print_replies(
        thread_uuid: *const c_char,
        user_uuid: *const c_char,
        reply_timestamp: TimeT,
        reply_body: *const c_char,
    ) -> i32;
    fn client_private_message_print_messages(
        sender_uuid: *const c_char,
        message_timestamp: TimeT,
        message_body: *const c_char,
    ) -> i32;
    fn client_error_unknown_team(team_uuid: *const c_char) -> i32;
    fn client_error_unknown_channel(channel_uuid: *const c_char) -> i32;
    fn client_error_unknown_thread(thread_uuid: *const c_char) -> i32;
    fn client_error_unknown_user(user_uuid: *const c_char) -> i32;
    fn client_error_unauthorized() -> i32;
    fn client_error_already_exist() -> i32;
    fn client_print_user(user_uuid: *const c_char, user_name: *const c_char, user_status: i32) -> i32;
    fn client_print_team(team_uuid: *const c_char, team_name: *const c_char, team_description: *const c_char) -> i32;
    fn client_print_channel(
        channel_uuid: *const c_char,
        channel_name: *const c_char,
        channel_description: *const c_char,
    ) -> i32;
    fn client_print_thread(
        thread_uuid: *const c_char,
        user_uuid: *const c_char,
        thread_timestamp: TimeT,
        thread_title: *const c_char,
        thread_body: *const c_char,
    ) -> i32;
    fn client_print_team_created(
        team_uuid: *const c_char,
        team_name: *const c_char,
        team_description: *const c_char,
    ) -> i32;
    fn client_print_channel_created(
        channel_uuid: *const c_char,
        channel_name: *const c_char,
        channel_description: *const c_char,
    ) -> i32;
    fn client_print_thread_created(
        thread_uuid: *const c_char,
        user_uuid: *const c_char,
        thread_timestamp: TimeT,
        thread_title: *const c_char,
        thread_body: *const c_char,
    ) -> i32;
    fn client_print_reply_created(
        thread_uuid: *const c_char,
        user_uuid: *const c_char,
        reply_timestamp: TimeT,
        reply_body: *const c_char,
    ) -> i32;
    fn client_print_subscribed(user_uuid: *const c_char, team_uuid: *const c_char) -> i32;
    fn client_print_unsubscribed(user_uuid: *const c_char, team_uuid: *const c_char) -> i32;
}

fn cs(s: &str) -> Option<CString> {
    CString::new(s).ok()
}

pub fn event_logged_in(uuid: &str, name: &str) {
    if let (Some(a), Some(b)) = (cs(uuid), cs(name)) {
        unsafe {
            let _ = client_event_logged_in(a.as_ptr(), b.as_ptr());
        }
    }
}

pub fn event_logged_out(uuid: &str, name: &str) {
    if let (Some(a), Some(b)) = (cs(uuid), cs(name)) {
        unsafe {
            let _ = client_event_logged_out(a.as_ptr(), b.as_ptr());
        }
    }
}

pub fn event_private_message_received(from: &str, body: &str) {
    if let (Some(a), Some(b)) = (cs(from), cs(body)) {
        unsafe {
            let _ = client_event_private_message_received(a.as_ptr(), b.as_ptr());
        }
    }
}

pub fn event_thread_reply_received(team: &str, thread: &str, user: &str, body: &str) {
    if let (Some(a), Some(b), Some(c), Some(d)) = (cs(team), cs(thread), cs(user), cs(body)) {
        unsafe {
            let _ = client_event_thread_reply_received(a.as_ptr(), b.as_ptr(), c.as_ptr(), d.as_ptr());
        }
    }
}

pub fn event_team_created(uuid: &str, name: &str, desc: &str) {
    if let (Some(a), Some(b), Some(c)) = (cs(uuid), cs(name), cs(desc)) {
        unsafe {
            let _ = client_event_team_created(a.as_ptr(), b.as_ptr(), c.as_ptr());
        }
    }
}

pub fn event_channel_created(uuid: &str, name: &str, desc: &str) {
    if let (Some(a), Some(b), Some(c)) = (cs(uuid), cs(name), cs(desc)) {
        unsafe {
            let _ = client_event_channel_created(a.as_ptr(), b.as_ptr(), c.as_ptr());
        }
    }
}

pub fn event_thread_created(thread: &str, user: &str, ts: TimeT, title: &str, body: &str) {
    if let (Some(a), Some(b), Some(t), Some(u)) = (cs(thread), cs(user), cs(title), cs(body)) {
        unsafe {
            let _ = client_event_thread_created(a.as_ptr(), b.as_ptr(), ts, t.as_ptr(), u.as_ptr());
        }
    }
}

pub fn print_users(uuid: &str, name: &str, status: i32) {
    if let (Some(a), Some(b)) = (cs(uuid), cs(name)) {
        unsafe {
            let _ = client_print_users(a.as_ptr(), b.as_ptr(), status);
        }
    }
}

pub fn print_teams(uuid: &str, name: &str, desc: &str) {
    if let (Some(a), Some(b), Some(c)) = (cs(uuid), cs(name), cs(desc)) {
        unsafe {
            let _ = client_print_teams(a.as_ptr(), b.as_ptr(), c.as_ptr());
        }
    }
}

pub fn print_channels(uuid: &str, name: &str, desc: &str) {
    if let (Some(a), Some(b), Some(c)) = (cs(uuid), cs(name), cs(desc)) {
        unsafe {
            let _ = client_team_print_channels(a.as_ptr(), b.as_ptr(), c.as_ptr());
        }
    }
}

pub fn print_threads(thread: &str, user: &str, ts: TimeT, title: &str, body: &str) {
    if let (Some(a), Some(b), Some(t), Some(u)) = (cs(thread), cs(user), cs(title), cs(body)) {
        unsafe {
            let _ = client_channel_print_threads(a.as_ptr(), b.as_ptr(), ts, t.as_ptr(), u.as_ptr());
        }
    }
}

pub fn print_replies(thread: &str, user: &str, ts: TimeT, body: &str) {
    if let (Some(a), Some(b), Some(c)) = (cs(thread), cs(user), cs(body)) {
        unsafe {
            let _ = client_thread_print_replies(a.as_ptr(), b.as_ptr(), ts, c.as_ptr());
        }
    }
}

pub fn print_dm_messages(sender: &str, ts: TimeT, body: &str) {
    if let (Some(a), Some(b)) = (cs(sender), cs(body)) {
        unsafe {
            let _ = client_private_message_print_messages(a.as_ptr(), ts, b.as_ptr());
        }
    }
}

pub fn error_unknown_team(id: &str) {
    if let Some(a) = cs(id) {
        unsafe {
            let _ = client_error_unknown_team(a.as_ptr());
        }
    }
}

pub fn error_unknown_channel(id: &str) {
    if let Some(a) = cs(id) {
        unsafe {
            let _ = client_error_unknown_channel(a.as_ptr());
        }
    }
}

pub fn error_unknown_thread(id: &str) {
    if let Some(a) = cs(id) {
        unsafe {
            let _ = client_error_unknown_thread(a.as_ptr());
        }
    }
}

pub fn error_unknown_user(id: &str) {
    if let Some(a) = cs(id) {
        unsafe {
            let _ = client_error_unknown_user(a.as_ptr());
        }
    }
}

pub fn error_unauthorized() {
    unsafe {
        let _ = client_error_unauthorized();
    }
}

pub fn error_already_exist() {
    unsafe {
        let _ = client_error_already_exist();
    }
}

pub fn print_user(uuid: &str, name: &str, status: i32) {
    if let (Some(a), Some(b)) = (cs(uuid), cs(name)) {
        unsafe {
            let _ = client_print_user(a.as_ptr(), b.as_ptr(), status);
        }
    }
}

pub fn print_team(uuid: &str, name: &str, desc: &str) {
    if let (Some(a), Some(b), Some(c)) = (cs(uuid), cs(name), cs(desc)) {
        unsafe {
            let _ = client_print_team(a.as_ptr(), b.as_ptr(), c.as_ptr());
        }
    }
}

pub fn print_channel(uuid: &str, name: &str, desc: &str) {
    if let (Some(a), Some(b), Some(c)) = (cs(uuid), cs(name), cs(desc)) {
        unsafe {
            let _ = client_print_channel(a.as_ptr(), b.as_ptr(), c.as_ptr());
        }
    }
}

pub fn print_thread(thread: &str, user: &str, ts: TimeT, title: &str, body: &str) {
    if let (Some(a), Some(b), Some(t), Some(u)) = (cs(thread), cs(user), cs(title), cs(body)) {
        unsafe {
            let _ = client_print_thread(a.as_ptr(), b.as_ptr(), ts, t.as_ptr(), u.as_ptr());
        }
    }
}

pub fn print_team_created(uuid: &str, name: &str, desc: &str) {
    if let (Some(a), Some(b), Some(c)) = (cs(uuid), cs(name), cs(desc)) {
        unsafe {
            let _ = client_print_team_created(a.as_ptr(), b.as_ptr(), c.as_ptr());
        }
    }
}

pub fn print_channel_created(uuid: &str, name: &str, desc: &str) {
    if let (Some(a), Some(b), Some(c)) = (cs(uuid), cs(name), cs(desc)) {
        unsafe {
            let _ = client_print_channel_created(a.as_ptr(), b.as_ptr(), c.as_ptr());
        }
    }
}

pub fn print_thread_created(thread: &str, user: &str, ts: TimeT, title: &str, body: &str) {
    if let (Some(a), Some(b), Some(t), Some(u)) = (cs(thread), cs(user), cs(title), cs(body)) {
        unsafe {
            let _ = client_print_thread_created(a.as_ptr(), b.as_ptr(), ts, t.as_ptr(), u.as_ptr());
        }
    }
}

pub fn print_reply_created(thread: &str, user: &str, ts: TimeT, body: &str) {
    if let (Some(a), Some(b), Some(c)) = (cs(thread), cs(user), cs(body)) {
        unsafe {
            let _ = client_print_reply_created(a.as_ptr(), b.as_ptr(), ts, c.as_ptr());
        }
    }
}

pub fn print_subscribed(user: &str, team: &str) {
    if let (Some(a), Some(b)) = (cs(user), cs(team)) {
        unsafe {
            let _ = client_print_subscribed(a.as_ptr(), b.as_ptr());
        }
    }
}

pub fn print_unsubscribed(user: &str, team: &str) {
    if let (Some(a), Some(b)) = (cs(user), cs(team)) {
        unsafe {
            let _ = client_print_unsubscribed(a.as_ptr(), b.as_ptr());
        }
    }
}
