/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** PoisonPotion
*/

#include "PoisonPotion.hpp"
#include "ICharacter.hpp"

PoisonPotion::PoisonPotion() {}

PoisonPotion::~PoisonPotion() {}

int PoisonPotion::apply(ICharacter& character) const
{
    character.addHp(-50);
    return 0;
}

