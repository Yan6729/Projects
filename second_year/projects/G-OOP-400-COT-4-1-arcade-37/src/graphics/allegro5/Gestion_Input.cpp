#include "../../../include/graphics/Arcade_Allegro5.hpp"

Arcade::Input ArcadeAllegro5::getInput() {
    ALLEGRO_EVENT event;
    if (al_get_next_event(this->event_queue, &event)) {
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            return Arcade::EXIT;
        }
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    return Arcade::UP;
                case ALLEGRO_KEY_DOWN:
                    return Arcade::DOWN;
                case ALLEGRO_KEY_LEFT:
                    return Arcade::LEFT;
                case ALLEGRO_KEY_RIGHT:
                    return Arcade::RIGHT;
                case ALLEGRO_KEY_SPACE:
                    return Arcade::ACTION;
                case ALLEGRO_KEY_ESCAPE:
                    return Arcade::MENU;
                case ALLEGRO_KEY_F5:
                    return Arcade::RESTART;
                case ALLEGRO_KEY_F1:
                    return Arcade::NEXT_LIB;
                case ALLEGRO_KEY_F10:
                    return Arcade::EXIT;
                case ALLEGRO_KEY_F2:
                    return Arcade::NEXT_GAME;
                case ALLEGRO_KEY_F3:
                    return Arcade::PAUSE;
                case ALLEGRO_KEY_F4:
                    return Arcade::GAME_MENU;
                case ALLEGRO_KEY_BACKSPACE:
                    return Arcade::BACKSPACE;

                default:
                    break;
            }
        }
        if (event.type == ALLEGRO_EVENT_KEY_CHAR) {
             if (event.keyboard.unichar < 128 && event.keyboard.unichar >= 32)
                _charQueue.push(static_cast<char>(event.keyboard.unichar));
        }
    }
    return Arcade::NONE;
}

char ArcadeAllegro5::pollChar() {
    if (_charQueue.empty())
        return '\0';
    char c = _charQueue.front();
    _charQueue.pop();
    return c;
}

