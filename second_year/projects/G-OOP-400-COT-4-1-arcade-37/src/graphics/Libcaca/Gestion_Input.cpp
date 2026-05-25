#include "../../../include/graphics/Arcade_Libcaca.hpp"

Arcade::Input ArcadeLibcaca::getInput() {
    caca_event_t event;
    if (caca_get_event(display_ptr, CACA_EVENT_KEY_PRESS, &event, 0) > 0) {
        unsigned int key = caca_get_event_key_ch(&event);
        switch (key) {
            case CACA_KEY_F10:
                return Arcade::EXIT;
            case CACA_KEY_UP:
                return Arcade::UP;
            case CACA_KEY_DOWN:
                return Arcade::DOWN;
            case CACA_KEY_LEFT:
                return Arcade::LEFT;
            case CACA_KEY_RIGHT:
                return Arcade::RIGHT;
            case ' ':
                return Arcade::ACTION;
            case 27: // ESC
                return Arcade::MENU;
            case CACA_KEY_F5:
                return Arcade::RESTART;
            case CACA_KEY_F1:
                return Arcade::NEXT_LIB;
            case CACA_KEY_F2:
                return Arcade::NEXT_GAME;
            case CACA_KEY_F3:
                return Arcade::PAUSE;
            case CACA_KEY_F4:
                return Arcade::GAME_MENU;
            case CACA_KEY_BACKSPACE:
                return Arcade::BACKSPACE;

            default:
                if (key < 128 && key >= 32)
                    _charQueue.push(static_cast<char>(key));
                break;
        }
    }
    return Arcade::Input::NONE;
}

char ArcadeLibcaca::pollChar() {
    if (_charQueue.empty())
        return '\0';
    char c = _charQueue.front();
    _charQueue.pop();
    return c;
}


