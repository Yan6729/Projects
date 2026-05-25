/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** TrueComponent
*/

#include "../../include/SpecialComponents/TrueComponent.hpp"
using namespace nts;

TrueComponent::TrueComponent()
{}

TrueComponent::~TrueComponent()
{}

Tristate TrueComponent::compute(size_t pin)
{
    static thread_local unordered_set<Verified, VerifiedHash> visited;

    if (visited.count({this, pin}))
        return Tristate::Undefined;

    pin != 1 ? throw CircuitError("Retrieve Error: Invalid pin ID") : ({
        visited.insert({this, pin});
        visited.erase({this, pin});
        return Tristate::True;
    });
}
