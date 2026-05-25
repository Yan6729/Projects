/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** DualFlipFlop
*/

#include "../../include/AdvancedComponents/DualFlipFlopComponent.hpp"
using namespace nts;

DFFComponent::DFFComponent()
{}

DFFComponent::~DFFComponent()
{}

void DFFComponent::updateFlipFlop(Tristate &q, Tristate &_q, Tristate &lastClock,
                                  std::size_t clkPin, std::size_t dataPin,
                                  std::size_t resetPin, std::size_t setPin)
{
    Tristate clk = getLink(clkPin);
    Tristate d = getLink(dataPin);
    Tristate reset = getLink(resetPin);
    Tristate set = getLink(setPin);

    if (set == True && reset == True) {
        q = True;
        _q = True;
    } else if (set == True) {
        q = True;
        _q = False;
    } else if (reset == True) {
        q = False;
        _q = True;
    } else if (set == False && reset == False) { 
    if (lastClock == False && clk == True) {
        q = d;
        if (d == True)
            _q = False;
        else if (d == False)
            _q = True;
        else
            _q = Undefined;
    }
    } else {
        q = Undefined;
        _q = Undefined;
    }
    lastClock = clk;
}

void DFFComponent::simulate(std::size_t tick)
{
    if (_lastTick == tick)
        return;
    _lastTick = tick;
    updateFlipFlop(_q1, q1, _lastClock1, 3, 5, 4, 6);
    updateFlipFlop(_q2, q2, _lastClock2, 11, 9, 10, 8);
}

Tristate DFFComponent::compute(std::size_t pin)
{
    switch (pin) {
    case 1:
        return _q1;
    case 2:
        return q1;
    case 13:
        return _q2;
    case 12:
        return q2;
    default:
        return Undefined;
    }
}