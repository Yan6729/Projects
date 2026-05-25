/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Lemon
*/

#include "Lemon.hpp"

Lemon::Lemon() : ACitrus("lemon", 4)
{}

Lemon::~Lemon()
{
}

IFruit *Lemon::clone() const
{
    return new Lemon();
}
