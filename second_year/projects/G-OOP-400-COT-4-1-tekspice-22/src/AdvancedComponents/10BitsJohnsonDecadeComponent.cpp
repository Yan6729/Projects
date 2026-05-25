/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** TenBitsJohnsonDecadeComponent
*/

#include "../../include/AdvancedComponents/10BitsJohnsonDecadeComponent.hpp"
using namespace nts;

TenBJDComponent::TenBJDComponent()
{}

TenBJDComponent::~TenBJDComponent()
{}

void TenBJDComponent::simulate(std::size_t tick)
{
    if (_lastTick == tick)
        return;

    _lastTick = tick;

    Tristate cp0 = getLink(14);
    Tristate cp1 = getLink(13);
    Tristate reset = getLink(15);

    if (reset == True) {
        _current = 0;
    }
    else {
        if (_lastCP0 == False && cp0 == True && cp1 == False) {
            _current++;
        } else if (_lastCP1 == True && cp1 == False && cp0 == True) {
            _current++;
        }
        if (_current >= 10)
            _current = 0;
    }
    _lastCP0 = cp0;
    _lastCP1 = cp1;
}

Tristate TenBJDComponent::compute(std::size_t pin)
{
    switch (pin) {
    case 12:
        if (_current <= 4)
            return True;
        return False;
    case 3:
        if (_current == 0)
            return True;
        return False;
    case 2:
        if (_current == 1)
            return True;
        return False;
    case 4:
        if (_current == 2)
            return True;
        return False;
    case 7:
        if (_current == 3)
            return True;
        return False;
    case 10:
        if (_current == 4)
            return True;
        return False;
    case 1:
        if (_current == 5)
            return True;
        return False;
    case 5:
        if (_current == 6)
            return True;
        return False;
    case 6:
        if (_current == 7)
            return True;
        return False;
    case 9:
        if (_current == 8)
            return True;
        return False;
    case 11:
        if (_current == 9)
            return True;
        return False;
    default:
        return Undefined;
    }
}
