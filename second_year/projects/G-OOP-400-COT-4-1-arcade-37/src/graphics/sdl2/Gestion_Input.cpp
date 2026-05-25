#include "../../../include/graphics/Arcade_sdl.hpp"

Arcade::Input ArcadeSdl::getInput() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return Arcade::EXIT;
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    return Arcade::UP;
                case SDLK_DOWN:
                    return Arcade::DOWN;
                case SDLK_LEFT:
                    return Arcade::LEFT;
                case SDLK_RIGHT:
                    return Arcade::RIGHT;
                case SDLK_SPACE:
                    return Arcade::ACTION;
                case SDLK_ESCAPE:
                    return Arcade::MENU;
                case SDLK_F5:
                    return Arcade::RESTART;
                case SDLK_F1:
                    return Arcade::NEXT_LIB;
                case SDLK_F10:
                    return Arcade::EXIT;
                case SDLK_F2:
                    return Arcade::NEXT_GAME;
                case SDLK_F3:
                    return Arcade::PAUSE;
                case SDLK_F4:
                    return Arcade::GAME_MENU;
                case SDLK_BACKSPACE:
                    return Arcade::BACKSPACE;

                default:
                    if (event.key.keysym.sym >= 32 && event.key.keysym.sym <= 126)
                        _charQueue.push(static_cast<char>(event.key.keysym.sym));
                    break;
            }
        }
    }
    return Arcade::NONE;
}

char ArcadeSdl::pollChar() {
    if (_charQueue.empty())
        return '\0';
    char c = _charQueue.front();
    _charQueue.pop();
    return c;
}