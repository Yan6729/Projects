/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Grapefruit
*/

#include "Grapefruit.hpp"

Grapefruit::Grapefruit() : ACitrus("grapefruit", 5)
{}

Grapefruit::~Grapefruit()
{
}

IFruit *Grapefruit::clone() const
{
    return new Grapefruit();
}