/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** FourNotComponent
*/

#include "../../include/GatesComponents/6NotComponent.hpp"
using namespace nts;


FourNotComponent::FourNotComponent()
{}

FourNotComponent::~FourNotComponent()
{}

Tristate FourNotComponent::compute(size_t pin)
{
    static thread_local unordered_set<Verified, VerifiedHash> visited;

    if (visited.count({this, pin}))
        return Tristate::Undefined;

    (pin != 2 &&
    pin != 4 &&
    pin != 6 &&
    pin != 8 &&
    pin != 10 &&
    pin != 12) ? throw CircuitError("Retrieve Error: Invalid pin ID") : ({
        visited.insert({this, pin});
        const Tristate input = (pin == 2 || pin == 4 || pin == 6) ? getLink(pin - 1) : getLink(pin + 1);

        visited.erase({this, pin});
        return !input;
    });
}

