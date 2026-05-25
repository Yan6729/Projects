/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** IGraphics
*/

#ifndef IGRAPHICS_HPP_
    #define IGRAPHICS_HPP_
    #include <iostream>
    #include <string>
    #include <vector>
    #include <stdexcept>
    #include <random>
    #include <chrono>
    #include <thread>
    #include <algorithm>
    #include <stack>
    #include <queue>
    using namespace std;

namespace Arcade {
    enum Input {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ACTION,
        MENU,
        RESTART,
        NEXT_LIB,
        NEXT_GAME,
        BACKSPACE,
        PAUSE,
        EXIT,
        GAME_MENU,
        NONE
    };

    enum class Color {
        WHITE,
        RED,
        GREEN,
        BLUE,
        YELLOW,
        CYAN,
        MAGENTA,
        BLACK,
        INDIGO,
        ORANGE,
        VIOLET,
        PINK,
        BROWN,
        GRAY,
        LIGHT_BLUE,
        LIGHT_GREEN,
        LIGHT_RED,
        LIGHT_YELLOW,
        LIGHT_CYAN,
        LIGHT_MAGENTA,
        LIGHT_GRAY,
        DARK_BLUE,
        DARK_GREEN,
        DARK_RED,
        DARK_YELLOW,
        DARK_CYAN,
        DARK_MAGENTA,
        DARK_GRAY
    };

    struct Entity {
        int x;
        int y;
        char symbol; 
        Color color;
        std::string sprite;
    };
    
    struct Text {
        std::string content;
        std::string font;
        int x;
        int y;
        Color color;
    };

    class IGraphics {
        public:
            virtual ~IGraphics() = default;
            virtual void init() = 0;
            virtual void close() = 0;
            virtual const std::string &getName() const = 0;
            virtual void clear() = 0;
            virtual Input getInput() = 0;
            virtual void display() = 0;
            virtual void drawText(const Arcade::Text &text) = 0;
            virtual void drawEntity(const Arcade::Entity &entity, std::size_t Col_Grid, std::size_t Line_Grid) = 0;
            virtual char pollChar() = 0;
    };
}

#endif // IGRAPHICS_HPP
