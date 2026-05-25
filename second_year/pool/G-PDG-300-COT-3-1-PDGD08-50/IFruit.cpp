/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** IFruit
*/

#include "IFruit.hpp"

IFruit::~IFruit()
{}

std::ostream& operator<<(std::ostream& redirect, const IFruit& fruit)
{
    redirect << "{ \"name\": \""
            << fruit.getName()
            << "\", \"vitamins\": "
            << fruit.getVitamins()
            << ", \"peeled\": "
            << (fruit.isPeeled() ? "true" : "false")
            << " }";
    return redirect;
}

