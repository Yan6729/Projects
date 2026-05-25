/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** IComponent
*/

#include "../include/IComponent.hpp"

ostream& operator<<(ostream& s, nts::Tristate v)
{
    switch (v) {
        case nts::Tristate::Undefined:
            s << "U";
            return s;
        case nts::Tristate::True:
            s << true;
            return s;
        case nts::Tristate::False:
            s << false;
            return s;
        case nts::Tristate::Void:
            s << "U";
            return s;
        default:
            s << "U";
            return s;
    }
}

nts::Tristate nts::operator&&(const nts::Tristate& one, const nts::Tristate& two)
{
    if (one == nts::Tristate::False || two == nts::Tristate::False)
        return nts::Tristate::False;
    if (one == nts::Tristate::True && two == nts::Tristate::True)
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}

nts::Tristate nts::operator||(const nts::Tristate& one, const nts::Tristate& two)
{
    if (one == nts::Tristate::True || two == nts::Tristate::True)
        return nts::Tristate::True;
    if (one == nts::Tristate::False)
        return two;
    return nts::Tristate::Undefined;
}

nts::Tristate nts::operator^(const nts::Tristate& one, const nts::Tristate& two)
{
    if (one == nts::Tristate::Undefined || two == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    if (one == two)
        return nts::Tristate::False;
    return nts::Tristate::True;
}

nts::Tristate nts::operator!(const nts::Tristate& value)
{
    if (value == nts::Tristate::False)
        return nts::Tristate::True;
    if (value == nts::Tristate::True)
        return nts::Tristate::False;
    return nts::Tristate::Undefined;
}
