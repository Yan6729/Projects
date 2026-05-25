/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** ModifiedWindow
*/

#include "../../include/reSf/ModifiedWindow.hpp"
using namespace reSf;

ModifiedWindow::ModifiedWindow()
    :  _title(""), _windowSize(Vector2u(1920, 1080)), _isFullscreen(false)
{
    create(VideoMode(1920, 1080), "", Style::Close);
    setView(View(FloatRect(0, 0, 1920, 1080)));
}

ModifiedWindow::ModifiedWindow(Vector2u size, const string& title) :
    _title(title), _windowSize(size), _isFullscreen(false)
{
    create(VideoMode(size.x, size.y), title, Style::Close);
    setView(View(FloatRect(0, 0, size.x, size.y)));
}

void ModifiedWindow::addTitle(string title)
{
    _title = title;
    setTitle(title);
}

void ModifiedWindow::centerWindow(sf::Vector2u size)
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    setPosition(sf::Vector2i(
        (desktop.width - size.x) / 2,
        (desktop.height - size.y) / 2
    ));
}

void ModifiedWindow::setResolution(sf::Vector2u size)
{
    _windowSize = size;
    if (_isFullscreen) {
        create(VideoMode(size.x, size.y), _title, Style::Close);
        _isFullscreen = false;
    } else {
        setSize(size);
    }
    setView(sf::View(sf::FloatRect(0, 0, size.x, size.y)));
    centerWindow(size);
}

void ModifiedWindow::toggleFullscreen(void)
{
    if (_isFullscreen) {
        create(sf::VideoMode(_windowSize.x, _windowSize.y), _title, sf::Style::Close);
        setView(sf::View(sf::FloatRect(0, 0, _windowSize.x, _windowSize.y)));
        centerWindow(_windowSize);
        _isFullscreen = false;
    } else {
        sf::VideoMode mode = sf::VideoMode::getFullscreenModes().at(0);
        create(mode, _title, sf::Style::Fullscreen);
        setView(sf::View(sf::FloatRect(0, 0, mode.width, mode.height)));
        _isFullscreen = true;
    }
}

bool ModifiedWindow::isFullscreen() const
{
    return _isFullscreen;
}

void ModifiedWindow::loopDisplay(Event& _event, function<void(void)> _function)
{
    while (isOpen()) {
        while(pollEvent(_event)) {
            if (_event.type == Event::Closed) {
                close();
            }
            if (_event.type == Event::KeyPressed) {
                if (_event.key.code == Keyboard::Escape) {
                    close();
                }
            }
        }
        _function();
    }
}

void ModifiedWindow::loopDisplay(Event& _event, function<void(void)> _eventFunc, function<void(void)> _function)
{
    while (isOpen()) {
        while(pollEvent(_event)) {
            if (_event.type == Event::Closed) {
                close();
            }
            if (_event.type == Event::KeyPressed) {
                if (_event.key.code == Keyboard::Escape) {
                    close();
                }
            }
            _eventFunc();
        }
        _function();
    }
}
