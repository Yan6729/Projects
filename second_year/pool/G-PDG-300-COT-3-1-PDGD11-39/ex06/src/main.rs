use std::env;
use std::process;

fn operation(element: (String, u32), temp: &mut u32, energy: &mut u32)
{
    match element.0.to_lowercase().as_str() {
        "uranium" => {
            *energy += 40 * element.1;
            *temp += 10 * element.1;
        }
        "plutonium" => {
            *energy += 90 * element.1;
            *temp += 60 * element.1;
        }
        "oldboot" => {
            *energy += 20 * element.1;
            *temp += 5 * element.1;
        }
        "unknown" => {
            if *temp % 2 == 0 {
                *energy += 400 * element.1;
            } else {
                *energy -= 140 * element.1;
            }
        }
        _ => {}
    }
    println!("Reactor Stats: Energy {0}, Temp {1}", energy, temp);
    if *temp > 800 {
        println!("CRITICAL MELTDOWN!");
        process::exit(-1);
    } else if *temp <= 800 && *energy >= 2000 {
        println!("Orbit achieved!");
        process::exit(1);
    } else if *energy < 2000 {
        println!("Out of fuel. We drift into the void...");
    }

}

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() <= 1 || args.len() <= 4 || (args.len() - 3) % 2 != 0 {
        return;
    }
    let mut energy: u32 = args[1].parse::<u32>().unwrap_or(84);
    let mut temp: u32 = args[2].parse::<u32>().unwrap_or(84);
    let vec = vec!["uranium".to_string(), "plutonium".to_string(), "oldboot".to_string(), "unknown".to_string()];
    let mut stock: String;

    for i in (3..(args.len()-1)).step_by(2) {
        stock = args[i].to_lowercase();
        if vec.contains(&stock) {
            println!("Processing: {0} ({1}kg)", &args[i], args[i+1]);
            operation((args[i].clone(), args[i+1].parse::<u32>().unwrap_or(84)), &mut temp, &mut energy);
        } else {
            println!("Error: Unknown element");
            return;
        }
    }
}
