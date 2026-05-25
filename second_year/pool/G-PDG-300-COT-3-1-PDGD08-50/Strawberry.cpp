/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Strawberry
*/

#include "Strawberry.hpp"

Strawberry::Strawberry() : ABerry("strawberry", 6)
{}

Strawberry::~Strawberry()
{
}

IFruit *Strawberry::clone() const
{
    return new Strawberry();
}