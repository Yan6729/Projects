/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** FalseComponent
*/

#include "../../include/SpecialComponents/FalseComponent.hpp"
using namespace nts;

FalseComponent::FalseComponent()
{}

FalseComponent::~FalseComponent()
{}

Tristate FalseComponent::compute(size_t pin)
{
    static thread_local unordered_set<Verified, VerifiedHash> visited;

    if (visited.count({this, pin}))
        return Tristate::Undefined;
    pin != 1 ? throw CircuitError("Retrieve Error: Invalid pin ID") : ({
        visited.insert({this, pin});
        visited.erase({this, pin});
        return Tristate::False;
    });
}
