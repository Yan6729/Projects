/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** 8ChannelDataSelectorComponent
*/

#include "../../include/AdvancedComponents/8ChannelDataSelectorComponent.hpp"
using namespace nts;

HeightCDSComponent::HeightCDSComponent()
{}

HeightCDSComponent::~HeightCDSComponent()
{}

void HeightCDSComponent::simulate(std::size_t tick)
{
    (void)tick;
}

Tristate HeightCDSComponent::compute(std::size_t pin)
{
    if (pin != 14)
        return Undefined;
    Tristate inh = getLink(10);
    Tristate enb = getLink(15);
    if (enb == True)
        return Undefined;
    if (inh == True)
        return False;
    Tristate a = getLink(11);
    Tristate b = getLink(12);
    Tristate c = getLink(13);
    if (a == Undefined || b == Undefined || c == Undefined)
        return Undefined;
    int index = 0;
    if (a == True)
        index += 1;
    if (b == True)
        index += 2;
    if (c == True)
        index += 4;

    std::size_t dataPin = 0;

    if (index == 0)
        dataPin = 1;
    else if (index == 1)
        dataPin = 2;
    else if (index == 2)
        dataPin = 3;
    else if (index == 3)
        dataPin = 4;
    else if (index == 4)
        dataPin = 5;
    else if (index == 5)
        dataPin = 6;
    else if (index == 6)
        dataPin = 7;
    else if (index == 7)
        dataPin = 9;

    return getLink(dataPin);
}
