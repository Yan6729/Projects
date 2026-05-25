/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string& name, int power) : Peasant(name, power), Enchanter(name, power)
{
    std::cout << this->getName() << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << this->getName() << " finds peace." << std::endl;
}

void Priest::rest(void)
{
    if (this->getHp() == 0) {
        std::cout << this->getName() << " is out of combat." << std::endl;
    } else {
        this->addHp(100);
        this->addPower(100);
        std::cout << this->getName() << " prays." << std::endl;
    }
}
