/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** 4BitsDecoderComponent
*/

#include "../../include/AdvancedComponents/4BitsDecoderComponent.hpp"
using namespace nts;

FourBDComponent::FourBDComponent() : _latchedIndex(0), _lastStrobe(Undefined)
{
    for (int i = 0; i < 16; i++)
        _outputs[i] = False;
}

FourBDComponent::~FourBDComponent()
{}

void FourBDComponent::simulate(std::size_t tick)
{
    if (_lastTick == tick)
      return;
      _lastTick = tick;

    Tristate inh = getLink(23);
    Tristate strobe = getLink(1);

    if (strobe == True)
        {
            Tristate a = getLink(2);
            Tristate b = getLink(3);
            Tristate c = getLink(21);
            Tristate d = getLink(22);
        
            if (a == Undefined || b == Undefined ||
                c == Undefined || d == Undefined)
                {
                    _latchedIndex = -1;
                } else {
                std::size_t index = 0;

                if (a == True)
                    index += 1;
                if (b == True)
                    index += 2;
                if (c == True)
                    index += 4;
                if (d == True)
                    index += 8;
                _latchedIndex = index;

            }
        }

    if (inh == True) {
        for (int i = 0; i < 16; i++)
            _outputs[i] = False;
    } else if (inh == False) {
        if (_latchedIndex == -1) {
            for (int i = 0; i < 16; i++)
                _outputs[i] = Undefined;
        } else {
            for (int i = 0; i < 16; i++)
                _outputs[i] = False;
            _outputs[_latchedIndex] = True;
        }
    } else {
        for (int i = 0; i < 16; i++)
                _outputs[i] = Undefined;
    }

       _lastStrobe = strobe;
}

Tristate FourBDComponent::compute(std::size_t pin)
{
    switch (pin)
        {
        case 11:  return _outputs[0];
        case 9:  return _outputs[1];
        case 10:  return _outputs[2];
        case 8:  return _outputs[3];
        case 7:  return _outputs[4];
        case 6:  return _outputs[5];
        case 5: return _outputs[6];
        case 4: return _outputs[7];
        case 18: return _outputs[8];
        case 17: return _outputs[9];
        case 20: return _outputs[10];
        case 19: return _outputs[11];
        case 14: return _outputs[12];
        case 13: return _outputs[13];
        case 16: return _outputs[14];
        case 15: return _outputs[15];
        default:
            return Undefined;
        }
}
