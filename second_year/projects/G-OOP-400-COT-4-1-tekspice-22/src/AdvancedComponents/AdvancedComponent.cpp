/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** AdvancedComponent
*/

#include "../../include/AdvancedComponents/AdvancedComponent.hpp"
using namespace nts;

AdvancedComponent::AdvancedComponent()
{}

AdvancedComponent::~AdvancedComponent()
{}

Tristate AdvancedComponent::compute(size_t pin)
{
    (void)pin;
    return Tristate::Undefined;
}

void AdvancedComponent::simulate(size_t tick)
{
    (void)tick;
}
