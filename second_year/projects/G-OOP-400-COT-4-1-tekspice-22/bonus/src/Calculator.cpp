/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Calculator
*/

#include "../include/Calculator.hpp"

Calculator::Calculator()
{
    if (!_font.loadFromFile("./bonus/LibraSerifModern-Regular.otf"))
        return;
    _btn.emplace("0", make_unique<Button>());
    _btn.emplace("1", make_unique<Button>());
    _btn.emplace("2", make_unique<Button>());
    _btn.emplace("3", make_unique<Button>());
    _btn.emplace("4", make_unique<Button>());
    _btn.emplace("5", make_unique<Button>());
    _btn.emplace("6", make_unique<Button>());
    _btn.emplace("7", make_unique<Button>());
    _btn.emplace("8", make_unique<Button>());
    _btn.emplace("9", make_unique<Button>());
    _btn.emplace("+", make_unique<Button>());
    _btn.emplace("=", make_unique<Button>());
    _btn.emplace("-", make_unique<Button>());
    _btn.emplace("/", make_unique<Button>());
    _btn.emplace("*", make_unique<Button>());
    _btn.emplace("AC", make_unique<Button>());
    _btn.emplace("DEL", make_unique<Button>());

    (*_btn["0"])(Vector2f{170,50}, 15, "0", _font);
    (*_btn["1"])(Vector2f{75,50}, 15, "1", _font);
    (*_btn["2"])(Vector2f{75,50}, 15, "2", _font);
    (*_btn["3"])(Vector2f{75,50}, 15, "3", _font);
    (*_btn["4"])(Vector2f{75,50}, 15, "4", _font);
    (*_btn["5"])(Vector2f{75,50}, 15, "5", _font);
    (*_btn["6"])(Vector2f{75,50}, 15, "6", _font);
    (*_btn["7"])(Vector2f{75,50}, 15, "7", _font);
    (*_btn["8"])(Vector2f{75,50}, 15, "8", _font);
    (*_btn["9"])(Vector2f{75,50}, 15, "9", _font);
    (*_btn["+"])(Vector2f{75,170}, 15, "+", _font);
    (*_btn["="])(Vector2f{70,50}, 15, "=", _font);
    (*_btn["-"])(Vector2f{75,50}, 15, "-", _font);
    (*_btn["/"])(Vector2f{75,50}, 15, "/", _font);
    (*_btn["*"])(Vector2f{75,50}, 15, "*", _font);
    (*_btn["AC"])(Vector2f{75,50}, 15, "AC", _font);
    (*_btn["DEL"])(Vector2f{75,50}, 15, "DEL", _font);

    _btn["0"]->setPosition({25,460});
    _btn["0"]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));
    _btn["1"]->setPosition({199,400});
    _btn["1"]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));
    _btn["2"]->setPosition({112,400});
    _btn["2"]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));
    _btn["3"]->setPosition({25,400});
    _btn["3"]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));
    _btn["4"]->setPosition({25,340});
    _btn["4"]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));
    _btn["5"]->setPosition({112,340});
    _btn["5"]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));   
    _btn["6"]->setPosition({199,340});
    _btn["6"]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));
    _btn["7"]->setPosition({25,280});
    _btn["7"]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));
    _btn["8"]->setPosition({112,280});
    _btn["8"]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));
    _btn["9"]->setPosition({199,280});
    _btn["9"]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));
    _btn["="]->setPosition({205,460});
    _btn["="]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));
    _btn["+"]->setPosition({286, 340});
    _btn["+"]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));
    _btn["-"]->setPosition({286,220});
    _btn["-"]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));
    _btn["AC"]->setPosition({286, 280});
    _btn["AC"]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));
    _btn["DEL"]->setPosition({25, 220});
    _btn["DEL"]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));
    _btn["/"]->setPosition({199,220});
    _btn["/"]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));
    _btn["*"]->setPosition({112,220});
    _btn["*"]->buttonDesign(Color(124,124,124),2,Color(0,0,0),Color(0,0,0));
}

Calculator::~Calculator()
{
}

