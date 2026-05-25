/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** pacmanGame
*/

#include "../../include/games/pacmanGame.hpp"
using namespace Arcade;

pacmanGame::pacmanGame() : _name("Pacman")
{}

pacmanGame::~pacmanGame()
{}

void pacmanGame::init()
{
    this->_h = 41;
    this->_w = 41;
    this->_score = 0;
    this->_isGameOver = false;
    this->blink = 0;
    int count = 0;
    this->_generator->init(_h, _w, 5, 5);
    this->_generator->generate();
    this->change = 0;
    this->_direction = "right";
    this->change_ghost = 0;
    this->_eatghost = false;
    this->time = 0;
    int var = 0;
    lost = 0;

    for (int a = 1; a < 3; a++)
        this->_dead.push_back("asset/picture/pac-man/dead_" + to_string(a) + ".png");
    for (int a = 1; a < 25; a++) {
        if (a < 7)
            this->pacman_assets["right"].push_back("asset/picture/pac-man/pacman" + to_string(a) + ".png");
        else if (a < 13)
            this->pacman_assets["up"].push_back("asset/picture/pac-man/pacman" + to_string(a) + ".png");
        else if (a < 19)
            this->pacman_assets["left"].push_back("asset/picture/pac-man/pacman" + to_string(a) + ".png");
        else
            this->pacman_assets["down"].push_back("asset/picture/pac-man/pacman" + to_string(a) + ".png");
    }
    for (int b = 1; b < 6; b++)
        this->ghost_asstes["red"].push_back("asset/picture/ghosts/red_ghost_" + to_string(b) + ".png");
    for (int b = 1; b < 6; b++)
        this->ghost_asstes["pink"].push_back("asset/picture/ghosts/pinky_ghost_" + to_string(b) + ".png");
    for (int b = 1; b < 6; b++)
        this->ghost_asstes["blue"].push_back("asset/picture/ghosts/blue_ghost_" + to_string(b) + ".png");
    for (int b = 1; b < 6; b++)
        this->ghost_asstes["orange"].push_back("asset/picture/ghosts/orange_ghost_" + to_string(b) + ".png");
    for (int b = 1; b < 3; b++)
        this->ghost_asstes["affraid"].push_back("asset/picture/ghosts/affraid_" + to_string(b) + ".png");
    for (int b = 1; b < 4; b++)
        this->ghost_asstes["blink"].push_back("asset/picture/ghosts/blink_" + to_string(b) + ".png");
    vector<string> map = this->_generator->getMaze();
    for (int h = 0; h < (int)_h; h++) {
        for (int w = 0; w < (int)_w; w++) {
            var++;
            if (map[h][w] == '#') {
                this->_entities.push_back({ w, h, '#', Color::DARK_CYAN, ""});
            } else if (map[h][w] == '.') {
                this->_entities.push_back(choosePiece(var, w, h));
            } else if (map[h][w] == ' ') {
                this->_entities.push_back({ w, h, ' ', Color::BLACK, ""});
            } else if (map[h][w] == '_') {
                this->_entities.push_back({ w, h, '_', Color::GRAY, "" });
            }
        }
    }
    for (int h = 0; h < (int)_h; h++) {
        for (int w = 0; w < (int)_w; w++) {
            if (map[h][w] == 'E') {
                if (count == 0)
                    this->_entities.push_back({ w, h, 'E', Color::BLUE, ghost_asstes["blue"][0]});
                else if (count == 1)
                    this->_entities.push_back({ w, h, 'E', Color::ORANGE, ghost_asstes["orange"][0]});
                else if (count == 2)
                    this->_entities.push_back({ w, h, 'E', Color::PINK, ghost_asstes["pink"][0]});
                else
                    this->_entities.push_back({ w, h, 'E', Color::RED, ghost_asstes["red"][0]});
                count += 1;
            }
        }
    }
    this->_entities.push_back({ 0, 1, 'G', Color::YELLOW, pacman_assets["right"][0]});
    _ghosts = {
        { Color::BLUE, "inky", "", false, getEntity('E', Color::BLUE), {_entities[getEntity('E', Color::BLUE)].x, _entities[getEntity('E', Color::BLUE)].y}, 0 },
        { Color::PINK, "pinky", "", false, getEntity('E', Color::PINK), {_entities[getEntity('E', Color::PINK)].x, _entities[getEntity('E', Color::PINK)].y}, 0 },
        { Color::RED, "blinky", "", false, getEntity('E', Color::RED), {_entities[getEntity('E', Color::RED)].x, _entities[getEntity('E', Color::RED)].y}, 0 },
        { Color::ORANGE, "clyde", "", false, getEntity('E', Color::ORANGE), {_entities[getEntity('E', Color::ORANGE)].x, _entities[getEntity('E', Color::ORANGE)].y}, 0 }
    };
}

bool pacmanGame::canBeCrossed(pair<int, int> coord)
{
    for (size_t a = 1; a < _entities.size(); a++) {
        if (_entities[a].x == coord.first && _entities[a].y == coord.second) {
            if (_entities[a].symbol == '.') {
                this->_score += 2;
                _entities[a].symbol = ' ';
                _entities[a].sprite = "";
                _entities[a].color = Color::BLACK;
                return true;
            } else if (_entities[a].symbol == 'o') {
                this->_score += 2;
                _eatghost = true;
                _entities[a].symbol = ' ';
                _entities[a].sprite = "";
                time = 0;
                _entities[a].color = Color::BLACK;
                return true;
            } else {
                if (_entities[a].symbol == ' ')
                    return true;
                return false;
            }
        }
    }
    return true;
}

