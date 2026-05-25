//
// EPITECH PROJECT, 2026
// snd_year_pool
// File description:
// ownership
//

pub struct Chest {
    pub helmet: u32,
    pub suit: u32,
}

fn take_helmet(equipment_chest: &mut Chest, to_take: u32)
{
    equipment_chest.helmet -= to_take;
}

fn take_suit(equipment_chest: &mut Chest, to_take: u32)
{
    equipment_chest.suit -= to_take;
}

fn add_title(name: &str) -> &str
{
    return name;
}

fn sign_contract(name: &str) -> String
{
    let contrat = format!("I am honored to join the space program of The Union and I am willing to risk my life to explore space. Therefore, I renounce every right I have to sue The Union in the event of my death.
Signed: Astronaut {}", &name);
    return contrat;
}

fn sign_press_declaration(astronaut: &str) -> String
{
    let press_declaration = format!("I am thrilled that I have been chosen in the space program of The Union. I will make The Union and my family proud by being a good astronaut, dedicated to the exploration of space. Cheers and see you on Venus !
Signed: Astronaut {}", &astronaut);
    return press_declaration;
}
