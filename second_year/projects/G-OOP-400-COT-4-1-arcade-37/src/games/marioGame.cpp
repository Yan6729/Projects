/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** marioGame
*/

#include "../../include/games/marioGame.hpp"
const vector<string> _map = {
    "                                                                                              ",
    "          C C C                    C C C                           C C C                      ",
    "         C     C                  C     C                         C     C                     ",
    "          C C C                    C C C                           C C C                      ",
    "                                                                                              ",
    "                                                      o  o  o                                 ",
    "                                             Q                                                ",
    "                    o  o  o                                                                   ",
    "                  b  Q  b  Q  b              b  b  b                                          ",
    "                                                                                              ",
    "HM          o o o o            ]_            _[   o o o o                               F    H",
    "________________________________________^^^^^____________________T____________________________",
    "_________________________________________^^^__________________________________________________",
    "______________________________________________________________________________________________",
    "____________________________________------------------________________________________________",
    "_____________________---------------------Q--------------------_______________________________",
    "_____________________-----oooo-----------bbbbbb----------------]______________________________",
    "_____________________bbbbbbbbb---------bbbbbbb------bbbbbbb--_________________________________",
    "____________________-------------------------------------------_______________________________",
    "____________________-----------Qbbbb--------------------------________________________________",
    "_____________________------bbb-------bbbbbbb------------------________________________________",
    "_____________________[------------------T-----------o-o-o-o---________________________________",
    "______________________________________________________________________________________________",
    "______________________________________________________________________________________________",
};

using namespace Arcade;

marioGame::marioGame() : _name("mario")
{}

marioGame::~marioGame()
{}

void marioGame::init()
{
    this->_h = _map.size();
    this->_w = _map[0].length();
    this->_score = 0;
    this->_isGameOver = false;
    this->_cameraX = 0;
    this->_viewWidth = _map.size() + 1;
    this->_velocityY = 0.0f;
    this->_isJumping = false;
    this->_onGround  = false;
    this->_tubes.push_back(getElement(0, '['));
    this->_tubes.push_back(getElement(_tubes.back().first, '['));
    this->_tubes.push_back(getElement(0, ']'));
    this->_tubes.push_back(getElement(_tubes.back().first, ']'));

    for (int a = 0; a < (int)_h; a++)
        for (int b = 0; b < (int)_w; b++)
            if (_map[a][b] == 'M') {
                this->_marioX = b;
                this->_marioY = a;
            }
}
void marioGame::close()
{
    this->_score = 0;
    this->_isGameOver = false;
    this->_entities.clear();
}

const string &marioGame::getName() const
{
    return this->_name;
}

void marioGame::update()
{
}

pair<size_t, size_t> marioGame::getElement(size_t start, char symbol)
{
    for (size_t a = 0; a < _map.size(); a++) {
        for (size_t w = start; w < _map[0].size(); w++) {
            if (_map[a][w] == symbol) {
                return { w, a };
            }
        }
    }
    return { _map[0].size() + 1, _map.size() + 1 };
}

vector<Entity> marioGame::getEntities() const
{
    vector<Entity> visible;
    int startX = this->_cameraX;
    int endX   = this->_cameraX + this->_viewWidth;
    for (int a = 0; a < (int)_h; a++) {
        for (int b = startX; b < endX && b < (int)_w; b++) {
            char c = _map[a][b];
            int screenX = b - startX;
            if (c == '_')
                visible.push_back({screenX, a, '_', Color::BROWN,
                    "asset/picture/mario/wall_s/wall_2.png"});
            else if (c == 'b')
                visible.push_back({screenX, a, 'b', Color::ORANGE,
                    "asset/picture/mario/wall_s/wall_1.png"});
            else if (c == '-')
                visible.push_back({screenX, a, '-', Color::GRAY,
                    "asset/picture/mario/wall_s/wall_4.png"});
            else if (c == '^')
                visible.push_back({screenX, a, '^', Color::BLUE,
                    "asset/picture/mario/water.png"});
            else if (c == '[')
                visible.push_back({screenX, a, '[', Color::DARK_GREEN,
                    "asset/picture/mario/right_tupe.png"});
            else if (c == 'H') {
                a <= 10 ? visible.push_back({screenX, a, ' ', Color::LIGHT_BLUE, ""}) :
                visible.push_back({screenX, a, '-', Color::GRAY, "asset/picture/mario/wall_s/wall_4.png"});
                visible.push_back({screenX, a, 'H', Color::LIGHT_CYAN,
                    "asset/picture/mario/Castle.png"});
            } else if (c == ']')
                visible.push_back({screenX, a, ']', Color::DARK_GREEN,
                    "asset/picture/mario/left_tube.png"});
            else if (c == 'C') {
                visible.push_back({screenX, a, ' ', Color::LIGHT_BLUE, ""});
                visible.push_back({screenX, a, 'C', Color::WHITE,
                    "asset/picture/mario/cloud.png"});
            }
            else if (c == 'Q')
                visible.push_back({screenX, a, 'Q', Color::YELLOW,
                    "asset/picture/mario/wall_s/wall_5.png"});
            else if (c == 'o') {
                a <= 10 ? visible.push_back({screenX, a, ' ', Color::LIGHT_BLUE, ""}) :
                visible.push_back({screenX, a, '-', Color::GRAY, "asset/picture/mario/wall_s/wall_4.png"});
                visible.push_back({screenX, a, 'o', Color::YELLOW,
                    "asset/picture/mario/mario_piece.png"});
            } else
                visible.push_back({screenX, a, ' ', Color::LIGHT_BLUE, ""});
        }
    }
    int marioScreenX = this->_marioX - startX;
    if (marioScreenX >= 0 && marioScreenX < this->_viewWidth)
        visible.push_back({marioScreenX, this->_marioY, 'M', Color::RED,
            "asset/picture/mario/mario_move/small_1.png"});

    return visible;
}

bool marioGame::canBeCrossed()
{
    if (getElement(_marioX, ' ').first ==  _map[0].size() + 1 ) {
        return true;
    }
    return false;
}

void marioGame::handleEvent(Input event)
{
    switch(event) {
        case Input::UP:
            if (this->_onGround) {
                this->_velocityY = JUMP_FORCE;
                this->_isJumping = true;
                this->_onGround  = false;
            }
            break;
        case Input::RIGHT:
            if (canBeCrossed() == true) {
                this->_marioX += 1;
                if (this->_marioX > this->_cameraX + this->_viewWidth / 2)
                    this->_cameraX = this->_marioX - this->_viewWidth / 2;
            }
            break;
        case Input::LEFT:
            if (canBeCrossed() == true) {
                if (this->_marioX > 0)
                    this->_marioX -= 1;
                if (this->_marioX < this->_cameraX + this->_viewWidth / 2)
                    this->_cameraX = std::max(0, this->_marioX - this->_viewWidth / 2);
            }
            break;
        default:
            break;
    }
}

int marioGame::getScore() const
{
    return this->_score;
}

bool marioGame::isGameOver()
{
    return this->_isGameOver;
}

size_t marioGame::getHeight() const
{
    return this->_h;
}

size_t marioGame::getWidth() const
{
    return this->_viewWidth;
}

extern "C" {
    Arcade::IGame *createGame(void) {
        return new Arcade::marioGame();
    }

    void destroyGame(Arcade::IGame *game) {
        delete game;
    }
}
