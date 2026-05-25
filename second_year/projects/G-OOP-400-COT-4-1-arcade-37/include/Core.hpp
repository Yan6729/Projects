/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "graphics/IGraphics.hpp"
#include "games/IGame.hpp"
#include "LibManager.hpp"
#include "ScoreManager.hpp"

#include <string>

namespace Arcade {

enum class AppState { MENU, PLAYING, GAME_OVER, EXIT };

class Core {
public:
    explicit Core(const std::string &initialGraphicLib);
    ~Core();

    void run();

private:
    void loadGraphics(const std::string &path);
    void loadGame    (const std::string &path);

    void handleMenuInput (Input input);
    void handleGameInput (Input input);

    void renderMenu();
    void renderGame();
    void renderGameOver();

    void switchNextLib();
    void switchNextGame();
    void restartGame();
    void goToMenu();

    // draw text using window-relative coordinates (0.0 to 1.0)
    void menuText(const std::string &content,
                  float rx, float ry, Color color);

    AppState    _state      {AppState::MENU};
    int         _menuSel    {0};
    int         _libSel     {0};
    bool        _focusOnLibs{false};
    bool        _typingName {true};
    std::string _playerName;

    LibManager   _libs;
    ScoreManager _scores;

    LibPtr<IGraphics> _graphics;
    LibPtr<IGame>     _game;

    std::string _currentGraphicLib;
    std::string _currentGameLib;
};

} // namespace Arcade

#endif