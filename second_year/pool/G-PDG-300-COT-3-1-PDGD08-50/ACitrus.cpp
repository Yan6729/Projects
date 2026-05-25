/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** ACitrus
*/

#include "ACitrus.hpp"

ACitrus::ACitrus(const std::string& name, unsigned int vitamins) : AFruit()
{
    this->_name = name;
    this->_vitamins = vitamins;
    this->_type = "ACitrus";
}

ACitrus::~ACitrus()
{
}
