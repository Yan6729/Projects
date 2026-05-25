/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** ABerry
*/

#include "ABerry.hpp"

ABerry::ABerry(const std::string& name, unsigned int vitamins) : AFruit()
{
    this->_name = name;
    this->_vitamins = vitamins;
    this->setType("ABerry");
    this->setIsPelled(true);
}

ABerry::~ABerry()
{}
