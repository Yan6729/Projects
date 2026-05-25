#include "../../../include/graphics/Arcade_Allegro5.hpp"

ALLEGRO_COLOR ArcadeAllegro5::SetColor(Arcade::Color color) {
    switch (color) {
        case Arcade::Color::WHITE:
            return al_map_rgb(255, 255, 255);
        case Arcade::Color::RED:
            return al_map_rgb(255, 0, 0);
        case Arcade::Color::GREEN:
            return al_map_rgb(0, 255, 0);
        case Arcade::Color::BLUE:
            return al_map_rgb(0, 0, 255);
        case Arcade::Color::YELLOW:
            return al_map_rgb(255, 255, 0);
        case Arcade::Color::CYAN:
            return al_map_rgb(0, 255, 255);
        case Arcade::Color::MAGENTA:
            return al_map_rgb(255, 0, 255);
        case Arcade::Color::BLACK:
            return al_map_rgb(0, 0, 0);
        case Arcade::Color::INDIGO:
            return al_map_rgb(75, 0, 130);
        case Arcade::Color::ORANGE:
            return al_map_rgb(255, 165, 0);
        case Arcade::Color::VIOLET:
            return al_map_rgb(238, 130, 238);
        case Arcade::Color::PINK:
            return al_map_rgb(255, 192, 203);
        case Arcade::Color::BROWN:
            return al_map_rgb(165, 42, 42);
        case Arcade::Color::GRAY:
            return al_map_rgb(128, 128, 128);
        case Arcade::Color::LIGHT_BLUE:
            return al_map_rgb(173, 216, 230);
        case Arcade::Color::LIGHT_GREEN:
            return al_map_rgb(144, 238, 144);
        case Arcade::Color::LIGHT_RED:
            return al_map_rgb(255, 182, 193);
        case Arcade::Color::LIGHT_YELLOW:
            return al_map_rgb(255, 255, 224);
        case Arcade::Color::LIGHT_CYAN: 
            return al_map_rgb(224, 255, 255);
        case Arcade::Color::LIGHT_MAGENTA:
            return al_map_rgb(255, 224, 255);
        case Arcade::Color::LIGHT_GRAY:
            return al_map_rgb(211, 211, 211);
        case Arcade::Color::DARK_BLUE:
            return al_map_rgb(0, 0, 139);
        case Arcade::Color::DARK_GREEN:
            return al_map_rgb(0, 100, 0);
        case Arcade::Color::DARK_RED:
            return al_map_rgb(139, 0, 0);
        case Arcade::Color::DARK_YELLOW:
            return al_map_rgb(139, 139, 0);
        case Arcade::Color::DARK_CYAN:
            return al_map_rgb(0, 139, 139);
        case Arcade::Color::DARK_MAGENTA:
            return al_map_rgb(139, 0, 139);
        case Arcade::Color::DARK_GRAY:
            return al_map_rgb(169, 169, 169);
        default:
            return al_map_rgb(255, 255, 255);
    }
}

void ArcadeAllegro5::drawText(const Arcade::Text &text) {
    ALLEGRO_COLOR color = SetColor(text.color);
    font = al_load_ttf_font(text.font.c_str(), 24, 0);
    if (!font) {
        std::cerr << "Failed to load font: " << text.font << std::endl;
        return;
    }

    al_draw_text(font, color, text.x, text.y, ALLEGRO_ALIGN_LEFT, text.content.c_str());
    al_destroy_font(font);
}

void ArcadeAllegro5::drawEntity(const Arcade::Entity &entity, std::size_t Col_Grid, std::size_t Line_Grid) {
    int pos_x = entity.x * (Window_Width / Col_Grid);
    int pos_y = entity.y * (Window_Height / Line_Grid);
    ALLEGRO_COLOR color = SetColor(entity.color);

    if (!entity.sprite.empty()) {
        ALLEGRO_BITMAP* bitmap;
        if (_textures.find(entity.sprite) != _textures.end()) {
            bitmap = _textures[entity.sprite];
        } else {
            bitmap = al_load_bitmap(entity.sprite.c_str());
            if (!bitmap) {
                std::cerr << "Failed to load sprite: " << entity.sprite << std::endl;
                return;
            }
            _textures[entity.sprite] = bitmap;
        }
        al_draw_scaled_bitmap(bitmap, 
            0, 0, al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), 
            pos_x, pos_y, Window_Width / Col_Grid, Window_Height / Line_Grid, 
            0);
    } else {
        al_draw_filled_rectangle(pos_x, pos_y, pos_x + (Window_Width / Col_Grid), pos_y + (Window_Height / Line_Grid), color);
    }
}