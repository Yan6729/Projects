//
// EPITECH PROJECT, 2026
// log_server.rs
// File description:
// FFI vers libs/myteams (journalisation serveur)
//

use std::ffi::CString;
use std::os::raw::c_char;

#[link(name = "myteams")]
unsafe extern "C" {
    fn server_event_team_created(
        team_uuid: *const c_char,
        team_name: *const c_char,
        user_uuid: *const c_char,
    ) -> i32;
    fn server_event_channel_created(
        team_uuid: *const c_char,
        channel_uuid: *const c_char,
        channel_name: *const c_char,
    ) -> i32;
    fn server_event_thread_created(
        channel_uuid: *const c_char,
        thread_uuid: *const c_char,
        user_uuid: *const c_char,
        thread_title: *const c_char,
        thread_body: *const c_char,
    ) -> i32;
    fn server_event_reply_created(
        thread_uuid: *const c_char,
        user_uuid: *const c_char,
        reply_body: *const c_char,
    ) -> i32;
    fn server_event_user_subscribed(team_uuid: *const c_char, user_uuid: *const c_char) -> i32;
    fn server_event_user_unsubscribed(team_uuid: *const c_char, user_uuid: *const c_char) -> i32;
    fn server_event_user_created(user_uuid: *const c_char, user_name: *const c_char) -> i32;
    fn server_event_user_loaded(user_uuid: *const c_char, user_name: *const c_char) -> i32;
    fn server_event_user_logged_in(user_uuid: *const c_char) -> i32;
    fn server_event_user_logged_out(user_uuid: *const c_char) -> i32;
    fn server_event_private_message_sended(
        sender_uuid: *const c_char,
        receiver_uuid: *const c_char,
        message_body: *const c_char,
    ) -> i32;
}

fn c(s: &str) -> Option<CString> {
    CString::new(s).ok()
}

pub fn team_created(team_uuid: &str, team_name: &str, user_uuid: &str) {
    if let (Some(a), Some(b), Some(c)) = (c(team_uuid), c(team_name), c(user_uuid)) {
        unsafe {
            let _ = server_event_team_created(a.as_ptr(), b.as_ptr(), c.as_ptr());
        }
    }
}

pub fn channel_created(team_uuid: &str, channel_uuid: &str, channel_name: &str) {
    if let (Some(a), Some(b), Some(d)) = (c(team_uuid), c(channel_uuid), c(channel_name)) {
        unsafe {
            let _ = server_event_channel_created(a.as_ptr(), b.as_ptr(), d.as_ptr());
        }
    }
}

pub fn thread_created(
    channel_uuid: &str,
    thread_uuid: &str,
    user_uuid: &str,
    thread_title: &str,
    thread_body: &str,
) {
    if let (Some(a), Some(b), Some(u), Some(t), Some(body)) =
        (c(channel_uuid), c(thread_uuid), c(user_uuid), c(thread_title), c(thread_body))
    {
        unsafe {
            let _ = server_event_thread_created(a.as_ptr(), b.as_ptr(), u.as_ptr(), t.as_ptr(), body.as_ptr());
        }
    }
}

pub fn reply_created(thread_uuid: &str, user_uuid: &str, reply_body: &str) {
    if let (Some(a), Some(b), Some(d)) = (c(thread_uuid), c(user_uuid), c(reply_body)) {
        unsafe {
            let _ = server_event_reply_created(a.as_ptr(), b.as_ptr(), d.as_ptr());
        }
    }
}

pub fn user_subscribed(team_uuid: &str, user_uuid: &str) {
    if let (Some(a), Some(b)) = (c(team_uuid), c(user_uuid)) {
        unsafe {
            let _ = server_event_user_subscribed(a.as_ptr(), b.as_ptr());
        }
    }
}

pub fn user_unsubscribed(team_uuid: &str, user_uuid: &str) {
    if let (Some(a), Some(b)) = (c(team_uuid), c(user_uuid)) {
        unsafe {
            let _ = server_event_user_unsubscribed(a.as_ptr(), b.as_ptr());
        }
    }
}

pub fn user_created(user_uuid: &str, user_name: &str) {
    if let (Some(a), Some(b)) = (c(user_uuid), c(user_name)) {
        unsafe {
            let _ = server_event_user_created(a.as_ptr(), b.as_ptr());
        }
    }
}

pub fn user_loaded(user_uuid: &str, user_name: &str) {
    if let (Some(a), Some(b)) = (c(user_uuid), c(user_name)) {
        unsafe {
            let _ = server_event_user_loaded(a.as_ptr(), b.as_ptr());
        }
    }
}

pub fn user_logged_in(user_uuid: &str) {
    if let Some(a) = c(user_uuid) {
        unsafe {
            let _ = server_event_user_logged_in(a.as_ptr());
        }
    }
}

pub fn user_logged_out(user_uuid: &str) {
    if let Some(a) = c(user_uuid) {
        unsafe {
            let _ = server_event_user_logged_out(a.as_ptr());
        }
    }
}

pub fn private_message_sended(sender: &str, receiver: &str, body: &str) {
    if let (Some(a), Some(b), Some(d)) = (c(sender), c(receiver), c(body)) {
        unsafe {
            let _ = server_event_private_message_sended(a.as_ptr(), b.as_ptr(), d.as_ptr());
        }
    }
}
