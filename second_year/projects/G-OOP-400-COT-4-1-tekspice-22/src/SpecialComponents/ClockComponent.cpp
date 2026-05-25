/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** ClockComponent
*/

#include "../../include/SpecialComponents/ClockComponent.hpp"
using namespace nts;

ClockComponent::ClockComponent()
{}

ClockComponent::~ClockComponent()
{}

void ClockComponent::simulate(size_t tick)
{
    (void)tick;
    
    switch (_temp) {
        case Tristate::Void:
            break;       
        default:
            _value = _temp;
            _temp = Tristate::Void;
            return;
    }
    if (_value == Tristate::True)
        _value = Tristate::False;
    else if (_value == Tristate::False)
        _value = Tristate::True;
}


ClockComponent& ClockComponent::operator=(nts::Tristate newValue)
{
    this->_temp = newValue;
    return *this;
}
