/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** FourXorComponent
*/

#include "../../include/GatesComponents/4XorComponent.hpp"
using namespace nts;


FourXorComponent::FourXorComponent()
{}

FourXorComponent::~FourXorComponent()
{}

Tristate FourXorComponent::compute(size_t pin)
{
    static thread_local unordered_set<Verified, VerifiedHash> visited;
    if (visited.count({this, pin}))
        return Tristate::Undefined;

    (pin != 3 &&
    pin != 4 &&
    pin != 10 &&
    pin != 11) ? throw CircuitError("Retrieve Error: Invalid pin ID") : ({
        visited.insert({this, pin});
        const Tristate input1 = (pin == 3 || pin == 10) ? getLink(pin - 2) : getLink(pin + 2);
        const Tristate input2 = (pin == 3 || pin == 10) ? getLink(pin - 1) : getLink(pin + 1);

        visited.erase({this, pin});
        return input1 ^ input2;
    });
}
