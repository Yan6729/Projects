/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** minesweeperGame
*/

#include "../../include/games/minesweeperGame.hpp"
using namespace Arcade;

minesweeperGame::minesweeperGame() : _name("MinesWeeper")
{}

minesweeperGame::~minesweeperGame()
{}

void minesweeperGame::init()
{
    this->_score = 0;
    this->_isGameOver = false;
}

void minesweeperGame::close()
{
    this->_score = 0;
    this->_isGameOver = false;
    this->_entities.clear();
}

const string &minesweeperGame::getName() const
{
    return this->_name;
}

void minesweeperGame::update()
{}

vector<Entity> minesweeperGame::getEntities() const
{
    return this->_entities;
}

void minesweeperGame::handleEvent(Input event)
{}

int minesweeperGame::getScore() const
{
    return this->_score;
}

bool minesweeperGame::isGameOver()
{
    return this->_isGameOver;
}

size_t minesweeperGame::getHeight() const
{
    return this->_h;
}

size_t minesweeperGame::getWidth() const
{
    return this->_w;
}

extern "C" {
    Arcade::IGame *createGame(void) {
        return new Arcade::minesweeperGame();
    }
}
