/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** OutputComponent
*/

#include "../../include/SpecialComponents/OutputComponent.hpp"
using namespace nts;

OutputComponent::OutputComponent()
{
    _pins[1] = {nullptr, 0};
}

OutputComponent::~OutputComponent()
{}

Tristate OutputComponent::compute(size_t pin)
{
    static thread_local unordered_set<Verified, VerifiedHash> visited;

    if (visited.count({this, pin}))
        return Tristate::Undefined;

    _pins.find(pin) == _pins.end() ? throw CircuitError("Retrieve Error: Invalid pin ID") : ({
        visited.insert({this, pin});
        Link _l = _pins[pin];
        visited.erase({this, pin});
        return _l.other != nullptr ? _l.other->compute(_l.pin) : Tristate::Undefined;
    });
}
