/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** centipedeGame
*/

#include "../../include/games/centipedeGame.hpp"
using namespace Arcade;

centipedeGame::centipedeGame() : _name("Centipede")
{}

centipedeGame::~centipedeGame()
{}

void centipedeGame::init()
{
    this->_score = 0;
    this->_isGameOver = false;
}

void centipedeGame::close()
{
    this->_score = 0;
    this->_isGameOver = false;
    this->_entities.clear();
}

const string &centipedeGame::getName() const
{
    return this->_name;
}

void centipedeGame::update()
{}

vector<Entity> centipedeGame::getEntities() const
{
    return this->_entities;
}

void centipedeGame::handleEvent(Input event)
{}

int centipedeGame::getScore() const
{
    return this->_score;
}

bool centipedeGame::isGameOver()
{
    return this->_isGameOver;
}

size_t centipedeGame::getHeight() const
{
    return this->_h;
}

size_t centipedeGame::getWidth() const
{
    return this->_w;
}

extern "C" {
    Arcade::IGame *createGame(void) {
        return new Arcade::centipedeGame();
    }
}