//
// EPITECH PROJECT, 2026
// snd_year_pool
// File description:
// flying_sequence
//

pub fn flying_sequence(mut countdown: u32, ignition: u32, secondary_activation: u32, thrust_duration: u32) {
    if (countdown < ignition) || (secondary_activation < 30) {
        println!("Wrong flying sequence, go back to the lab !");
        return;
    }

    let mut a = 1;
    println!("Liftoff in {0}...", countdown);
    while countdown > 0 {
        countdown -= 1;
        if countdown == ignition {
            println!("Main engine ignition");
        }
        if countdown == 0 {
            println!("Liftoff ! We have liftoff !");
            while a < (secondary_activation + thrust_duration) {
                if a == secondary_activation {
                    println!("T+{0} : Secondary engines ignition", a);
                }
                if a % 10 == 0 {
                    println!("T+{0} : Everything is fine", a);
                }
                if a == (secondary_activation - 10) {
                    println!("T+{0} : Main engine cutoff", a);
                    println!("T+{0} : Main engine decoupling", a+1);
                }
                a += 1;
            }
        } else {
            println!("Liftoff in {0}...", countdown);
        }
    }
    println!("T+{0} : Secondary engines cutoff. We're in orbit !", a);
}
