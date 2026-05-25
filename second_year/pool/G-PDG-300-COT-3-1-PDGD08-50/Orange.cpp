/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Orange
*/

#include "Orange.hpp"

Orange::Orange() : ACitrus("orange", 7)
{}

Orange::~Orange()
{
}

IFruit *Orange::clone() const
{
    return new Orange();
}
