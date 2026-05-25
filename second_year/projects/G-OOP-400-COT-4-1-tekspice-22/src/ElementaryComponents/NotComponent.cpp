/*
** EPITECH PROJECT, 2026
** snd_projects
** File description:
** NotComponent
*/

#include "../../include/ElementaryComponents/NotComponent.hpp"
using namespace nts;

NotComponent::NotComponent()
{}

NotComponent::~NotComponent()
{}

Tristate NotComponent::compute(size_t pin)
{
    static thread_local unordered_set<Verified, VerifiedHash> visited;

    if (visited.count({this, pin}))
        return Tristate::Undefined;

    pin != 2  ? throw CircuitError("Retrieve Error: Invalid pin ID") : ({
        visited.insert({this, pin});
        Tristate input = getLink(1);
!
        visited.erase({this, pin});
        return !input;
    });
}
