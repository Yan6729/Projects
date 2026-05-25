//
// EPITECH PROJECT, 2026
// snd_year_pool
// File description:
// ship_characteristics
//

pub struct RocketBooster {
    height: f32,
    diameter: f32,
    last_check_time: u32,
}
pub struct FuelTank {
    height: f32,
    quantity: f32,
    max_quantity: f32,
    last_check_time: u32,
}
pub struct CrewCabin {
    nb_seats: u8,
    diameter: f32,
    last_check_time: u32,
}
pub struct SciencePayload {
    quantity: f32,
    max_quantity: f32,
    science_percentage: f32,
}
pub trait RocketComponent {
    fn new() -> Self;
    fn info(&self) -> String;
}
pub trait SafetyCheck {
    fn check_component(&mut self, current_time: u32) -> bool;
    fn is_safe(&self, current_time: u32) -> bool;
}
pub trait LoadContent {
    fn load(&mut self, to_load: f32);
    fn is_full(&self) -> bool;
}

impl RocketComponent for RocketBooster {
    fn new() -> RocketBooster {
        let new_rb : RocketBooster = RocketBooster {height: 32.3, diameter: 3.0, last_check_time: 0};

        println!("Rocket Booster created with a height of {} meters.", new_rb.height);
        return new_rb;
    }

    fn info(&self) -> String {
        return format!("This Rocket Booster is {0} meters tall and {1} meters wide. It was last checked on day {2} of its life."
       , self.height, self.diameter, self.last_check_time);
    }
}


impl RocketComponent for FuelTank {
    fn new() -> FuelTank {
        let new_ft : FuelTank = FuelTank {height: 30.0, quantity: 0.0, max_quantity: 220.0, last_check_time: 0};

        println!("Fuel Tank created with a max quantity of {} tons.", new_ft.max_quantity);
        return new_ft;
    }

    fn info(&self) -> String {
        return format!("This Fuel Tank is {0} meters tall and can contain up to {1} tons of propergol, currently {2} tons inside. It was last checked on day {3} of its life."
       , self.height, self.max_quantity, self.quantity, self.last_check_time);
    }
}

impl RocketComponent for CrewCabin {
    fn new() -> CrewCabin {
        let new_cc : CrewCabin = CrewCabin {nb_seats: 4, diameter: 2.5,last_check_time: 0};

        println!("Cabin of {} person created.", new_cc.nb_seats);
        return new_cc;
    }

    fn info(&self) -> String {
        return format!("This cabin has {0} seats arranged in a circle {1:.02} meters large. It was last checked on day {2} of its life.",
        self.nb_seats, self.diameter, self.last_check_time);
    }
}

impl RocketComponent for SciencePayload {
    fn new() -> SciencePayload {
        let new_sp : SciencePayload = SciencePayload {quantity: 0.0, max_quantity: 1142.0, science_percentage: 0.0};

        println!("Science Payload created with a max quantity of {} kilos.", new_sp.max_quantity);
        return new_sp;
    }

    fn info(&self) -> String {
        return format!("This Science Payload can carry {0:.02} kilos of science material. Currently it contains {1:.02} kilos which means it has a science percentage of {2:.02}%."
       , self.max_quantity, self.quantity, self.science_percentage);
    }
}

impl SafetyCheck for RocketBooster {
    fn check_component(&mut self, current_time: u32) -> bool {
        if current_time < self.last_check_time {
            return false;
        } else {
            self.last_check_time = current_time;
            return true;
        }
    }

    fn is_safe(&self, current_time: u32) -> bool {
        if current_time < self.last_check_time || self.last_check_time == 0 {
            return false;
        }
        return current_time - self.last_check_time <= 12;
    }
}

impl SafetyCheck for FuelTank {
    fn check_component(&mut self, current_time: u32) -> bool {
        if current_time < self.last_check_time {
            return false;
        } else {
            self.last_check_time = current_time;
            return true;
        }
    }

    fn is_safe(&self, current_time: u32) -> bool {
        if current_time < self.last_check_time || self.last_check_time == 0 {
            return false;
        }
        return current_time - self.last_check_time <= 6;
    }
}

impl SafetyCheck for CrewCabin {
    fn check_component(&mut self, current_time: u32) -> bool {
        if current_time < self.last_check_time {
            return false;
        } else {
            self.last_check_time = current_time;
            return true;
        }
    }

    fn is_safe(&self, current_time: u32) -> bool {
        if current_time < self.last_check_time || self.last_check_time == 0 {
            return false;
        }
        return current_time - self.last_check_time <= 16;
    }
}

pub const DISCOVERIES : [& str; 4] = [
   "The Union discovered that the hottest planet in our solar system is Venus (about 450°C).",
   "The Union discovered that Mercury and Venus are the only planets in our solar system with no moons.",
   "The Union discovered that one day on Venus is longer than a year on Earth.",
   "The Union discovered that on Venus it snow metal and rains sulfuric acid."
];

impl LoadContent for FuelTank {
    fn load(&mut self, to_load: f32) {
        self.quantity = (self.quantity + to_load).min(self.max_quantity);
    }

    fn is_full(&self) -> bool {
        return self.quantity >= self.max_quantity;
    }
}

impl LoadContent for SciencePayload {
    fn load(&mut self, to_load: f32) {
        self.quantity = (self.quantity + to_load).min(self.max_quantity);
    }

    fn is_full(&self) -> bool {
        return self.quantity >= self.max_quantity;
    }
}

impl SciencePayload {
    pub fn science(&mut self) -> f32 {
        self.science_percentage = (self.quantity / self.max_quantity) * 100.0 * 2.0;

        let percentage = self.science_percentage;
        if percentage < 50.0 {
            println!("{}", DISCOVERIES[0]);
        } else if percentage < 100.0 {
            println!("{}", DISCOVERIES[1]);
        } else if percentage < 150.0 {
            println!("{}", DISCOVERIES[2]);
        } else {
            println!("{}", DISCOVERIES[3]);
        }
        return self.science_percentage
    }
}
