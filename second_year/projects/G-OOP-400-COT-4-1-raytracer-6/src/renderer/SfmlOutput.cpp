/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** SfmlOutput
*/

#include "../../include/renderer/SfmlOutput.hpp"
#include "../../include/lights/Lighting.hpp"
#include <cstdlib>
using namespace RayTracer;

bool openUrl(const std::string& htmFile) {
    #if defined(_WIN32)
        HINSTANCE result = ShellExecuteW(nullptr, L"open", htmFile, nullptr, nullptr, SW_SHOWNORMAL);
        return reinterpret_cast<intptr_t>(result) > 32;
    #elif defined(__APPLE__)
        std::string cmd = "open \"" + htmFile + "\"";
        return std::system(cmd.c_str()) == 0;
    #else
        std::string cmd = "xdg-open \"" + htmFile + "\"";
        return std::system(cmd.c_str()) == 0;
    #endif
}

SfmlOutput::SfmlOutput()
    : _window(reSf::ModifiedWindow(Vector2u(1600, 900), "Raytracer -- graphic output")), _buf({800, 800}),
    _sceneName("-- Select a scene to draw --"), avencment("0%")
{
    _loadingProgress = 0;
    _loadingStep = 0;
    _index = 1;
    _maxX = 800;
    _maxY = 800;
    _img.create(800, 800, sf::Color::Black);
    if (!(_text.loadFromImage(_img)))
        throw RayTracerError("Error while charging the image");
    
    if (!(_font.loadFromFile("asset/LibraSerifModern-Regular.otf")))
        throw RayTracerError("Can't find the font file");
    _sp.setTexture(_text);
}

SfmlOutput::~SfmlOutput()
{
}

void SfmlOutput::loader(void)
{
    switch (_loadingStep) {
        case 0:
            {
                int idx2 = 0;
                double y = 297.5;
                for (auto& name : {"Start", "About Us", "Quit"}) {
                    reSf::Button btn(sf::Vector2f(360.f, 55.2), 10.f, name, _font);
                    btn.buttonDesign(
                        sf::Color(50, 50, 70),
                        2,
                        sf::Color(100, 100, 180),
                        sf::Color::White
                    );
                    btn.setOriginColor(sf::Color(50, 50, 70));
                    btn.setPosition(sf::Vector2f(670.f, y));
                    btn.addSoundFile("asset/mouseSound.mp3");
                    _menuButton.push_back(std::move(btn));
                    idx2++;
                    y += 75.f;
                }
            }
            _loadingProgress += 15;
            break;
        case 1:
            {
                std::vector<string> _scenes = LoadFiles("scenes").getfiles();
                for (auto& scene : _scenes) {
                    std::size_t pos;
                    Config cfg;
                    cfg.readFile(string("scenes/" + scene).c_str());
                    if (((pos = scene.find(".cfg")) != string::npos) && cfg.exists("camera")) {
                        _filesScene.emplace(scene.substr(0, pos), "scenes/" + scene);
                    }
                }
            }
            _loadingProgress += 15;
            break;
        case 2:
            {
                std::vector<string> _plugins = LoadFiles("plugins").getfiles();
                for (auto& plugin : _plugins) {
                    if (plugin.find(".so") != string::npos)
                        _prim.loadPlugin("plugins/" + plugin);
                }
            }
            _loadingProgress += 25;
            break;
        case 3:
            _build = make_unique<RayTracer::SceneBuilder>(_prim, _light);
            _loadingProgress += 15;
            break;
        case 4:
            {
                int idx = 0;
                for (auto& sceneInfo : _filesScene) {
                    reSf::Button btn(sf::Vector2f(360.f, 55.2), 8.f, sceneInfo.first, _font);
                    btn.buttonDesign(
                        sf::Color(50, 50, 70),
                        2,
                        sf::Color(100, 100, 180),
                        sf::Color::White
                    );
                    btn.setOriginColor(sf::Color(50, 50, 70));
                    btn.addSoundFile("asset/mouseSound.mp3");
                    _scenesButtons.push_back(std::move(btn));
                    idx++;
                }
                _maxScroll = std::max(0.f, (float)(_scenesButtons.size() - _visibleButtons));
            }
            _loadingProgress += 15;
            break;
        case 5:
            {
                int idx1 = 0;
                for (auto& name : {"clear", "Export scenes (ppm)", "↩ Menu"}) {
                    reSf::Button btn(sf::Vector2f(360.f, 55.2), 8.f, name, _font);
                    btn.buttonDesign(
                        sf::Color(50, 50, 70),
                        2,
                        sf::Color(100, 100, 180),
                        sf::Color::White
                    );
                    btn.setOriginColor(sf::Color(50, 50, 70));
                    btn.setPosition(sf::Vector2f(1220.f, 70.f * idx1 + 20.f));
                    btn.addSoundFile("asset/mouseSound.mp3");
                    _leftPanelButton.push_back(std::move(btn));
                    idx1++;
                }
            }
            _loadingProgress += 15;
            break;
        default:
            _state = STATE::MENU;
            break;
    }
}

