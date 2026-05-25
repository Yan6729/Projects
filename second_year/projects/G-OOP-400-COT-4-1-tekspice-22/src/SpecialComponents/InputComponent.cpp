/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** InputComponent
*/

#include "../../include/SpecialComponents/InputComponent.hpp"
using namespace nts;

InputComponent::InputComponent()
{}

InputComponent::~InputComponent()
{}

Tristate InputComponent::compute(size_t pin)
{
    static thread_local unordered_set<Verified, VerifiedHash> visited;

    if (visited.count({this, pin}))
        return Tristate::Undefined;

    pin != 1 ? throw CircuitError("Retrieve Error: Invalid pin ID") : ({
        visited.insert({this, pin});
        visited.erase({this, pin});
        return _value;
    });
}

InputComponent& InputComponent::operator=(nts::Tristate newValue)
{
    this->_temp = newValue;
    return *this;
}

void InputComponent::simulate(size_t tick)
{
    (void)tick;
    switch (_temp) {
        case Tristate::Void:
            return;       
        default:
            _value = _temp;
            _temp = Tristate::Void;
            return;
    }
}
