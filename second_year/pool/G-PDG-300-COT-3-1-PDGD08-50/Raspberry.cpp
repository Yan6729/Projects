/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Raspberry
*/

#include "Raspberry.hpp"

Raspberry::Raspberry() : ABerry("raspberry", 5)
{}

Raspberry::~Raspberry()
{
}

IFruit *Raspberry::clone() const
{
    return new Raspberry();
}
