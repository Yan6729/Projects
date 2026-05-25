/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** snakeGame
*/

#include "../../include/games/snakeGame.hpp"
using namespace Arcade;

snakeGame::snakeGame() : _name("Snake")
{}

snakeGame::~snakeGame()
{}

void snakeGame::init()
{
    this->_h = 41;
    this->_w = 40;
    this->_score = 0;
    this->_isGameOver = false;
    this->_direction = "down";
    for (int a = 0; a < (int)_h; a++)
        for (int b = 0; b < (int)_w; b++)
            _entities.push_back({ b, a, ' ', Color::BLACK, getGrassAssets(_h, _w, b, a)});

    Entity _bonus = {
        -1,
        -1,
        'b',
        Color::YELLOW,
        "asset/picture/goal/snake_food_0.png"
    };
    for (int a = 1; a < 22; a++) {
        this->foods.push_back("asset/picture/goal/snake_food_" + to_string(a) + ".png");
    }
    auto _p = spawnFood(_entities, _h, _w);
    this->_entities.push_back({ _p.first, _p.second, 'a', Color::RED, "asset/picture/goal/snake_food_1.png" });
    this->_entities.push_back({_bonus});
    this->_entities.push_back({ 30, 20, '0', Color::GREEN, "asset/picture/snake/tile002.png"});
    this->_entities.push_back({ 30, 19, '0', Color::WHITE, "asset/picture/snake/horizontal.png"});
    this->_entities.push_back({ 30, 18, '0', Color::WHITE, "asset/picture/snake/horizontal.png"});
    this->_entities.push_back({ 30, 17, '0', Color::WHITE, "asset/picture/snake/tail_up.png"});
    this->_timer = 0;
    _assets["up"] = "asset/picture/snake/tile000.png";
    _assets["down"] = "asset/picture/snake/tile002.png";
    _assets["left"] = "asset/picture/snake/tile003.png";
    _assets["right"] = "asset/picture/snake/tile001.png";
}

void snakeGame::close()
{
    this->_score = 0;
    this->_isGameOver = false;
    this->_entities.clear();
    this->_direction.clear();
}

const string &snakeGame::getName() const
{
    return this->_name;
}

size_t snakeGame::getEntity(char symbol, Color color)
{
    for (size_t a = 0; a < _entities.size(); a++) {
        if (_entities[a].symbol == symbol && _entities[a].color == color)
            return a;
    }
    return 0;
}

void snakeGame::update()
{
    this_thread::sleep_for(chrono::milliseconds(DEFAULT_TICK));
    if (_isGameOver)
        return;
    size_t index = getEntity('0', Color::GREEN);
    pair<int, int> last_pos = {_entities[index].x, _entities[index].y};
    pair<int, int> temp;

    _timer += 1;
    if (_timer == 200) {
        auto p = spawnFood(_entities, _h, _w);
        _entities[index - 1].x = p.first;
        _entities[index - 1].y = p.second;
        _timer = 0;
    }
    for (size_t i = index + 1; i < _entities.size(); i++) {
        temp = {_entities[i].x, _entities[i].y};
        _entities[i].x = last_pos.first;
        _entities[i].y = last_pos.second;
        last_pos = temp;
    }
    move_head(_entities[index].x, _entities[index].y, _direction);
    _entities[index].sprite = _assets[_direction];
    for (size_t i = index + 1; i < _entities.size() - 1; i++) {
        auto &prev = _entities[i - 1];
        auto &curr = _entities[i];
        auto &next = _entities[i + 1];
        curr.sprite = getAssets({prev.x, prev.y}, {curr.x, curr.y}, {next.x, next.y});
    }
    if (_entities[index - 2].x == _entities[index].x &&
        _entities[index - 2].y == _entities[index].y) {
        Entity newPart = {
            _entities.back().x,
            _entities.back().y,
            '0',
            Color::WHITE,
            ""
        };
        _entities.push_back(newPart);
        auto _p = spawnFood(_entities, _h, _w);
        _entities[index - 2].x = _p.first;
        _entities[index - 2].y = _p.second;
        _entities[index - 2].sprite = foods[rand() % foods.size()];
        _score += 10;
    } else if (_entities[index - 1].x == _entities[index].x &&
        _entities[index - 1].y == _entities[index].y) {
            Entity newPart = {
            _entities.back().x,
            _entities.back().y,
            '0',
            Color::WHITE,
            ""
        };
        _entities.push_back(newPart);
        _entities.push_back(newPart);
        _entities[index - 1].x = -1;
        _entities[index - 1].y = -1;
        _score += 20;

    }
    getTailAssetsByState(_entities);
}

vector<Entity> snakeGame::getEntities() const
{
    return this->_entities;
}

void snakeGame::handleEvent(Input event)
{
    if (_isGameOver == false) {
        switch (event) {
            case Input::UP:
                if (this->_direction != "down")
                    this->_direction = "up";
                break;
            case Input::DOWN:
                if (this->_direction != "up")
                    this->_direction = "down";
                break;
            case Input::LEFT:
                if (this->_direction != "right")
                    this->_direction = "left";
                break;
            case Input::RIGHT:
                if (this->_direction != "left")
                    this->_direction = "right";
                break;
            default:
                break;
        }
    }
}

int snakeGame::getScore() const
{
    return this->_score;
}

bool snakeGame::isGameOver()
{
    size_t index = getEntity('0', Color::GREEN);
    for (size_t a = index + 1; a < _entities.size(); a++) {
        if ((_entities[index].x == _entities[a].x) && (_entities[index].y == _entities[a].y)) {
            this->_isGameOver = true;
            break;
        }
    }
    if (_entities[index].x >= (int)_w ||
        _entities[index].y >= (int)_h ||
        _entities[index].x < 0 ||
        _entities[index].y < 0)
    {
        this->_isGameOver = true;
    }
    return this->_isGameOver;
}

size_t snakeGame::getHeight() const
{
    return this->_h;
}

size_t snakeGame::getWidth() const
{
    return this->_w;
}

extern "C" {
    Arcade::IGame *createGame(void) {
        return new Arcade::snakeGame();
    }

    void destroyGame(Arcade::IGame *game) {
        delete game;
    }
}
