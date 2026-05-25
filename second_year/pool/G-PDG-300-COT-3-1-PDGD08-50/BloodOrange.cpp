/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** BloodOrange
*/

#include "BloodOrange.hpp"

BloodOrange::BloodOrange() : ACitrus("blood orange", 6), Orange()
{
    this->setType("Orange");
}

BloodOrange::~BloodOrange()
{
}

IFruit *BloodOrange::clone() const
{
    return new BloodOrange();
}