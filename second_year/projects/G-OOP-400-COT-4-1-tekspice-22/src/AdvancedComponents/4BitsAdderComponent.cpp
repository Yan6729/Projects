/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** FourBitsAdderComponent
*/

#include "../../include/AdvancedComponents/4BitsAdderComponent.hpp"
using namespace nts;

FourBAComponent::FourBAComponent()
{}

FourBAComponent::~FourBAComponent()
{}

Tristate FourBAComponent::computeSum(Tristate a, Tristate b, Tristate cin) const
{
    if (a == Undefined || b == Undefined || cin == Undefined)
        return Undefined;
    int sum = (a ^ b) ^ cin;
    if (sum == -1)
        return Undefined;
    if (sum == 1)
	return True;
    return False;
}

Tristate FourBAComponent::computeCarry(Tristate a, Tristate b, Tristate cin) const
{
    if (a == Undefined || b == Undefined || cin == Undefined)
        return Undefined;

    int carry = (a & b) | (cin & (a ^ b));
    if (carry == -1)
	return Undefined;
    if (carry == 1)
        return True;
    return False;
}

Tristate FourBAComponent::compute(std::size_t pin)
{
    Tristate a1 = getLink(7);
    Tristate b1 = getLink(6);
    Tristate a2 = getLink(5);
    Tristate b2 = getLink(4);
    Tristate a3 = getLink(3);
    Tristate b3 = getLink(2);
    Tristate a4 = getLink(1);
    Tristate b4 = getLink(15);
    Tristate cin = getLink(9);

    Tristate s1 = computeSum(a1, b1, cin);
    Tristate c1 = computeCarry(a1, b1, cin);
    Tristate s2 = computeSum(a2, b2, c1);
    Tristate c2 = computeCarry(a2, b2, c1);
    Tristate s3 = computeSum(a3, b3, c2);
    Tristate c3 = computeCarry(a3, b3, c2);
    Tristate s4 = computeSum(a4, b4, c3);
    Tristate cout = computeCarry(a4, b4, c3);

    switch (pin)
        {
        case 10: return s1;
        case 11: return s2;
        case 12: return s3;
        case 13: return s4;
        case 14: return cout;
        default: return Undefined;
        }
}
