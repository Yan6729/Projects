/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** solarFoxGame
*/

#include "../../include/games/slorFoxGame.hpp"
using namespace Arcade;

solarFoxGame::solarFoxGame() : _name("Qix")
{}

solarFoxGame::~solarFoxGame()
{}

void solarFoxGame::init()
{
    this->_score = 0;
    this->_isGameOver = false;
}

void solarFoxGame::close()
{
    this->_score = 0;
    this->_isGameOver = false;
    this->_entities.clear();
}

const string &solarFoxGame::getName() const
{
    return this->_name;
}

void solarFoxGame::update()
{}

vector<Entity> solarFoxGame::getEntities() const
{
    return this->_entities;
}

void solarFoxGame::handleEvent(Input event)
{}

int solarFoxGame::getScore() const
{
    return this->_score;
}

bool solarFoxGame::isGameOver()
{
    return this->_isGameOver;
}

size_t solarFoxGame::getHeight() const
{
    return this->_h;
}

size_t solarFoxGame::getWidth() const
{
    return this->_w;
}

extern "C" {
    Arcade::IGame *createGame(void) {
        return new Arcade::solarFoxGame();
    }
}