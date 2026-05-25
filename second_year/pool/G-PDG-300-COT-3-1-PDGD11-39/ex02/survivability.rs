//
// EPITECH PROJECT, 2026
// snd_year_pool
// File description:
// survivability
//

pub fn compute_survivable_days(water_quantity: f32, water_cycles: u32, food_quantity: f32, nb_crew: u32)-> u32 {
    let water_supply : f32 = 2.0 * (nb_crew as f32);
    let food_supply : f32 = 500.0 * (nb_crew as f32);
    let water_days = ((water_quantity / water_supply) as u32) * water_cycles;
    let food_days = ((food_quantity * 1000.0) / food_supply) as u32;

    println!("If the mission can embark {0}L of water, {1}kg of food and the water recycler can do {2} water cycles... With {3} crew members, there is enough water for {4} day(s) and enough food for {5} day(s).", (water_quantity as u32), food_quantity, water_cycles, nb_crew, water_days, food_days);
    return if water_days < food_days { water_cycles } else { food_days };
}
