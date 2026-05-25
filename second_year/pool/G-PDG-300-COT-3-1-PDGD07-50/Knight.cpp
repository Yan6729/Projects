/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Knight
*/

#include "Knight.hpp"

Knight::Knight(const std::string& name, int power) : Peasant(name, power)
{
    std::cout << this->getName() << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << this->getName() << " takes off his armor." << std::endl;
}

int Knight::attack(void)
{
    if ((this->getHp() == 0)) {
        std::cout << this->getName() << " is out of combat." << std::endl;
        return 0;
    }
    if ((this->getPower() - 10) < 0) {
        std::cout << this->getName() << " is out of power." << std::endl;
        return 0;
    } else {
        this->addPower(-10);
        std::cout << this->getName() << " strikes with his sword." << std::endl;
        return 20;
    }
}

int Knight::special(void)
{
    if ((this->getHp() == 0)) {
        std::cout << this->getName() << " is out of combat." << std::endl;
        return 0;
    }
    if ((this->getPower() - 30) < 0) {
        std::cout << this->getName() << " is out of power." << std::endl;
        return 0;
    } else {
        this->addPower(-30);
        std::cout << this->getName() << " impales his enemy." << std::endl;
        return 50;
    }
}

void Knight::rest(void)
{
    if (this->getHp() == 0) {
        std::cout << this->getName() << " is out of combat." << std::endl;
    } else {
        this->addPower(50);
        std::cout << this->getName() << " eats." << std::endl;
    }
}
