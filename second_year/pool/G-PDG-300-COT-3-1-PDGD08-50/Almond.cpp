/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Almond
*/

#include "Almond.hpp"

Almond::Almond() : AFruit(), ANut("almond", 2)
{}

Almond::~Almond()
{}

IFruit *Almond::clone() const
{
    return new Almond();
}