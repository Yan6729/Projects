/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** SfmlDisplay
*/

#include "../../include/displays/SfmlDisplay.hpp"
#include "../../include/MonitorCore.hpp"
#include "../../include/displays/NcurseDisplay.hpp"


#include <fstream>
#include <string>

int getCpuCount() {
    std::ifstream file("/proc/stat");
    std::string line;
    int count = 0;

    while (std::getline(file, line)) {
        if (line.rfind("cpu", 0) == 0 && line != "cpu")
            count++;
    }
    return count;
}

namespace Krell {

    void SfmlDisplay::slide()
    {
        Krell::MonitorCore core;

        int count = getCpuCount();

        for (int a = 0; a < count-1; a++) {
            core.addModule(new Krell::CpuInfo(std::to_string(a)));
        }

        core.addModule(new Krell::RamModule());
        core.addModule(new Krell::Battery());
        core.addModule(new Krell::Network());
        core.addModule(new Krell::DiskModule());
        core.addModule(new Krell::HostUserModule());
        core.addModule(new Krell::OSKernelModule());
        core.addModule(new Krell::DateTimeModule());
        core.addModule(new Krell::ProcessModule());

        core.setDisplay(new Krell::NcursesDisplay);
        core.run();
    }


    SfmlDisplay::SfmlDisplay() : _window(sf::VideoMode(sf::VideoMode::getDesktopMode()), "GKrellM wannabe", sf::Style::Close)
    {
        sf::Texture texture;

        if (!texture.loadFromFile("Background.jpeg")) {
            exit(EXIT_FAILURE);
        }
        sprite.setTexture(texture);
        sf::Vector2u size = _window.getSize();
        sprite.setPosition(size.x, size.y);
        leftview.reset(sf::FloatRect(0.f, 0.f, size.x/2, size.y/2));
        rightview.reset(sf::FloatRect(size.x/2, 0.f, size.x/2, size.y/2));

        leftview.setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));
        rightview.setViewport(sf::FloatRect(0.5f, 0.f, 0.5f, 1.f));
        if (!_font.loadFromFile("Arial.ttf")) {
            std::cerr << "Failed to load font!" << std::endl;
        }
    }

    SfmlDisplay::~SfmlDisplay() {
        
        _window.close();
    }

    std::vector<IModule*>& SfmlDisplay::getModuleList() {
        return module_list;
    }

    void SfmlDisplay::stop() {
        _window.close();
    }

    void SfmlDisplay::Events()
    {
        sf::Clock clock;
        sf::Event event;

        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                stop();
                std::exit(0);
            }
            if (event.type ==  sf::Event::MouseWheelScrolled) {
                sf::Vector2i pos = sf::Mouse::getPosition(_window);
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                    if (pos.x < int(_window.getSize().x/2))
                        leftview.move(0, -event.mouseWheelScroll.delta * 10.f);
                    else if (pos.x > int(_window.getSize().x/2))
                        rightview.move(0, -event.mouseWheelScroll.delta * 10.f); 
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::S) {
                    stop();
                    slide();
                }
            }
        }
    }

    void SfmlDisplay::display_modules(const std::vector<IModule*>& modules) {
        Events();
        _window.clear(sf::Color::Black);
        float y = 10.f;
        float y_ = 10.f;
        for (auto m : modules) {
            if (m->getName().find("cpu") != std::string::npos) {
                _window.setView(leftview);
                _window.draw(sprite);
                auto data = m->getData();
                sf::Text moduleName(m->getName(), _font, 20);
                moduleName.setFillColor(sf::Color::Green);
                moduleName.setPosition(10.0f, y);
                _window.draw(moduleName);
                y = y + 25;
                for (const auto& [key, value] : data) {
                    std::ostringstream ss;
                    ss << key << ": " << value;
                    sf::Text text(ss.str(), _font, 16);
                    text.setFillColor(sf::Color::White);
                    text.setPosition(20.0f, y);
                    _window.draw(text);
                    y += 20;
                }
                y += 15;
            } else {
                _window.setView(rightview);
                _window.draw(sprite);
                auto data = m->getData();
                sf::Text moduleName(m->getName(), _font, 20);
                moduleName.setFillColor(sf::Color::Green);
                moduleName.setPosition(_window.getSize().x/2, y_);
                _window.draw(moduleName);
                y_ = y_ + 25;
                for (const auto& [key, value] : data) {
                    std::ostringstream ss;
                    ss << key << ": " << value;
                    sf::Text text(ss.str(), _font, 16);
                    text.setFillColor(sf::Color::White);
                    text.setPosition(_window.getSize().x/2+10.f, y_);
                    _window.draw(text);
                    y_ += 20;
                }
                y_ += 15;
            }
        }
        _window.display();
    }

    void SfmlDisplay::init() {
        
    }
}