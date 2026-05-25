#ifndef ARCADE_LIBCACA_HPP
#define ARCADE_LIBCACA_HPP

#include "IGraphics.hpp"
#include <caca.h>
#include <queue>


class ArcadeLibcaca : public Arcade::IGraphics {

    public:
        ArcadeLibcaca();
        ~ArcadeLibcaca() override;
        void init() override;
        void close() override;
        const std::string &getName() const override;
        void clear() override;
        Arcade::Input getInput() override;
        void display() override;
        void drawText(const Arcade::Text &text) override;
        void drawEntity(const Arcade::Entity &entity, std::size_t Col_Grid, std::size_t Col_Line) override;
        char pollChar() override;
        uint16_t SetColor(Arcade::Color color);

    private:
        std::string name;
        caca_canvas_t *canvas;
        caca_display_t *display_ptr;
        std::size_t Window_Width = 800;
        std::size_t Window_Height = 600;
        std::queue<char> _charQueue;
        bool _isInitialized = false;
};


#endif