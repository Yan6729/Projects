/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Coconut
*/

#include "Coconut.hpp"

Coconut::Coconut() : ANut("coconut", 4)
{}

Coconut::~Coconut()
{
}

IFruit *Coconut::clone() const
{
    return new Coconut();
}
