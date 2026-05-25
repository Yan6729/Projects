/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Button
*/

#ifndef BUTTON_HPP_
    #include <iostream>
    #include <string>
    #include <functional>
    #include "ModifiedWindow.hpp"
    #include <cmath>
    #include <map>
    #include <memory>
    #include <list>
    #include <SFML/Audio.hpp>
    using namespace std;
    using namespace sf;
    #define BUTTON_HPP_
    #define PI 3.14159265358979323846

namespace reSf {
    class RoundedRectangleShape : public Shape {
        public:
            RoundedRectangleShape();
            RoundedRectangleShape(Vector2f size, double radius, unsigned int cornerPoints);
            RoundedRectangleShape& operator()(Vector2f size, double radius, unsigned int cornerPoints);
            ~RoundedRectangleShape();
            void setCornerRadius(double radius);
            double getCornerRadius(void);
            void setSize(Vector2f size);
            Vector2f getSize(void);
            void setCornerPoints(unsigned int cornerPoints);
            virtual size_t getPointCount() const override;
            virtual Vector2f getPoint(size_t index) const override;
        
        private:
            Vector2f _size;
            float _radius;
            unsigned int _cornerPoints;
    };

    class Button{
        public:
            Button();
            Button(Vector2f size, float radius, const string& label, const Font& _font);
            Button& operator()(Vector2f size, float radius, const string& label, const Font& _font);
            ~Button();
            bool onClick(Event* _event, ModifiedWindow* _win, function<void(void)> _function);
            void draw(ModifiedWindow* window);
            void setPosition(Vector2f _pos);
            void buttonDesign(const sf::Color& _color, size_t thickness, const sf::Color& _colorThickness, const sf::Color& _textColor);
            void setBackgroudColor(const sf::Color& _color);
            void resetcolor(void);
            void setOriginColor(const sf::Color& _color);
            std::string getText(void);
            void addSoundFile(const std::string& _filepath);
            Button(Button&& other) noexcept;
            Button& operator=(Button&& other) noexcept;

        protected:
        private:
            RoundedRectangleShape _btn;
            Text _text;
            Font _font;
            sf::Color _originColor;
            bool _haveAColor;
            std::unique_ptr<sf::Music> _sound;
            bool haveSound = false;
    };
}
#endif /* !BUTTON_HPP_ */
