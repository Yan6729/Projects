//
// EPITECH PROJECT, 2026
// snd_year_pool
// File description:
// null_paradox
//

pub struct Coordinates {
    pub x: i32,
    pub y: i32,
    pub z: i32,
}

pub fn get_place(name: &str) -> Option<Coordinates>
{
    match name {
        "Earth" => Some(Coordinates {x: 0, y:0, z: 0}),
        "Mars" => Some(Coordinates {x: 15, y: 22, z: 110}),
        "Jupiter" => Some(Coordinates {x: 88, y: 12, z: -4}),
        _ => None,
    }
}

pub fn analyze_transport_method(option: Option<Coordinates>) -> String
{
    match option {
        Some(coord) => format!("Teleporting to {0},{1},{2}", coord.x, coord.y, coord.z),
        None => "No destination available".to_string(),
    }
}

pub fn risky_teleport(option: Option<Coordinates>) -> String
{
    let coord : Coordinates = option.unwrap();

    return format!("Teleporting to {0},{1},{2}", coord.x, coord.y, coord.z);
}
