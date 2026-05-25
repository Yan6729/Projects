/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** AComponent
*/

#include "../include/AComponent.hpp"
using namespace nts;

AComponent::AComponent()
{}

AComponent::~AComponent()
{}

CircuitError::CircuitError(const string& message) : _msg(message)
{}

CircuitError::~CircuitError()
{}

const char *CircuitError::what(void) const noexcept
{
    return _msg.c_str();
}

void AComponent::setLink(size_t pin, IComponent& other, size_t otherPin)
{
    if (_pins[pin].other == &other) {
        return;
    }
    _pins[pin] = { &other, otherPin };
    other.setLink(otherPin, *this, pin);
}

Tristate AComponent::getLink(size_t pin)
{
    auto _pair = _pins.find(pin);

    if (_pair == _pins.end()) {
        return Tristate::Undefined;
    }

    Link& _link = _pair->second;
    return _link.other->compute(_link.pin);
}

void AComponent::simulate(size_t tick)
{
    (void)tick;
    return;
}
