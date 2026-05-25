/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** nibblerGame
*/

#include "../../include/games/nibblerGame.hpp"
using namespace Arcade;

nibblerGame::nibblerGame() : _name("Nibbler")
{}

nibblerGame::~nibblerGame()
{}

void nibblerGame::init()
{
    this->_score = 0;
    this->_isGameOver = false;
    this->_direction = "right";
    this->_h = 41;
    this->_w = 40;
    this->reverse = true;
    this->_timer = 0;
    this->_first = 1;
    this->_second = 8;
    this->_last = 0;
    for (size_t a = 0; a < 10; a++)
        this->numbers.push_back("asset/picture/timer/number/" + to_string(a) + ".png");
    this->_entities.push_back({ int(_w / 2) - 5, (int)_h + 1, 'T', Color::WHITE, "asset/picture/timer/letter/T.png" });
    this->_entities.push_back({ int(_w / 2) - 4, (int)_h + 1, 'I', Color::WHITE, "asset/picture/timer/letter/I.png" });
    this->_entities.push_back({ int(_w / 2) - 3, (int)_h + 1, 'M', Color::WHITE, "asset/picture/timer/letter/M.png" });
    this->_entities.push_back({ int(_w / 2) - 2, (int)_h + 1, 'E', Color::WHITE, "asset/picture/timer/letter/E.png" });
    this->_entities.push_back({ int(_w / 2) - 1, (int)_h + 1, 'R', Color::WHITE, "asset/picture/timer/letter/R.png" });
    this->_entities.push_back({ int(_w / 2) + 1, (int)_h + 1, ':', Color::WHITE, "asset/picture/timer/deux_points.png" });
    this->_entities.push_back({ int(_w / 2) + 3, (int)_h + 1, '1', Color::WHITE, numbers[_first] });
    this->_entities.push_back({ int(_w / 2) + 4, (int)_h + 1, '8', Color::WHITE, numbers[_second] });
    this->_entities.push_back({ int(_w / 2) + 5, (int)_h + 1, '0', Color::WHITE, numbers[_last] });
    _generator->init(_h, _w);
    _generator->carvePath(1, 1);
    _generator->removeDeadEnds();
    _generator->applySymmetry();
    _generator->removeDeadEnds();
    vector<string> map = _generator->getMaze();
    map[1][0] = ' ';
    for (int a = 1; a < 22; a++) {
        this->foods.push_back("asset/picture/goal/snake_food_" + to_string(a) + ".png");
    }
    for (int h = 0; h < (int)_h; h++) {
        for (int w = 0; w < (int)_w; w++) {
            if (map[h][w] == '#') {
                _entities.push_back({ w, h, '#', Color::GRAY, "asset/picture/background/tile002.png"});
            } else {
                _entities.push_back({ w, h, ' ', Color::BLACK, ""});
            }
        }
    }
    for (size_t a = 0; a < (_h * _w) / (_h + _w); a++) {
        auto _p = spawnFood(_entities, _h, _w);
        _entities.push_back({
            _p.first,
            _p.second,
            '@',
            Color::RED,
            foods[(rand() % 20) + 1]
        });
    }
    this->_entities.push_back({ 0, 1, '0', Color::GREEN, "asset/picture/snake/tile001.png"});
    this->_entities.push_back({ -1, 1, '0', Color::WHITE, ""});
    this->_entities.push_back({ -2, 1, '0', Color::WHITE, ""});
    this->_entities.push_back({ -3, 1, '0', Color::WHITE, ""});
    _assets["up"] = "asset/picture/snake/tile000.png";
    _assets["down"] = "asset/picture/snake/tile002.png";
    _assets["left"] = "asset/picture/snake/tile003.png";
    _assets["right"] = "asset/picture/snake/tile001.png";
}

void nibblerGame::close()
{
    this->_score = 0;
    this->_isGameOver = false;
    this->_entities.clear();
    this->_direction.clear();
}

const string &nibblerGame::getName() const
{
    return this->_name;
}

