#ifndef ARCADE_SFML_HPP_
#define ARCADE_SFML_HPP_

#include "IGraphics.hpp"
#include <SDL2/SDL.h>

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <queue>


class ArcadeSdl : public Arcade::IGraphics {
    public:
        ArcadeSdl();
        ~ArcadeSdl() override;
        void init() override;
        void close() override;
        const std::string &getName() const override;
        void clear() override;
        SDL_Color SetColor(Arcade::Color color);
        Arcade::Input getInput() override;
        void display() override;
        void drawText(const Arcade::Text &text) override;
        void drawEntity(const Arcade::Entity &entity, std::size_t Col_Grid, std::size_t Col_Line) override;
        char pollChar() override;

    private:
        std::string name;
        std::size_t Window_Width = 800;
        std::size_t Window_Height = 600;
        SDL_Window* window;
        SDL_Renderer* renderer;
        std::map<std::string, SDL_Texture *> _textures;
        std::map<std::string, TTF_Font*> _fonts;
        std::queue<char> _charQueue;
};


#endif