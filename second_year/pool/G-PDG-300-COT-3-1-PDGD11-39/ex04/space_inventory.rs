//
// EPITECH PROJECT, 2026
// snd_year_pool
// File description:
// space_inventory
//

pub enum ItemType {
    Tool,
    Weapon(u32),
}

pub struct Item {
    pub name: String,
    pub item_type: ItemType,
    pub price: f32,
    pub usage: u8,
}
fn get_damage(item: &Item) -> u32
{
    match item.item_type {
        ItemType::Weapon(value) => value,
        ItemType::Tool => 0,
    }
}

fn use_item(item: &mut Item, usage: u8)
{
    if item.usage == 0 {
        return;
    }
    if usage > item.usage {
        item.usage = 0;
    } else {
        item.usage -= usage;
    }
    if item.usage < 25 {
        item.price -= (item.price * 75.0) / 100.0;
    }
}

fn is_used(item: &Item) -> bool
{
    return item.usage < 25;
}

fn harmonize_price(first: &mut Item, second: &mut Item)
{
    if first.price == second.price {
        return;
    }
    if first.price < second.price {
        first.price = second.price;
    } else {
        second.price = first.price;
    }
}
