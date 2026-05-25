#include "../../../include/graphics/Arcade_ncurses.hpp"

Arcade_ncurses::Arcade_ncurses() : name("NCurses"), _isInitialized(false) {}

Arcade_ncurses::~Arcade_ncurses()
{
    if (_isInitialized)
    {
        endwin();
    }
}

void Arcade_ncurses::init()
{
    std::cout << "Init ncurses" << std::endl;
    if (!_isInitialized)
    {
        initscr();
        cbreak();
        noecho();
        curs_set(0);
        keypad(stdscr, TRUE);
        nodelay(stdscr, TRUE);

        start_color();
        SetColor();

        wrefresh(stdscr);
        _isInitialized = true;
    }
}

void Arcade_ncurses::close()
{
    if (_isInitialized)
    {
        endwin();
        _isInitialized = false;
    }
}

void Arcade_ncurses::clear()
{
    if (_isInitialized)
    {
        werase(stdscr);
    }
}

void Arcade_ncurses::display()
{
    if (_isInitialized)
    {
        wrefresh(stdscr);
    }
}

const std::string &Arcade_ncurses::getName() const
{
    return name;
}

extern "C"
{
    Arcade::IGraphics *createGraphics(void)
    {
        return new Arcade_ncurses();
    }

    void destroyGraphics(Arcade::IGraphics *graphics)
    {
        delete graphics;
    }
}