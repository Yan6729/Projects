#ifndef ARCADE_NCURSES_HPP_
#define ARCADE_NCURSES_HPP_

#include "IGraphics.hpp"
#include <ncurses.h>
#include <queue>
#undef clear
#undef refresh
#undef getch

class Arcade_ncurses : public Arcade::IGraphics {
    public:
        Arcade_ncurses();
        ~Arcade_ncurses() override;
        void init() override;
        void close() override;
        const std::string &getName() const override;
        void clear() override;
        Arcade::Input getInput() override;
        void display() override;
        void drawText(const Arcade::Text &text) override;
        void drawEntity(const Arcade::Entity &entity, std::size_t Col_Grid, std::size_t Col_Line) override;
        char pollChar() override;
        void SetColor();
    
    private:
        std::string name;
        int _lastKey = -1;
        std::queue<char> _charQueue;
        bool _isInitialized = false;
};

#endif