void SfmlOutput::configCamera(CameraData _data)
{
    _cam.origin = Vec3(_data.xp, _data.yp, _data.zp);

    double _fov = _data.field_of_view * PI / 180.0;
    double _halfW = tan(_fov / 2.0);
    double _halfH = _halfW * (double)_maxY / _maxX;

    double _yaw = _data.yr * PI / 180.0;
    double _pitch = -_data.xr * PI / 180.0;

    Vec3 _forward = Vec3(
        cos(_pitch) * sin(_yaw),
        sin(_pitch),
        cos(_pitch) * cos(_yaw)
    ).normalized();

    Vec3 worldUp = std::abs(_forward.dot(Vec3(0, 1, 0))) > 0.999 ? ({
        Vec3(0, 0, 1);
    }) : ({
        Vec3(0, 1, 0);
    });
    Vec3 _right = _forward.cross(worldUp).normalized();
    Vec3 _up = _right.cross(_forward).normalized();

    Vec3 s_Center = _cam.origin + _forward;
    Vec3 s_Corner = s_Center - _right * _halfW - _up * _halfH;

    _cam.screen = Rectangle3D(
        s_Corner,
        _right * (2 * _halfW),
        _up * (2 * _halfH)
    );
}

void SfmlOutput::menu_displaying(void) {
    Sprite _menu;
    Texture back;

    if (!(back.loadFromFile("asset/menu_background.png")))
        throw RayTracerError("Error while loading the background png.");

    _menu.setTexture(back);
    _menu.setScale(
        1600.f / back.getSize().x,
        900.f / back.getSize().y
    );
    _window.draw(_menu);

    for (auto& but : _menuButton) {
        but.draw(&_window);
    }

}

void SfmlOutput::drawSceneButtons()
{
    float y = _buttonStartY;

    for (size_t i = 0; i < _scenesButtons.size(); ++i)
    {
        size_t visibleIndex = i - _scrollOffset;
        if (i >= (size_t)(_scrollOffset) && 
            visibleIndex < (size_t)(_visibleButtons))
        {
            _scenesButtons[i].setPosition(sf::Vector2f(20.f, y));
            _scenesButtons[i].draw(&_window);
            y += _buttonHeight;
        }
    }
}

void SfmlOutput::showTheRendering(void)
{
    const int PANEL_X = 400;
    _sp.setPosition(PANEL_X, 0);
    vector<string> _types = _scene.primitives_presents;

    if (_currentLine >= _maxY)
        return;
    int h = _currentLine;
    for (int w = 0; w < _maxX; w++) {
        std::optional<HitRecord> _closest;
        double _tMin = 1e9;
        RayTracer::Ray _ray = _cam.thorwRay(
            (double)w / (_maxX - 1),
            (double)h / (_maxY - 1)
        );
        for (auto _type : _types) {
            for (auto& _prim : _scene.getPrimitives(_type)) {
                auto _hit = _prim->intersect(_ray, 1e-1, _tMin);
                if (_hit && _hit->t < _tMin) {
                    _tMin = _hit->t;
                    _closest = _hit;
                }
            }
        }
        if (_closest) {
            Color surfaceColor(
                _closest->_color.x,
                _closest->_color.y,
                _closest->_color.z
            );
            Color lit = computeLighting(*_closest, surfaceColor, _scene);
            _img.setPixel(w, h, sf::Color(
                (sf::Uint8)(lit.r * 255),
                (sf::Uint8)(lit.g * 255),
                (sf::Uint8)(lit.b * 255)
            ));
            _buf.setPixel(w, h, lit * 255);
        }
    }
    _currentLine++;
    _text.update(_img);
    if (_sceneName != "-- Select a scene to draw --")
        avencment = std::to_string((int)((_currentLine * 100.0) / _maxY)) + "%";
}

sf::Sprite SfmlOutput::createSprite(const sf::Texture& _text,
    const sf::Vector2f& scale,
    const sf::Vector2f& position)
{
    sf::Sprite sprite;

    sprite.setTexture(_text);
    sprite.setScale(scale);
    sprite.setPosition(position);
    return sprite;
}

