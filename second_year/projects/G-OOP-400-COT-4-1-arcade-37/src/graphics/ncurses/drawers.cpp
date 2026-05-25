#include "../../../include/graphics/Arcade_ncurses.hpp"

void Arcade_ncurses::SetColor() {
    init_color(10, 1000, 1000, 1000);
    init_pair(static_cast<int>(Arcade::Color::WHITE), 10, COLOR_BLACK);
    init_color(11, 1000, 0, 0);
    init_pair(static_cast<int>(Arcade::Color::RED), 11, COLOR_BLACK);
    init_color(12, 0, 1000, 0);
    init_pair(static_cast<int>(Arcade::Color::GREEN), 12, COLOR_BLACK);
    init_color(13, 0, 0, 1000);
    init_pair(static_cast<int>(Arcade::Color::BLUE), 13, COLOR_BLACK);
    init_color(14, 1000, 1000, 0);
    init_pair(static_cast<int>(Arcade::Color::YELLOW), 14, COLOR_BLACK);
    init_color(15, 0, 1000, 1000);
    init_pair(static_cast<int>(Arcade::Color::CYAN), 15, COLOR_BLACK);
    init_color(16, 1000, 0, 1000);
    init_pair(static_cast<int>(Arcade::Color::MAGENTA), 16, COLOR_BLACK);
    init_color(17, 0, 0, 0);
    init_pair(static_cast<int>(Arcade::Color::BLACK), 17, COLOR_BLACK);
    init_color(18, 294, 0, 509);
    init_pair(static_cast<int>(Arcade::Color::INDIGO), 18, COLOR_BLACK);
    init_color(19, 1000, 500, 0);
    init_pair(static_cast<int>(Arcade::Color::ORANGE), 19, COLOR_BLACK);
    init_color(20, 509, 0, 823);
    init_pair(static_cast<int>(Arcade::Color::VIOLET), 20, COLOR_BLACK);
    init_color(21, 1000, 411, 705);
    init_pair(static_cast<int>(Arcade::Color::PINK), 21, COLOR_BLACK);
    init_color(22, 509, 250, 0);
    init_pair(static_cast<int>(Arcade::Color::BROWN), 22, COLOR_BLACK);
    init_color(23, 500, 500, 500);
    init_pair(static_cast<int>(Arcade::Color::GRAY), 23, COLOR_BLACK);
    init_color(24, 333, 666, 1000); 
    init_pair(static_cast<int>(Arcade::Color::LIGHT_BLUE), 24, COLOR_BLACK);
    init_color(25, 333, 1000, 333);
    init_pair(static_cast<int>(Arcade::Color::LIGHT_GREEN), 25, COLOR_BLACK);
    init_color(26, 1000, 333, 333);
    init_pair(static_cast<int>(Arcade::Color::LIGHT_RED), 26, COLOR_BLACK);
    init_color(27, 1000, 1000, 333);
    init_pair(static_cast<int>(Arcade::Color::LIGHT_YELLOW), 27, COLOR_BLACK);
    init_color(28, 333, 1000, 1000);
    init_pair(static_cast<int>(Arcade::Color::LIGHT_CYAN), 28, COLOR_BLACK);
    init_color(29, 1000, 333, 1000);
    init_pair(static_cast<int>(Arcade::Color::LIGHT_MAGENTA), 29, COLOR_BLACK);
    init_color(30, 750, 750, 750);
    init_pair(static_cast<int>(Arcade::Color::LIGHT_GRAY), 30, COLOR_BLACK);
    init_color(31, 0, 0, 509);
    init_pair(static_cast<int>(Arcade::Color::DARK_BLUE), 31, COLOR_BLACK);
    init_color(32, 0, 509, 0);
    init_pair(static_cast<int>(Arcade::Color::DARK_GREEN), 32, COLOR_BLACK);
    init_color(33, 509, 0, 0);
    init_pair(static_cast<int>(Arcade::Color::DARK_RED), 33, COLOR_BLACK);
    init_color(34, 509, 509, 0);
    init_pair(static_cast<int>(Arcade::Color::DARK_YELLOW), 34, COLOR_BLACK);
    init_color(35, 0, 509, 509);
    init_pair(static_cast<int>(Arcade::Color::DARK_CYAN), 35, COLOR_BLACK);
    init_color(36, 509, 0, 509);
    init_pair(static_cast<int>(Arcade::Color::DARK_MAGENTA), 36, COLOR_BLACK);
    init_color(37, 250, 250, 250);
    init_pair(static_cast<int>(Arcade::Color::DARK_GRAY), 37, COLOR_BLACK);
}

void Arcade_ncurses::drawText(const Arcade::Text &text) {    
    int ncurses_x = (text.x * COLS) / 800;
    int ncurses_y = (text.y * LINES) / 600;
    attron(COLOR_PAIR(static_cast<int>(text.color) + 1));
    mvprintw(ncurses_y, ncurses_x, "%s", text.content.c_str());
    attroff(COLOR_PAIR(static_cast<int>(text.color) + 1));
}


void Arcade_ncurses::drawEntity(const Arcade::Entity &entity, std::size_t Col_Grid, std::size_t Line_Grid) {
    if (Col_Grid == 0 || Line_Grid == 0) return;
    int pos_x = (entity.x * COLS) / Col_Grid;
    int pos_y = (entity.y * LINES) / Line_Grid;
    
    attron(COLOR_PAIR(static_cast<int>(entity.color) + 1));
    mvaddch(pos_y, pos_x, entity.symbol);
    attroff(COLOR_PAIR(static_cast<int>(entity.color) + 1));
}