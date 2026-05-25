//
// EPITECH PROJECT, 2026
// snd_year_pool
// File description:
// flight_log
//

#[derive(Debug, PartialEq)]
pub enum FlightStatus {
    OnTime,
    Delayed(u32), // Delay in minutes
    Cancelled(String), // Reason for cancellation
}
#[derive(Debug)]
pub struct Flight {
    pub id: String,
    pub destination: String,
    pub time: u32, // Time in 24h format (e.g., 1430 for 14:30)
    pub status : FlightStatus,
}

pub fn parse_flight(line: &str) -> Result<Flight, String>
{
    let field : Vec<&str> = line.split(',').collect();

    match field.len() {
        4 => {
            let id = field[0].to_string();
            let destination = field[1].to_string();
            let time = field[2].parse::<u32>()
                .map_err(|_| "Invalid time".to_string())?;
            let status = match field[3] {
                "ONTIME" => FlightStatus::OnTime,
                f if f.contains("DELAYED") => {
                    let contain : Vec<&str> = field[3].trim().split(' ').collect();
                    if contain.len() <= 1 || contain.len() != 2 {
                        return Err("Bad delay".to_string());
                    } else {
                        let value = contain[1].trim().parse::<u32>().map_err(|_| "Bad delay".to_string())?;
                        FlightStatus::Delayed(value)
                    }
                },
                f if f.contains("CANCELLED") => {
                    let contain_ : Vec<&str> = field[3].trim().split(' ').collect();
                    if contain_.len() == 2 {
                        FlightStatus::Cancelled(contain_[1].trim().to_string())
                    } else {
                        FlightStatus::Cancelled("".to_string())
                    }
                }
                _ => return Err("Unknown status".to_string())
            };
            Ok(Flight {id, destination, time, status})
        }
        _ => Err("false".to_string()),
    }
}

pub fn build_schedule(raw_logs: Vec<&str>) -> Vec<Flight>
{
    let mut vector: Vec<Flight> = Vec::new();

    for i in raw_logs {
        vector.push(match parse_flight(i) {
            Err(_) => continue,
            Ok(flight) => flight,
        })
    }
    sjvector.sort_by_key(|flight| flight.time);
    return vector;
}