void SfmlOutput::loading(void)
{
    if (count == 40) {
        count = 0;
        loader();
        _loadingStep += 1;
    }
    sf::Sprite _gifSprite;
    if (!(_introTexture.loadFromFile("asset/loader" + to_string(_gifIndex) + ".png")) ||
        !(_back1.loadFromFile("asset/background" + to_string(one) + ".png")) ||
        !(_back2.loadFromFile("asset/background" + to_string(two) + ".png")) ||
        !(_back3.loadFromFile("asset/background" + to_string(three) + ".png")) ||
        !(_back4.loadFromFile("asset/background" + to_string(four) + ".png")) ||
        !(_back5.loadFromFile("asset/background" + to_string(five) + ".png")) ||
        !(_back6.loadFromFile("asset/background" + to_string(six) + ".png")) ||
        !(_back7.loadFromFile("asset/background" + to_string(seven) + ".png")) ||
        !(_back8.loadFromFile("asset/background" + to_string(eight) + ".png"))
    )
        throw RayTracerError("Loading frame not found.");
    sf::Sprite _backSprite1 = createSprite(_back1, sf::Vector2f(0.5, 0.5), sf::Vector2f(0, 0));
    sf::Sprite _backSprite2 = createSprite(_back2, sf::Vector2f(0.5, 0.5), sf::Vector2f(0, 400));
    sf::Sprite _backSprite3 = createSprite(_back3, sf::Vector2f(0.5, 0.5), sf::Vector2f(400, 0));
    sf::Sprite _backSprite4 = createSprite(_back4, sf::Vector2f(0.5, 0.5), sf::Vector2f(400, 400));
    sf::Sprite _backSprite5 = createSprite(_back5, sf::Vector2f(0.5, 0.5), sf::Vector2f(800, 0));
    sf::Sprite _backSprite6 = createSprite(_back6, sf::Vector2f(0.5, 0.5), sf::Vector2f(800, 400));
    sf::Sprite _backSprite7 = createSprite(_back7, sf::Vector2f(0.5, 0.5), sf::Vector2f(1200, 0));
    sf::Sprite _backSprite8 = createSprite(_back8, sf::Vector2f(0.5, 0.5), sf::Vector2f(1200, 400));
    _gifSprite.setTexture(_introTexture);
    _gifSprite.setPosition(1460.f, 780.f);
    _gifSprite.setScale(
        130.f / _introTexture.getSize().x,
        130.f / _introTexture.getSize().y
    );
    _loadBar.setSize(sf::Vector2f(_loadingProgress * 14.4, 30.f));
    _window.draw(_backSprite1);
    _window.draw(_backSprite2);
    _window.draw(_backSprite3);
    _window.draw(_backSprite4);
    _window.draw(_backSprite5);
    _window.draw(_backSprite6);
    _window.draw(_backSprite7);
    _window.draw(_backSprite8);
    _window.draw(_loadBar);
    _window.draw(_gifSprite);
    _gifIndex++;
    count++;

    if (count == 20) {
        one = one >= 8 ? 1 : one + 1;
        two = two >= 8 ? 1 : two + 1;
        three = three >= 8 ? 1 : three + 1;
        four = four >= 8 ? 1 : four + 1;
        five = five >= 8 ? 1 : five + 1;
        six = six >= 8 ? 1 : six + 1;
        seven = seven >= 8 ? 1 : seven + 1;
        eight = eight >= 8 ? 1 : eight + 1;
    }
    if (_gifIndex > 30) {
        _gifIndex = 1;
    }
    sf::sleep(sf::milliseconds(50));
}

