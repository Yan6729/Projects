#include "../../../include/graphics/Arcade_Libcaca.hpp"

uint16_t ArcadeLibcaca::SetColor(Arcade::Color color) {

    switch (color) {
        case Arcade::Color::WHITE:         return 0xFFFF;
        case Arcade::Color::RED:           return 0xFF00;
        case Arcade::Color::GREEN:         return 0xF0F0;
        case Arcade::Color::BLUE:          return 0xF00F;
        case Arcade::Color::YELLOW:        return 0xFFF0;
        case Arcade::Color::CYAN:          return 0xF0FF;
        case Arcade::Color::MAGENTA:       return 0xFF0F;
        case Arcade::Color::BLACK:         return 0xF000;
        case Arcade::Color::INDIGO:        return 0xF408;
        case Arcade::Color::ORANGE:        return 0xFFA0;
        case Arcade::Color::VIOLET:        return 0xFE8E;
        case Arcade::Color::PINK:          return 0xFFCC;
        case Arcade::Color::BROWN:         return 0xFA22;
        case Arcade::Color::GRAY:          return 0xF888;
        case Arcade::Color::LIGHT_BLUE:    return 0xFADE;
        case Arcade::Color::LIGHT_GREEN:   return 0xF9E9;
        case Arcade::Color::LIGHT_RED:     return 0xFFBC;
        case Arcade::Color::LIGHT_YELLOW:  return 0xFFFE;
        case Arcade::Color::LIGHT_CYAN:    return 0xEEFF;
        case Arcade::Color::LIGHT_MAGENTA: return 0xFFEF;
        case Arcade::Color::LIGHT_GRAY:    return 0xFD33;
        case Arcade::Color::DARK_BLUE:     return 0xF008;
        case Arcade::Color::DARK_GREEN:    return 0xF060;
        case Arcade::Color::DARK_RED:      return 0xF800;
        case Arcade::Color::DARK_YELLOW:   return 0xF880;
        case Arcade::Color::DARK_CYAN:     return 0xF088;
        case Arcade::Color::DARK_MAGENTA:  return 0xF808;
        case Arcade::Color::DARK_GRAY:     return 0xFAAA;
        default:                           return 0xFFFF;
    }
}

void ArcadeLibcaca::drawText(const Arcade::Text &text) {
    caca_set_color_argb(canvas, SetColor(text.color), 0xF000);
    caca_put_str(canvas, text.x / 8, text.y / 16, text.content.c_str());
}

void ArcadeLibcaca::drawEntity(const Arcade::Entity &entity, std::size_t Col_Grid, std::size_t Line_Grid) {
    float pixel_x = static_cast<float>(entity.x) * Window_Width / Col_Grid;
    float pixel_y = static_cast<float>(entity.y) * Window_Height / Line_Grid;
    float pixel_w = static_cast<float>(Window_Width) / Col_Grid;
    float pixel_h = static_cast<float>(Window_Height) / Line_Grid;

    int caca_x = static_cast<int>(pixel_x / 8);
    int caca_y = static_cast<int>(pixel_y / 16);
    int caca_w = static_cast<int>(pixel_w / 8);
    int caca_h = static_cast<int>(pixel_h / 16);


    if (caca_w < 1) caca_w = 1;
    if (caca_h < 1) caca_h = 1;

    uint16_t color = SetColor(entity.color);
    caca_set_color_argb(canvas, color, color);
    caca_fill_box(canvas, caca_x, caca_y, caca_w, caca_h, ' ');
    
    if (entity.symbol != '\0') {
        caca_set_color_argb(canvas, 0xFFFF, color);
        caca_put_char(canvas, caca_x, caca_y , entity.symbol);
    }
}
