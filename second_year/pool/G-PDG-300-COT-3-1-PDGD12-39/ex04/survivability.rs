//
// EPITECH PROJECT, 2026
// snd_year_pool
// File description:
// survivability
//

pub struct ShipAssessment {
    pub water_quantity: f32,
    pub water_cycles: u32,
    pub food_quantity: f32,
}

pub struct StudyResult {
    pub rock_name: String,
    pub reachable: bool,
    pub ship_index: usize,
}

pub fn compute_survivable_days(needs: &ShipAssessment, nb_crew: u32)-> u32
{
    let water_supply: f32 = 3.0 * (nb_crew as f32);
    let food_supply: f32 = 500.0 * (nb_crew as f32);
    let water_days = ((needs.water_quantity / water_supply) * (needs.water_cycles as f32)) as u32;
    let food_days = ((needs.food_quantity * 1000.0) / food_supply) as u32;

    return if water_days < food_days { water_days } else { food_days };
}

pub fn study_ships(ships: &[ShipAssessment], rocks_to_visit: &[(String, u32)], rock: String, nb_crew: u32)-> StudyResult
{
    let mut rock_name = "Error".to_string();
    let mut days_needed = 0;
    let mut reachable =  false;
    let mut index: usize = 0;

    for rock_to_visit in rocks_to_visit {
        if rock_to_visit.0 == rock {
            rock_name = rock.to_string();
            days_needed  = rock_to_visit.1;
        }
    }

    match rock_name {
        r if r == "Error".to_string() => return StudyResult {rock_name: "Error".to_string(), reachable: false, ship_index: 0},
        _ => {
            for i in ships {
                index += 1;
                if compute_survivable_days(i, nb_crew) > days_needed {
                    reachable = true;
                    break;
                }
            }
            return StudyResult {rock_name: rock_name,
                reachable: reachable,
                ship_index: if reachable {index-1} else {0}
            };
        }
    }
}
