/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** qixGame
*/

#include "../../include/games/qixGame.hpp"
using namespace Arcade;

qixGame::qixGame() : _name("Qix")
{}

qixGame::~qixGame()
{}

void qixGame::init()
{
    this->_score = 0;
    this->_isGameOver = false;
}

void qixGame::close()
{
    this->_score = 0;
    this->_isGameOver = false;
    this->_entities.clear();
}

const string &qixGame::getName() const
{
    return this->_name;
}

void qixGame::update()
{}

vector<Entity> qixGame::getEntities() const
{
    return this->_entities;
}

void qixGame::handleEvent(Input event)
{}

int qixGame::getScore() const
{
    return this->_score;
}

bool qixGame::isGameOver()
{
    return this->_isGameOver;
}

size_t qixGame::getHeight() const
{
    return this->_h;
}

size_t qixGame::getWidth() const
{
    return this->_w;
}

extern "C" {
    Arcade::IGame *createGame(void) {
        return new Arcade::qixGame();
    }
}