void pacmanGame::close()
{
    this->_score = 0;
    this->_isGameOver = false;
    this->_entities.clear();
}

const string &pacmanGame::getName() const
{
    return this->_name;
}

void pacmanGame::update()
{
    int index = this->getEntity('G', Color::YELLOW);

    this_thread::sleep_for(chrono::milliseconds(DEFAULT_TICK));

    if (change == 6)
        change = 0;

    if (_direction == "up") {
        if (this->canBeCrossed({ this->_entities[index].x, this->_entities[index].y - 1 }) == true) {
            if (this->_entities[index].y - 1 < 0)
                this->_entities[index].y = _h;
            else
                this->_entities[index].y -= 1;
            _entities[index].sprite = pacman_assets[_direction][change];
            change += 1;
        }
    } else if (_direction == "down") {
        if (this->canBeCrossed({ this->_entities[index].x, this->_entities[index].y + 1 }) == true) {
            if (this->_entities[index].y + 1 >= (int)_h)
                this->_entities[index].y = 0;
            else
                this->_entities[index].y += 1;
            _entities[index].sprite = pacman_assets[_direction][change];
            change += 1;
        }
    } else if (_direction == "left") {
        if (this->canBeCrossed({ this->_entities[index].x - 1, this->_entities[index].y }) == true) {
            if (this->_entities[index].x - 1 < 0)
                this->_entities[index].x = _w;
            else
               this->_entities[index].x -= 1;
            _entities[index].sprite = pacman_assets[_direction][change];
            change += 1;
        }
    } else if (_direction == "right") {
        if (this->canBeCrossed({ this->_entities[index].x + 1, this->_entities[index].y }) == true) {
            if (this->_entities[index].x + 1 >= (int)_w)
                this->_entities[index].x = 0;
            else
                this->_entities[index].x += 1;
            _entities[index].sprite = pacman_assets[_direction][change];
            change += 1;
        }
    };
    moveGhosts();

    if (_eatghost == false) {
        if (change_ghost >= 5)
            change_ghost = 0;
        _entities[getEntity('E', Color::PINK)].sprite = ghost_asstes["pink"][change_ghost];
        _entities[getEntity('E', Color::RED)].sprite = ghost_asstes["red"][change_ghost];
        _entities[getEntity('E', Color::BLUE)].sprite = ghost_asstes["blue"][change_ghost];
        _entities[getEntity('E', Color::ORANGE)].sprite = ghost_asstes["orange"][change_ghost];
        change_ghost += 1;
    }
    if (_eatghost == true) {
        int affraid = 0;
        if (affraid == 2)
            affraid = 0;
        if (blink == 3)
            blink = 0;
        for (int a = 0; a < 4; a++)
            _entities[_ghosts[a]._entityIdx].sprite = ghost_asstes["affraid"][affraid];
        if (time >= 100) {
            if ((10 - (time / 10)) % 2 == 0) {
                for (int a = 0; a < 4; a++)
                    _entities[_ghosts[a]._entityIdx].sprite = ghost_asstes["affraid"][affraid];
            } else {
                for (int a = 0; a < 4; a++)
                    _entities[_ghosts[a]._entityIdx].sprite = ghost_asstes["blink"][blink];
            }
        }
        eatGhost();
        time += 1;
        affraid += 1;
        blink += 1;
    }
    if (time == 151) {
        _eatghost = false;
        time = 0;
    }
}

void pacmanGame::eatGhost()
{
    int pacman = getEntity('G', Color::YELLOW);
    for (auto& g : _ghosts) {
        auto& entity = _entities[g._entityIdx];
        if (entity.x == _entities[pacman].x &&
        entity.y == _entities[pacman].y)
        {
            this->_score += 100;
            g._hasLeft = false;
            g._prevDir = "";
            entity.x = g.origin.x;
            entity.y = g.origin.y;
        }
    }
}

vector<Entity> pacmanGame::getEntities() const
{
    return this->_entities;
}

size_t pacmanGame::getEntity(char symbol, Color color)
{
    for (size_t a = 0; a < _entities.size(); a++) {
        if (_entities[a].symbol == symbol && _entities[a].color == color) {
            return a;
        }
    }
    return 0;
}

void pacmanGame::handleEvent(Input event)
{
    int index = this->getEntity('G', Color::YELLOW);
    switch(event) {
        case Input::UP:
            if (this->canBeCrossed({ this->_entities[index].x, this->_entities[index].y - 1 }) == true) {
                _direction = "up";
            }
            break;
        case Input::DOWN:
            if (this->canBeCrossed({ this->_entities[index].x, this->_entities[index].y + 1 }) == true) {
                _direction = "down";
            }
            break;

        case Input::LEFT:
            if (this->canBeCrossed({ this->_entities[index].x - 1, this->_entities[index].y }) == true) {
                _direction = "left";
            }
            break;
        case Input::RIGHT:
            if (this->canBeCrossed({ this->_entities[index].x + 1, this->_entities[index].y }) == true) {
                _direction = "right";
            }
            break;
        default:
            break;
    }
}

int pacmanGame::getScore() const
{
    return this->_score;
}

bool pacmanGame::isGameOver()
{
    return this->_isGameOver;
}

size_t pacmanGame::getHeight() const
{
    return this->_h;
}

size_t pacmanGame::getWidth() const
{
    return this->_w;
}

extern "C" {
    Arcade::IGame *createGame(void) {
        return new Arcade::pacmanGame();
    }

    void destroyGame(Arcade::IGame *game) {
        delete game;
    }
}
