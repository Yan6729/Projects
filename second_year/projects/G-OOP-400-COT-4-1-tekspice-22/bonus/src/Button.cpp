/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Button
*/

#include "../include/Button.hpp"
using namespace reSf;

RoundedRectangleShape::RoundedRectangleShape() :
    _size({0, 0}), _radius(0.0), _cornerPoints(0)
{
    update();
}

RoundedRectangleShape::RoundedRectangleShape(Vector2f size, double radius, unsigned int cornerPoints) :
    _size(size), _radius(radius), _cornerPoints(cornerPoints)
{
    update();
}

RoundedRectangleShape& RoundedRectangleShape::operator()(Vector2f size, double radius, unsigned int cornerPoints) {
    _size = size;
    _radius = radius;
    _cornerPoints = cornerPoints;
    update();
    return *this;
}

RoundedRectangleShape::~RoundedRectangleShape()
{}

void RoundedRectangleShape::setCornerRadius(double radius)
{
    _radius = radius;
    update();
}

double RoundedRectangleShape::getCornerRadius(void)
{
    return _radius;
}

void RoundedRectangleShape::setSize(Vector2f size)
{
    _size = size;
    update();
}

Vector2f RoundedRectangleShape::getSize(void)
{
    return _size;
}

void RoundedRectangleShape::setCornerPoints(unsigned int cornerCount)
{
    _cornerPoints = cornerCount;
    update();
}

size_t RoundedRectangleShape::getPointCount() const
{
    return _cornerPoints * 4;
}

Vector2f RoundedRectangleShape::getPoint(size_t index) const
{
    int corner = index / _cornerPoints;
    float angle = (index % _cornerPoints) * 90.f / (_cornerPoints - 1);
    sf::Vector2f center;

    switch (corner)
    {
        case 0:
            center = {_radius, _radius};
            angle += 180;
            break;
        case 1:
            center = {_size.x - _radius, _radius};
            angle += 270;
            break;
        case 2:
            center = {_size.x - _radius, _size.y - _radius};
            break;
        case 3:
            center = {_radius, _size.y - _radius};
            angle += 90;
            break;
    }

    float rad = angle * 3.14159f / 180.f;

    return {
        center.x + cos(rad) * _radius,
        center.y + sin(rad) * _radius
    };
}


Button::Button(Vector2f size, float radius, const string& label, const Font& font)
{
    _btn.setSize(size);
    _btn.setCornerRadius(radius);
    _btn.setCornerPoints(10);
    
    _text.setString(label);
    _text.setFont(font);
}

Button& Button::operator()(Vector2f size, float radius, const string& label, const Font& font)
{
    _btn.setSize(size);
    _btn.setCornerRadius(radius);
    _btn.setCornerPoints(10);
    
    _text.setString(label);
    _text.setFont(font);
    return *this;
}

Button::~Button()
{
}

Button::Button()
{}

void Button::buttonDesign(const Color& _color, size_t _thickness, const Color& _colorThickness, const Color& _textColor)
{
    _btn.setFillColor(_color);
    _btn.setOutlineColor(_colorThickness);
    _btn.setOutlineThickness(_thickness);

    _text.setFillColor(_textColor);
    _text.setCharacterSize(20);
}

bool Button::onClick(Event* _event, RenderWindow* _win, function<void(void)> _function)
{
    if (_event->type == Event::MouseButtonPressed) {
        Vector2i _mousePos = Mouse::getPosition(*_win);
        Vector2f _convert = _win->mapPixelToCoords(_mousePos);

        if (_btn.getGlobalBounds().contains(_convert)){
            _function();
            return true;
        }
    }
    return false;
}

void Button::setPosition(Vector2f _pos)
{
    _btn.setPosition(_pos);
    FloatRect bounds = _text.getLocalBounds();
    _text.setPosition(
        _btn.getPosition().x + (_btn.getSize().x - bounds.width) / 2,
        (_btn.getPosition().y + (_btn.getSize().y - bounds.height) / 2) - 4 
    );
}

void Button::draw(RenderWindow* _window)
{
    _window->draw(_btn);
    _window->draw(_text);
}
