#include "../../../include/graphics/Arcade_sfml.hpp"

Arcade::Input ArcadeSfml::getInput() {
    sf::Event event;
    if (this->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            return Arcade::EXIT;
        }
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Up:
                    return Arcade::UP;
                case sf::Keyboard::Down:
                    return Arcade::DOWN;
                case sf::Keyboard::Left:
                    return Arcade::LEFT;
                case sf::Keyboard::Right:
                    return Arcade::RIGHT;
                case sf::Keyboard::Space:
                    return Arcade::ACTION;
                case sf::Keyboard::Escape:
                    return Arcade::MENU;
                case sf::Keyboard::F5:
                    return Arcade::RESTART;
                case sf::Keyboard::F1:
                    return Arcade::NEXT_LIB;
                case sf::Keyboard::F10:
                    return Arcade::EXIT;
                case sf::Keyboard::F2:
                    return Arcade::NEXT_GAME;
                case sf::Keyboard::F3:
                    return Arcade::PAUSE;
                case sf::Keyboard::F4:
                    return Arcade::GAME_MENU;
                case sf::Keyboard::BackSpace:
                    return Arcade::BACKSPACE;

                default:
                    break;
            }
        }
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode < 128 && event.text.unicode >= 32 && _charQueue.size() < 10)
                _charQueue.push(static_cast<char>(event.text.unicode));
        }
    }
    return Arcade::NONE;
}

char ArcadeSfml::pollChar() {
    if (_charQueue.empty())
        return '\0';
    char c = _charQueue.front();
    _charQueue.pop();
    return c;
}