/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** TwelveBitsCounterComponent
*/

#include "../../include/AdvancedComponents/12BitsCounterComponent.hpp"
using namespace nts;

TwelveBCComponent::TwelveBCComponent()
{}

TwelveBCComponent::~TwelveBCComponent()
{}

void TwelveBCComponent::simulate(std::size_t tick)
{
    if (_lastTick == tick)
        return;

    _lastTick = tick;

    Tristate clk = getLink(10);
    Tristate reset = getLink(11);

    if (reset == True) {
        _current = 0;
        _lastClock == clk;
    } else if (_lastClock == True && clk == False) {
        _current = _current + 1;
        _current &= 4095;
    }
    _lastClock = clk;
}

Tristate TwelveBCComponent::compute(std::size_t pin)
{
    switch (pin) {
    case 9:
        if ((_current >> 0) & 1)
            return True;
        return False;
    case 7:
        if ((_current >> 1) & 1)
            return True;
        return False;
    case 6:
        if ((_current >> 2) & 1)
            return True;
        return False;
    case 5:
        if ((_current >> 3) & 1)
            return True;
        return False;
    case 3:
        if ((_current >> 4) & 1)
            return True;
        return False;
    case 2:
        if ((_current >> 5) & 1)
            return True;
        return False;
    case 4:
        if ((_current >> 6) & 1)
            return True;
        return False;
    case 13:
        if ((_current >> 7) & 1)
            return True;
        return False;
    case 12:
        if ((_current >> 8) & 1)
            return True;
        return False;
    case 14:
        if ((_current >> 9) & 1)
            return True;
        return False;
    case 15:
        if ((_current >> 10) & 1)
            return True;
        return False;
    case 1:
        if ((_current >> 11) & 1)
            return True;
        return False;
    default:
        return Undefined;
    }
}
