#include "../../include/Core.hpp"

#include <chrono>
#include <stdexcept>
#include <thread>

namespace Arcade {

namespace {
    constexpr int FRAME_MS = 1000 / 60;
    constexpr float VIRT_W = 800.0f;
    constexpr float VIRT_H = 600.0f;
    const std::string FONT = "asset/Fonts/Roboto-Regular.ttf";
}

Core::Core(const std::string &initialGraphicLib)
{
    if (!_libs.isGraphicLib(initialGraphicLib))
        throw std::runtime_error("'" + initialGraphicLib + "' not a graphical library");
    _libs.scanLibs("./lib");
    loadGraphics(initialGraphicLib);
}

Core::~Core()
{
    if (_game)
        _game->close();
    if (_graphics)
        _graphics->close();
}

void Core::run()
{
    using Clock = std::chrono::steady_clock;
    using Ms    = std::chrono::milliseconds;

    while (_state != AppState::EXIT) {
        auto frameStart = Clock::now();
        Input input = _graphics->getInput();
        char c = _graphics->pollChar();

        if (_state == AppState::MENU && _typingName) {
            if (input == NEXT_LIB) {
                _typingName = false;
                continue;
            } else if (input == BACKSPACE && !_playerName.empty()) {
                _playerName.pop_back();
            } else if (c >= 32 && c <= 126 && _playerName.size() < 10) {
                _playerName += c;
            }
            renderMenu();
            _graphics->display();
            auto elapsed = Clock::now() - frameStart;
            auto sleepMs = Ms(FRAME_MS) - std::chrono::duration_cast<Ms>(elapsed);
            if (sleepMs.count() > 0)
                std::this_thread::sleep_for(sleepMs);
            continue;
        }

        switch (_state) {
            case AppState::MENU:
                handleMenuInput(input);
                renderMenu();
                break;
            case AppState::PLAYING:
                handleGameInput(input);
                if (_game) {
                    _game->handleEvent(input);
                    _game->update();
                    if (_game->isGameOver()) {
                        const std::string &gp = _currentGameLib;
                        std::string gameName  = gp.substr(gp.rfind('/') + 1);
                        _scores.addScore(
                            gameName,
                            _playerName.empty() ? "AAA" : _playerName,
                            _game->getScore());
                        _state = AppState::GAME_OVER;
                    }
                }
                renderGame();
                break;
            case AppState::GAME_OVER:
                handleGameInput(input);
                renderGameOver();
                break;
            case AppState::EXIT:
                break;
        }

        _graphics->display();

        auto elapsed = Clock::now() - frameStart;
        auto sleepMs = Ms(FRAME_MS) - std::chrono::duration_cast<Ms>(elapsed);
        if (sleepMs.count() > 0)
            std::this_thread::sleep_for(sleepMs);
    }

    _graphics->close();
}

void Core::loadGraphics(const std::string &path)
{
    if (_graphics) {
        _graphics->close();
        _graphics.reset();
    }
    _graphics = _libs.loadGraphics(path);
    _graphics->init();
    _currentGraphicLib = path;
}

void Core::loadGame(const std::string &path)
{
    if (_game)
        _game->close();
    _game = _libs.loadGame(path);
    _game->init();
    _currentGameLib = path;
    _state = AppState::PLAYING;
}

void Core::handleMenuInput(Input input)
{
    const auto &games = _libs.gameLibs();
    const auto &glibs = _libs.graphicLibs();

    if (_typingName) {
        if (input == ACTION)
            _typingName = false;
        return;
    }

    switch (input) {
        case UP:
            if (!_focusOnLibs && _menuSel > 0) --_menuSel;
            if (_focusOnLibs && _libSel > 0)   --_libSel;
            break;
        case DOWN:
            if (!_focusOnLibs && _menuSel < static_cast<int>(games.size()) - 1) ++_menuSel;
            if (_focusOnLibs  && _libSel  < static_cast<int>(glibs.size()) - 1) ++_libSel;
            break;
        case ACTION:
            if (!_focusOnLibs && !games.empty())
                loadGame(games[static_cast<std::size_t>(_menuSel)]);
            else if (_focusOnLibs && !glibs.empty())
                loadGraphics(glibs[static_cast<std::size_t>(_libSel)]);
            break;
        case NEXT_LIB:
            _focusOnLibs = !_focusOnLibs;
            break;
        case MENU:
        case EXIT:
            _state = AppState::EXIT;
            break;
        default:
            break;
    }
}

void Core::handleGameInput(Input input)
{
    switch (input) {
        case NEXT_LIB:   switchNextLib();         break;
        case NEXT_GAME:  switchNextGame();        break;
        case RESTART:    restartGame();           break;
        case MENU:
        case GAME_MENU:  goToMenu();              break;
        case EXIT:       _state = AppState::EXIT; break;
        default:                                  break;
    }
}

void Core::switchNextLib()
{
    std::string next = LibManager::nextIn(_libs.graphicLibs(), _currentGraphicLib);
    if (!next.empty() && next != _currentGraphicLib)
        loadGraphics(next);
}

void Core::switchNextGame()
{
    std::string next = LibManager::nextIn(_libs.gameLibs(), _currentGameLib);
    if (!next.empty())
        loadGame(next);
}

void Core::restartGame()
{
    if (_game) {
        _game->close();
        _game->init();
        _state = AppState::PLAYING;
    }
}

void Core::goToMenu()
{
    if (_game) {
        _game->close();
        _game.reset();
    }
    _typingName = false;
    _state = AppState::MENU;
}

void Core::menuText(const std::string &content, float rx, float ry, Color color)
{
    int x = static_cast<int>(rx * VIRT_W);
    int y = static_cast<int>(ry * VIRT_H);
    _graphics->drawText({content, FONT, x, y, color});
}

void Core::renderMenu()
{
    _graphics->clear();

    menuText("== ARCADE ==", 0.38f, 0.05f, Color::YELLOW);

    std::string nameDisplay = "Name: "
        + (_playerName.empty() ? "_" : _playerName)
        + (_typingName ? "|" : "");
    menuText(nameDisplay, 0.05f, 0.12f, Color::WHITE);
    if (_typingName)
        menuText("TAB to confirm name", 0.05f, 0.18f, Color::GRAY);

    const auto &games = _libs.gameLibs();
    const auto &glibs = _libs.graphicLibs();

    std::string gamesHeader = !_focusOnLibs ? "> GAMES <" : "-- GAMES --";
    std::string libsHeader  =  _focusOnLibs ? "> GRAPHICS <" : "-- GRAPHICS --";

    menuText(gamesHeader, 0.05f, 0.26f, !_focusOnLibs ? Color::YELLOW : Color::CYAN);
    for (int i = 0; i < static_cast<int>(games.size()); ++i) {
        const std::string &p = games[static_cast<std::size_t>(i)];
        std::string label = (!_focusOnLibs && i == _menuSel ? "> " : "  ")
                          + p.substr(p.rfind('/') + 1);
        menuText(label, 0.05f, 0.33f + i * 0.08f,
                 !_focusOnLibs && i == _menuSel ? Color::YELLOW : Color::WHITE);
    }

    menuText(libsHeader, 0.52f, 0.26f, _focusOnLibs ? Color::YELLOW : Color::CYAN);
    for (int i = 0; i < static_cast<int>(glibs.size()); ++i) {
        const std::string &p = glibs[static_cast<std::size_t>(i)];
        std::string label = (_focusOnLibs && i == _libSel ? "> " : "  ")
                          + p.substr(p.rfind('/') + 1)
                          + (p == _currentGraphicLib ? " *" : "");
        menuText(label, 0.52f, 0.33f + i * 0.08f,
                 _focusOnLibs && i == _libSel ? Color::YELLOW : Color::WHITE);
    }

    float scoreY = 0.33f + std::max(games.size(), glibs.size()) * 0.08f + 0.06f;
    menuText("-- TOP SCORES --", 0.05f, scoreY, Color::CYAN);
    if (!games.empty()) {
        const std::string &gp = games[static_cast<std::size_t>(_menuSel)];
        std::string gameName  = gp.substr(gp.rfind('/') + 1);
        auto top = _scores.getScores(gameName, 5);
        if (top.empty())
            menuText("no scores yet", 0.05f, scoreY + 0.07f, Color::GRAY);
        for (int i = 0; i < static_cast<int>(top.size()); ++i) {
            const auto &e = top[static_cast<std::size_t>(i)];
            menuText(e.player + "  " + std::to_string(e.score),
                     0.05f, scoreY + 0.07f + i * 0.06f, Color::GREEN);
        }
    }

    menuText("TAB:confirm name/switch column  SPACE:select  ESC:quit",
             0.05f, 0.94f, Color::MAGENTA);
}

void Core::renderGame()
{
    _graphics->clear();
    if (!_game)
        return;
    for (const auto &entity : _game->getEntities())
        _graphics->drawEntity(entity, _game->getWidth(), _game->getHeight());
}

void Core::renderGameOver()
{
    renderGame();
    menuText("GAME  OVER", 0.38f, 0.40f, Color::RED);
    menuText("Score: " + std::to_string(_game ? _game->getScore() : 0), 0.38f, 0.50f, Color::WHITE);
    menuText("R:restart   ESC:menu   close:quit", 0.28f, 0.60f, Color::MAGENTA);
}

} // namespace Arcade