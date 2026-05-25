#include "../../../include/graphics/Arcade_ncurses.hpp"


Arcade::Input Arcade_ncurses::getInput() {
    int ch = wgetch(stdscr);

    switch (ch) {
        case KEY_F(10):
            return Arcade::EXIT;
        case KEY_UP:
            return Arcade::UP;
        case KEY_DOWN:
            return Arcade::DOWN;
        case KEY_LEFT:
            return Arcade::LEFT;
        case KEY_RIGHT:
            return Arcade::RIGHT;
        case ' ':
            return Arcade::ACTION;
        case 27: // ESC
            return Arcade::MENU;
        case KEY_F(5):
            return Arcade::RESTART;
        case KEY_F(1):
            return Arcade::NEXT_LIB;
        case KEY_F(2):
            return Arcade::NEXT_GAME;
        case KEY_F(3):
            return Arcade::PAUSE;
        case KEY_F(4):
            return Arcade::GAME_MENU;
        case KEY_BACKSPACE:
        case 127:
        case 8:
            return Arcade::BACKSPACE;
        case ERR:
            return Arcade::NONE;

            
        default:
            if (ch >= 32 && ch <= 126) {
                _charQueue.push(static_cast<char>(ch));
            }
            break;
    }
    return Arcade::NONE;
}

char Arcade_ncurses::pollChar() {
    if (_charQueue.empty()) {
        return '\0';
    }
    
    char c = _charQueue.front();
    _charQueue.pop();
    return c;
}