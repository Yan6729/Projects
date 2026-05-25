//
// EPITECH PROJECT, 2026
// snd_year_pool
// File description:
// mission_report
//

#[derive(Debug, Clone, PartialEq)]
pub struct Rover {
    pub name: String,
    pub fuel_level: u8,
    pub map_sectors: Vec<u32>,
}

#[derive(Debug)]
pub enum MissionState {
    Planned,
    InProgress,
    Completed,
    Failed,
}

#[derive(Debug)]
pub struct Mission {
    pub mission_name: String,
    pub rover: Rover,
    pub state: MissionState,
}

use std::fmt;

impl fmt::Display for MissionState {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let s = match self {
            MissionState::Planned => "PLANNED",
            MissionState::InProgress => "IN PROGRESS",
            MissionState::Completed => "COMPLETED",
            MissionState::Failed => "FAILED",
        };
        write!(f, "{}", s)
    }
}

impl fmt::Display for Rover {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(
            f,
            "{} (Fuel: {}%)\nMap Coverage: {} sectors",
            self.name,
            self.fuel_level,
            self.map_sectors.len()
        )
    }
}

impl fmt::Display for Mission {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(
            f,
            "[{}] {}\nAssigned Rover: {}",
            self.state,
            self.mission_name,
            self.rover
        )
    }
}

impl PartialEq for Mission {
    fn eq(&self, other: &Self) -> bool {
        self.mission_name == other.mission_name
    }
}
impl Ord for MissionState {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        self.priority().cmp(&other.priority())
    }
}

impl PartialOrd for MissionState {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

impl PartialEq for MissionState {
    fn eq(&self, other: &Self) -> bool {
        self.priority() == other.priority()
    }
}

impl Eq for MissionState {}

impl MissionState {
    fn priority(&self) -> u8 {
        match self {
            MissionState::Failed => 4,
            MissionState::InProgress => 3,
            MissionState::Planned => 2,
            MissionState::Completed => 1,
        }
    }
}
