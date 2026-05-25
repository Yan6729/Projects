/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** HealthPotion
*/

#include "HealthPotion.hpp"
#include "ICharacter.hpp"

HealthPotion::HealthPotion()
{}

HealthPotion::~HealthPotion()
{}

int HealthPotion::apply(ICharacter& character) const
{
    character.addHp(50);
    return 0;
}