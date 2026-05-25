/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** SfmlDisplay
*/

#ifndef SFMLDISPLAY_HPP_
    #include <SFML/Graphics.hpp>
    #include <vector>
    #include <map>
    #include <string>
    #include "../IModule.hpp"
    #include "../IDisplay.hpp"
#define SFMLDISPLAY_HPP_

namespace Krell {
    class SfmlDisplay : public IDisplay {
        public:
            SfmlDisplay();
            ~SfmlDisplay();
            void init();
            void stop();
            void Events();
            std::vector<IModule*>& getModuleList();
            void display_modules(const std::vector<IModule*>& modules) override;
            void slide();
            
        private:
            sf::RenderWindow _window;
            sf::Font _font;
            std::vector<IModule*> module_list;
            sf::View leftview;
            sf::View rightview;
            sf::Sprite sprite;
    };
}
int getCpuCount();

#endif /* !SFMLDISPLAY_HPP_ */
