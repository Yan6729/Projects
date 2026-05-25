/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
**  HeightBitsShiftRegisterComponent
*/

#include "../../include/AdvancedComponents/8BitsShiftRegisterComponent.hpp"
using namespace nts;

HeightBSRComponent::HeightBSRComponent()
{
    for (int i = 0; i < 8; ++i) {
        _rgt[i] = False;
        _output[i] = False;
    }
}

HeightBSRComponent::~HeightBSRComponent()
{}

void HeightBSRComponent::simulate(std::size_t tick)
{
    if (_lastTick == tick)
        return;

    _lastTick = tick;
    Tristate strobe = getLink(1);
    Tristate data = getLink(2);
    Tristate clock = getLink(3);
    Tristate qs;
    Tristate qe;

    if (_lastClock == False && clock == True) {
        for (int i = 7; i > 0; i--)
            _rgt[i] = _rgt[i - 1];
        _rgt[0] = data;
        qs = _rgt[7];
    }
    if (_lastStrobe == True && strobe == False) {
        for (int i = 0; i < 8; i++)
            _output[i] = _rgt[i];
    }
    if (_lastClock == True && clock == False)
        qe = qs;
   _lastClock = clock;
   _lastStrobe = strobe;
}

Tristate HeightBSRComponent::compute(std::size_t pin)
{
    Tristate oe = getLink(15);
    Tristate qs;
    Tristate qe;

    if (oe == False)
        return Undefined;
    switch (pin) {
    case 4:  return _output[0];
    case 5:  return _output[1];
    case 6:  return _output[2];
    case 7:  return _output[3];
    case 9:  return qs;
    case 10: return qe;
    case 14: return _output[4];
    case 13: return _output[5];
    case 12: return _output[6];
    case 11: return _output[7];
    default:
        return Undefined;
    }
}
