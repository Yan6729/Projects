/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Operand
*/

#include "IOperand.hpp"

std::ostream& operator<<(std::ostream& redirect, const IOperand& object)
{
    redirect << object.toString();
    return redirect;
}
