//
// EPITECH PROJECT, 2026
// snd_year_pool
// File description:
// float_recognition
//

pub fn is_number(number: &str)-> bool
{
    let num = number.trim();
    let minus_number = num.chars().filter(|&c| c == '-').count();
    let dot_number = num.chars().filter(|&c| c == '.').count();

    
    if (num.contains("-") && num.chars().nth(0) != Some('-')) || dot_number >= 2 || minus_number >= 2 {
        return false;
    }
    if num.contains('.') {
        let index = num.find('.').unwrap();
        let chars_before_dot = num.chars().nth(index - 1).unwrap();
        if !chars_before_dot.is_ascii_digit() {
            return false;
        }
    }
    return num.parse::<f32>().is_ok();
}

#[cfg(test)]

mod tests {
    use super::*;

    #[test]
    fn true_result() {
        assert!(is_number("24.2"));
        assert!(is_number("45.5"));
        assert!(is_number("89.45"));
        assert!(is_number("100.0"));
        assert!(is_number("25.0"));
    }

    #[test]
    fn invalid_number() {
        assert!(!is_number("12a.5"));
        assert!(!is_number("n54.25"));
        assert!(!is_number("25 .5"));
        assert!(!is_number("hgfd"));
        assert!(!is_number("645651m"));
    }

    #[test]
    fn too_many_dot() {
        assert!(!is_number("12..5"));
        assert!(!is_number("12..9..5"));
        assert!(!is_number(".25..5"));
        assert!(!is_number("1.2.3.4.5"));
        assert!(!is_number("1.5."));
    }

    #[test]
    fn too_many_dash() {
        assert!(!is_number("--125.0"));
        assert!(!is_number("-25.8-"));
        assert!(!is_number("-25.-25"));
        assert!(!is_number("-.8"));
        assert!(!is_number("259.-5"));
    }

    #[test]
    fn dash_and_dot() {
        assert!(!is_number("0..-5"));
        assert!(!is_number("-558..9."));
        assert!(!is_number("-98.0-2"));
        assert!(!is_number("--03.5"));
        assert!(!is_number("-.258.."));
    }
}
