/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** ModifiedWindow
*/

#ifndef MODIFIEDWINDOW_HPP_
    #define MODIFIEDWINDOW_HPP_
    #include <SFML/Graphics.hpp>
    using namespace std;
    #include <functional>
    #include <map>
    using namespace sf;


namespace reSf {
    class ModifiedWindow : public RenderWindow {
        public:
            ModifiedWindow();
            ModifiedWindow(Vector2u size, const std::string& title);
            ~ModifiedWindow() = default;
            void setResolution(Vector2u size);
            void toggleFullscreen(void);
            void centerWindow(sf::Vector2u size);
            bool isFullscreen() const;
            void addTitle(string title);
            void loopDisplay(Event& _event, function<void(void)> _function);
            void loopDisplay(Event& _event, function<void(void)> _eventFunc, function<void(void)> _function);

        private:
            string _title;
            Vector2u _windowSize;
            bool _isFullscreen;
    };
}

#endif /* !MODIFIEDWINDOW_HPP_ */
