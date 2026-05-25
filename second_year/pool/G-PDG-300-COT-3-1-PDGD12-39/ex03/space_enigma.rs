//
// EPITECH PROJECT, 2026
// snd_year_pool
// File description:
// space_enigma
//

pub enum Message {
    ClearString(String),
    DigitalCode(u32),
    Encrypted(String, u32),
}

pub enum SecurityClass {
    Civilian,
    Diplomatic,
    Military,
}

pub struct Transmission {
    pub message: Message,
    pub security: SecurityClass,
    pub signal_strength: u8,
}

pub fn solve_enigma(transmission: Transmission, daily_key: u32) -> Result<String, String>
{
    let result : String;
    let mut score : i32 = 0;

    match daily_key {
        0_u32 => return Err("Sign
        al lost".to_string()),
        1_u32..=19_u32 => return Err("Signal too weak".to_string()),
        20_u32..=u32::MAX => {
            match (transmission.security, daily_key) {
                (SecurityClass::Military, d) if daily_key != 4242 => return Err("Security Breach: Invalid Key".to_string()),
                _ => {
                    match transmission.message {
                        Message::ClearString(s) => {
                            if s == "Bomb" { return Err("Panic: Bomb detected".to_string()) } else { result = s}
                        },
                        Message::DigitalCode(value) => {
                            if value == 404 {
                                result = "Not Found".to_string()
                            } else if value == 200 {
                                result = "OK".to_string()
                            } else { result = format!("Code: {}", value) }},
                        Message::Encrypted(msg, key_id) => {
                            if key_id == daily_key {
                                result = msg
                            } else { return Err("Encryption Error: Wrong Key".to_string()) }},
                    }
                }, 
            }
        },
    }

    for i in result.chars() {
        if i.is_ascii_alphabetic() {
            score += 1;
        } else if i.is_ascii_digit() {
            score -= 1;
        }
    }
    return if score < 0 { Err("Artificial Noise".to_string()) } else { Ok(result) };
}
