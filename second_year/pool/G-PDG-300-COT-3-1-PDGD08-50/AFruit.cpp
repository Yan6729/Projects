/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** AFruit
*/

#include "AFruit.hpp"

AFruit::AFruit()
{}

AFruit::~AFruit()
{}

unsigned int AFruit::getVitamins(void) const
{
    if (_isPeeled == true)
        return _vitamins;
    return 0;
}

std::string AFruit::getName(void) const
{
    return _name;
}

bool AFruit::isPeeled(void) const
{
    return _isPeeled;
}

void AFruit::peel(void)
{
    _isPeeled = true;
}

void AFruit::setName(std::string name)
{
    _name = name;
}

void AFruit::setVitamins(unsigned int vitamins)
{
    _vitamins = vitamins;
}

void AFruit::setIsPelled(bool ispelled)
{
    _isPeeled = ispelled;
}

void AFruit::setType(std::string type)
{
    _type = type;
}

std::string AFruit::getType(void) const
{
    return _type;
}

IFruit* AFruit::clone() const
{
    return new AFruit;
}
