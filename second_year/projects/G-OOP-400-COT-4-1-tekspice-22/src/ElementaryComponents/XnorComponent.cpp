/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** XnorComponent
*/

#include "../../include/ElementaryComponents/XnorComponent.hpp"
using namespace nts;

XnorComponent::XnorComponent()
{
}

XnorComponent::~XnorComponent()
{
}

Tristate XnorComponent::compute(size_t pin)
{
    static thread_local unordered_set<Verified, VerifiedHash> visited;

    if (visited.count({this, pin}))
        return Tristate::Undefined;

    pin != 3  ? throw CircuitError("Retrieve Error: Invalid pin ID") : ({
        visited.insert({this, pin});
        const Tristate one = getLink(1);
        const Tristate two = getLink(2);

        visited.erase({this, pin});
        return !(one ^ two);
    });
}