int Calculator::launch() {
    sf::RenderWindow _window(sf::VideoMode(400, 540), "Bouton avec Texte");

    string _screenText = "0";
    RectangleShape screen(Vector2f(350, 80));
    screen.setPosition(25, 25);
    screen.setFillColor(Color(128, 128, 128));
    Text _display;
    bool result = false;


    while (_window.isOpen()) {
        sf::Event _event;
        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed)
                _window.close();
            _btn["0"]->onClick(&_event, &_window, [&](){
                if (_screenText == "0" || result == true) {
                    result = false;
                    return;
                } else {
                    _screenText += "0";
                }
            });
            _btn["1"]->onClick(&_event, &_window, [&](){
                if (_screenText == "0" || result == true) {
                    _screenText.clear();
                    _screenText = "1";
                    result = false;
                } else {
                    _screenText += "1";
                }
            });
            _btn["2"]->onClick(&_event, &_window, [&](){
                if (_screenText == "0" || result == true) {
                    _screenText.clear();
                    _screenText = "2";
                    result = false;
                } else {
                    _screenText += "2";
                }
            });
            _btn["3"]->onClick(&_event, &_window, [&](){
                if (_screenText == "0" || result == true) {
                    _screenText.clear();
                    _screenText = "3";
                    result = false;
                } else {
                    _screenText += "3";
                }
            });
            _btn["4"]->onClick(&_event, &_window, [&](){
                if (_screenText == "0" || result == true) {
                    _screenText.clear();
                    _screenText = "4";
                    result = false;
                } else {
                    _screenText += "4";
                }
            });
            _btn["5"]->onClick(&_event, &_window, [&](){
                if (_screenText == "0" || result == true) {
                    _screenText.clear();
                    _screenText = "5";
                    result = false;
                } else {
                    _screenText += "5";
                }
            });
            _btn["6"]->onClick(&_event, &_window, [&](){
                if (_screenText == "0" || result == true) {
                    _screenText.clear();
                    _screenText = "6";
                    result = false;
                } else {
                    _screenText += "6";
                }
            });
            _btn["7"]->onClick(&_event, &_window, [&](){
                if (_screenText == "0" || result == true) {
                    _screenText.clear();
                    _screenText = "7";
                    result = false;
                } else {
                    _screenText += "7";
                }
            });
            _btn["8"]->onClick(&_event, &_window, [&](){
                if (_screenText == "0" || result == true) {
                    _screenText.clear();
                    _screenText = "8";
                    result = false;
                } else {
                    _screenText += "8";
                }
            });
            _btn["9"]->onClick(&_event, &_window, [&](){
                if (_screenText == "0" || result == true) {
                    _screenText.clear();
                    _screenText = "9";
                    result = false;
                } else {
                    _screenText += "9";
                }
            });
            _btn["+"]->onClick(&_event, &_window, [&](){
                result = false;
                if (_screenText[_screenText.size()-1] == ' ') {
                   return;
                } else {
                    _screenText += " + ";
                }
            });
            _btn["-"]->onClick(&_event, &_window, [&](){
                result = false;
                if (_screenText[_screenText.size()-1] == ' ') {
                    return;
                } else {
                    _screenText += " - ";
                }
            });
            _btn["*"]->onClick(&_event, &_window, [&](){
                result = false;
                if (_screenText[_screenText.size()-1] == ' ') {
                    return;
                } else {
                    _screenText += " * ";
                }
            });
            _btn["/"]->onClick(&_event, &_window, [&](){
                result = false;
                if (_screenText == "0" || _screenText[_screenText.size()-1] == ' ') {
                    return;
                } else {
                    _screenText += " / ";
                }
            });
            _btn["AC"]->onClick(&_event, &_window, [&](){
                _screenText.clear();
                _screenText = "0";
                result = false;
            });
            _btn["DEL"]->onClick(&_event, &_window, [&](){
                result = false;
                if (_screenText.empty())
                    return;
                if (_screenText.size() == 1) {
                    _screenText.clear();
                    _screenText = "0";
                    return;
                }
                if (_screenText[_screenText.size()-1] == ' ') {
                    _screenText.erase(_screenText.size()-3, 3);
                } else {
                    _screenText.erase(_screenText.size() - 1);
                }
            });
            _btn["="]->onClick(&_event, &_window, [&](){
                string value = _back.calcul(_screenText);
                _screenText = value;
                result = true;
            });
        }

        _window.clear(Color::White);

        for (auto& it : _btn) {
            it.second->draw(&_window);
        }
        _display.setString(_screenText);
        _display.setFont(_font);
        FloatRect _bound = _display.getGlobalBounds();
        _display.setPosition(350-(_bound.width - 10), 80-50);
        _display.setFillColor(Color(0, 0, 0));
        _display.setCharacterSize(50);
        _window.draw(screen);
        _window.draw(_display);
        _window.display();
    }
    return 0;
}

int main()
{
    Calculator _calc;

    _calc.launch();
}