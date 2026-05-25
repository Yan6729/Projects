#ifndef ARCADE_ALLEGRO5_HPP_
#define ARCADE_ALLEGRO5_HPP_

#include "IGraphics.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <map>
#include <queue>


class ArcadeAllegro5 : public Arcade::IGraphics {
    public:
        ArcadeAllegro5();
        ~ArcadeAllegro5();

        void init() override;
        void close() override;
        const std::string &getName() const override;
        void clear() override;
        void display() override;
        void drawText(const Arcade::Text &text) override;
        void drawEntity(const Arcade::Entity &entity, std::size_t Col_Grid, std::size_t Line_Grid) override;
        Arcade::Input getInput() override;
        char pollChar() override;
        ALLEGRO_COLOR SetColor(Arcade::Color color);

    private:
        std::string name;
        ALLEGRO_DISPLAY *show = nullptr;
        ALLEGRO_FONT *font = nullptr;
        ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
        std::map<std::string, ALLEGRO_BITMAP*> _textures; 
        std::size_t Window_Width = 800;
        std::size_t Window_Height = 600;
        std::queue<char> _charQueue;
};
#endif