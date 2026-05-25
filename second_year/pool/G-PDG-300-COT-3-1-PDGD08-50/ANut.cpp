/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** ANut
*/

#include "ANut.hpp"

ANut::ANut(const std::string& name, unsigned int vitamins) : AFruit()
{
    this->_name = name;
    this->_vitamins = vitamins;
    this->setType("ANut");
}

ANut::~ANut()
{
}
