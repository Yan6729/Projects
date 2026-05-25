//
// EPITECH PROJECT, 2026
// snd_year_pool
// File description:
// food_court
//

pub struct Recipe {
    pub name: String,
    pub ingredients: Vec<String>,
}

pub fn get_ingredient_quantity(ingredient: &str) -> Result<usize, String>
{
    match ingredient {
        "Space Bacon" => Ok(42),
        "Dehydrated Eggs" => Ok(120),
        "Soy Milk" => Ok(5),
        "Antimatter" => panic!("BOOM! The kitchen exploded!"),
        "Recycled Water" => Err("Machine broken".to_string()),
        _ => Err("Food not found".to_string()),
    }
}

pub fn resolve_recipe(name: &str) -> Result<Recipe, String>
{
    match name {
        "Space Omelette" => Ok(Recipe {
            name: "Space Omelette".to_string(),
            ingredients: vec!(
                "Space Bacon".to_string(),
                "Dehydrated Eggs".to_string()
            )
        }),
        "Corpse Reviver" => Ok(Recipe {
            name: "Corpse Reviver".to_string(),
            ingredients: vec!(
                "Soy Milk".to_string(),
                "Recycled Water".to_string()
            )
        }),
        "Quantum Brownie" => Ok(Recipe {
            name: "Quantum Brownie".to_string(),
            ingredients: vec!(
                "Space Bacon".to_string(),
                "Antimatter".to_string()
            )
        }),
        _=> Err("Meal not on menu".to_string()),
    }
}

pub fn check_availability(recipe: &Recipe) -> Result<String, String>
{
    for i in recipe.ingredients.iter() {
        get_ingredient_quantity(&i)?;
    }
    return Ok("All ingredients available".to_string());

}

pub fn cook_meal(order: &str) -> Result<String, String>
{
    let resoleved_recipe : Recipe = resolve_recipe(order)?;
    check_availability(&resoleved_recipe)?;
    return Ok(format!("The {} is ready!", order));
}
