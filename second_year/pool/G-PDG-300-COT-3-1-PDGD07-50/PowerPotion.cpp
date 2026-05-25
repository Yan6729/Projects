/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** PowerPotion
*/

#include "PowerPotion.hpp"
#include "ICharacter.hpp"

PowerPotion::PowerPotion()
{
}

PowerPotion::~PowerPotion()
{
}

int PowerPotion::apply(ICharacter& character) const
{
    character.addPower(50);
    return 0;
}