void nibblerGame::update()
{
    this_thread::sleep_for(chrono::milliseconds(DEFAULT_TICK));
    size_t index = getEntity('0', Color::GREEN);
    pair<int, int> last_pos = {this->_entities[index].x, this->_entities[index].y};
    pair<int, int> temp = {0, 0};
    
    if (_isGameOver == true)
        return;

    bool body_move = false;
    _entities[index].sprite = _assets[_direction];
    _direction == "up" ? ({
        if (this->canBeCrossed({ this->_entities[index].x, this->_entities[index].y - 1 })) {
            if (this->_entities[index].y - 1 < 0)
                this->_entities[index].y = _h + 1;
            else
                this->_entities[index].y -= 1;
            body_move = true;
        }
    }) : _direction == "down" ? ({
        if (this->canBeCrossed({ this->_entities[index].x, this->_entities[index].y + 1 }) == true) {
            if (this->_entities[index].y + 1 >= (int)_h)
                this->_entities[index].y = -1;
            else
                this->_entities[index].y += 1;
            body_move = true;
        }
    }) : _direction == "left" ? ({
        if (this->canBeCrossed({ this->_entities[index].x - 1, this->_entities[index].y }) == true) {
            if (this->_entities[index].x - 1 < 0)
                this->_entities[index].x = _w + 1;
            else
               this->_entities[index].x -= 1;
            body_move = true;
        }
    }) : ({
        if (this->canBeCrossed({ this->_entities[index].x + 1, this->_entities[index].y }) == true) {
            if (this->_entities[index].x + 1 >= (int)_w)
                this->_entities[index].x = -1;
            else
                this->_entities[index].x += 1;
            body_move = true;
        }
    });

    if (body_move == true) {
        for (size_t tail = index + 1; tail < _entities.size(); tail++) {
            temp = { _entities[tail].x, _entities[tail].y };
            _entities[tail].x = last_pos.first;
            _entities[tail].y = last_pos.second;
            last_pos = temp;
        }
        body_move = false;
    }
    for (size_t i = index + 1; i < _entities.size() - 1; i++) {
        auto &prev = _entities[i - 1];
        auto &curr = _entities[i];
        auto &next = _entities[i + 1];
        curr.sprite = getAssets({prev.x, prev.y}, {curr.x, curr.y}, {next.x, next.y});
    }

    int first = getEntity('@', Color::RED);
    for (size_t a = first; a < index; a++) {
        if ((_entities[a].symbol == '@') && (_entities[a].x == _entities[index].x) && (_entities[a].y == _entities[index].y)) {
            Entity _tailblock = { _entities.back().x, _entities.back().y, '0', Color::WHITE, ""};
            _entities.push_back(_tailblock);
            _entities.erase(_entities.begin() + a);
            this->_score += 10;
            break;
        }
    }
    getTailAssetsByState(_entities);
    _timer += 1;
    if (_timer == 10) {
        _last -= 1;
        if (_last == -1) {
            _second -= 1;
            _last = 9;
            if (_second == -1) {
                _first -= 1;
                _second = 8;
                if (_first == -1) {
                    _first = 0;
                    _last = 0;
                    _second = 0;
                }
            }
        }
        _timer = 0;
    }
    this->_entities[6].symbol = _first + 48;
    this->_entities[7].symbol = _second + 48;
    this->_entities[8].symbol = _last + 48;
    this->_entities[6].sprite = numbers[_first];
    this->_entities[7].sprite = numbers[_second];
    this->_entities[8].sprite = numbers[_last];
}

vector<Entity> nibblerGame::getEntities() const
{
    return this->_entities;
}

bool nibblerGame::canBeCrossed(pair<int, int> coord)
{
    for (size_t a = 1; a < _entities.size(); a++) {
        if (_entities[a].x == coord.first && _entities[a].y == coord.second) {
            if (_entities[a].symbol != '#') {
                return true;
            } else {
                return false;
            }
        }
    }
    return true;

}

void nibblerGame::handleEvent(Input event)
{
    if (_isGameOver == false) {
        switch (event) {
            case Input::UP:
                if (this->_direction == "down")
                    reverse = true;
                this->_direction = "up";
                break;
            case Input::DOWN:
                if (this->_direction == "up")
                    reverse = true;
                this->_direction = "down";
                break;
            case Input::LEFT:
                if (this->_direction == "right")
                    reverse = true;
                this->_direction = "left";
                break;
            case Input::RIGHT:
                if (this->_direction == "left")
                    reverse = true;
                this->_direction = "right";
                break;
            default:
                break;
        }
    }
}

int nibblerGame::getScore() const
{
    return this->_score;
}

size_t nibblerGame::getEntity(char c, Color color)
{
    for (size_t a = 0; a < _entities.size(); a++) {
        if (_entities[a].symbol == c && _entities[a].color == color) {
            return a;
        }
    }
    return 0;
}

bool nibblerGame::isGameOver()
{
    if (reverse == true)
        return false;
    int index = getEntity('0', Color::GREEN);
    for (size_t a = index + 1; a < _entities.size(); a++) {
        if ((_entities[index].x == _entities[a].x) && (_entities[index].y == _entities[a].y)) {
            this->_isGameOver = true;
            break;
        }
    }
    if (_first == 0 && _second == 0 && _last == 0 && getEntity('@', Color::RED) != _entities.size() + 1) {
        this->_isGameOver = true;
        return true;
    }
    return this->_isGameOver;
}

size_t nibblerGame::getHeight(void) const
{
    return _h;
}

size_t nibblerGame::getWidth(void) const
{
    return _w;
}

extern "C" {
    Arcade::IGame *createGame(void) {
        return new Arcade::nibblerGame();
    }

    void destroyGame(Arcade::IGame *game) {
        delete game;
    }
}