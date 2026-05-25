//
// EPITECH PROJECT, 2026
// snd_year_pool
// File description:
// global_inventory
//

use std::collections::HashMap;

pub struct Stock {
    pub quantity: u32,
    pub total_value: u32,
}

pub fn consolidate_inventory(orders: &[(&str, u32, u32)]) -> HashMap<String, Stock>
{
    let mut map : HashMap<String, Stock> = HashMap::new();

    for tuple in orders {
        match map.get_mut(tuple.0) {
            Some(stock) => {
                stock.quantity += tuple.1;
                stock.total_value += tuple.1 * tuple.2;
            },
            None => {
                match tuple.1 {
                    0 => continue,
                    _ => {
                        map.insert(tuple.0.to_string(),
                        Stock {
                            quantity: tuple.1,
                            total_value: tuple.1 * tuple.2,
                        });
                    }
                    }
            },
        }
    }
    return map;
}