void SfmlOutput::update(const STATE& state) {
    switch (state) {
        case STATE::MENU:
            for (auto& but : _menuButton) {
                but.onClick(&_event, &_window, [&](){
                    if (but.getText() == "Quit") {
                        _window.clear();
                        _window.close();
                    } else if (but.getText() == "Start") {
                        _state = STATE::RENDERER;
                    } else {
                        openUrl("Documentation/ABOUT_US.html");
                    }
                });
            }
            break;
        case STATE::RENDERER:
            if ((buttonPanel.getGlobalBounds().contains((Vector2f)sf::Mouse::getPosition(_window)))
            && (_event.type == sf::Event::MouseWheelScrolled)) {
                if (_event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                    _scrollOffset -= _event.mouseWheelScroll.delta;
                    _scrollOffset = std::clamp(_scrollOffset, 0, (int)(_maxScroll));
                }
            }
            for (auto& _men : _leftPanelButton) {
                _men.onClick(&_event, &_window, [&](){
                    if (_men.getText() == "clear") {
                        _buf.reset();
                        _parse = make_unique<RayTracer::SceneParser>();
                        _scene = Scene();
                        _img.create(_maxX, _maxY, sf::Color::Black);
                        _currentLine = 0;
                        _sceneName = "-- Select a scene to draw --";
                        avencment = "0%";
                    } else if (_men.getText() == "Export scenes (ppm)") {
                        _ppm.render(_buf);
                    } else {
                        _state = STATE::MENU;
                    }
                });
            }
            for (auto& it : _scenesButtons) {
                it.onClick(&_event, &_window, [&](){
                    _img.create(_maxX, _maxY, sf::Color::Black);
                    _buf.reset();
                    _parse = make_unique<RayTracer::SceneParser>();
                    _parse->parse_all(_filesScene.at(it.getText()));
                    _scene = _build->build(*_parse);
                    configCamera(_parse->camera_);
                    _currentLine = 0;
                    _sceneName = it.getText();
                });
            }
            break;
        case STATE::INTRO:
            if (_index < 120 && _event.type == sf::Event::KeyPressed && (
                _event.key.code == sf::Keyboard::BackSpace ||
                _event.key.code == sf::Keyboard::Space)
            ) {
                _state = STATE::LOADING;
            }
            break;
        default:
            break;
    }
}

sf::Text SfmlOutput::createTexte(const std::string& label,
    const sf::Vector2f& position,
    std::size_t charactereSize,
    const sf::Color _color
) {
    sf::Text _text;
    _text.setFont(_font);
    _text.setString(label);
    _text.setPosition(position);
    _text.setCharacterSize(charactereSize);
    _text.setFillColor(_color);
    return _text;
}

void SfmlOutput::render()
{
    sf::Text _text1 = createTexte("Scene Name:", sf::Vector2f(410,  805), 30, sf::Color(100, 100, 180));
    sf::Text _text2 = createTexte("Evolution:", sf::Vector2f(900,  805), 30, sf::Color(100, 100, 180));
    Sprite sp;
    sf::RectangleShape _leftPanel(sf::Vector2f(400, 900));
    sf::RectangleShape _bottomPanel(sf::Vector2f(1600, 100));

    _state = STATE::INTRO;
    _loadBar.setPosition(sf::Vector2f(20.f, 830.f));
    _currentLine = 0;
    buttonPanel.setSize(sf::Vector2f(400, 900));
    buttonPanel.setPosition(0, 0);
    buttonPanel.setFillColor(sf::Color(30, 30, 45));
    _leftPanel.setPosition(1200, 0);
    _leftPanel.setFillColor(sf::Color(30, 30, 45));
    _bottomPanel.setPosition(0, 800);
    _bottomPanel.setFillColor(sf::Color(40, 40, 45));
    _window.loopDisplay(_event, [&](){
        this->update(_state);
    }, [&](){
        _window.clear(sf::Color::Black);
        switch (_state) {
            case STATE::INTRO:
                if (_index <= 116) {
                    if (!(_introTexture.loadFromFile("asset/intro_" + to_string(_index) + ".png")))
                        throw RayTracerError("File not found.");
                    sp.setTexture(_introTexture);
                    sf::Vector2u texSize = _introTexture.getSize();
                    sp.setScale(
                        1600.f / texSize.x,
                        900.f / texSize.y
                    );
                    _window.draw(sp);
                    sf::sleep(sf::milliseconds(96));
                    _index++;
                } else {
                    _state = STATE::LOADING;
                }
                break;
            case STATE::LOADING:
                loading();
                break;
            case STATE::MENU:
                menu_displaying();
                break;
            case STATE::RENDERER:
                showTheRendering();
                _sceneText = createTexte(_sceneName, sf::Vector2f(410,  850), 30, sf::Color::White);
                avancmentText = createTexte(avencment, sf::Vector2f(900,  850), 30, sf::Color::White);
                _window.draw(buttonPanel);
                drawSceneButtons();
                _window.draw(_sp);
                _window.draw(_leftPanel);
                _window.draw(_bottomPanel);
                _window.draw(_text1);
                _window.draw(_text2);
                _window.draw(_sceneText);
                _window.draw(avancmentText);
                for (auto& but_ : _leftPanelButton)
                    but_.draw(&_window);
                break;
        }
        _window.display();
    });
}
