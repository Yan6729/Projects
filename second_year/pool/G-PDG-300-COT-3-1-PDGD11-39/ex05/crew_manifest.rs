//
// EPITECH PROJECT, 2026
// snd_year_pool
// File description:
// crew_manifest
//

pub fn create_crew(size: i32) -> Vec<String>
{
    if size <= 0 {
        return Vec::new();
    }
    let vec_: Vec<String> = Vec::with_capacity(size as usize);
    return vec_;
}

pub fn join_crew(crew: &mut Vec<String>, name: String)
{
    crew.push(name);
}

pub fn leave_crew(crew: &mut Vec<String>, name: &str)
{
    let mut index = 0;
    let mut is_in : bool = false;

    for number in crew.iter_mut() {
        index += 1;
        if name.to_string() == *number {
            is_in = true;
            break;
        }
    }
    if is_in == true{
        crew.remove(index-1);
    }
}

pub fn survey_crew(crew: &Vec<String>) -> usize
{
    return crew.len();
}
