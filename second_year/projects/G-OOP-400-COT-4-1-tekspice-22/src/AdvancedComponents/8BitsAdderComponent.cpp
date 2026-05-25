/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** 8BitsAdderComponent
*/

#include "../../include/AdvancedComponents/8BitsAdderComponent.hpp"
using namespace nts;

HBAComponent::HBAComponent()
{}

HBAComponent::~HBAComponent()
{}

Tristate HBAComponent::computeSum(Tristate a, Tristate b, Tristate cin) const
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

Tristate HBAComponent::computeCarry(Tristate a, Tristate b, Tristate cin) const
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

Tristate HBAComponent::compute(size_t pin)
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
    Tristate a5 = getLink(21);
    Tristate b5 = getLink(20);
    Tristate a6 = getLink(19);
    Tristate b6 = getLink(18);
    Tristate a7 = getLink(17);
    Tristate b7 = getLink(16);
    Tristate a8 = getLink(22);
    Tristate b8 = getLink(23);


    Tristate s1 = computeSum(a1, b1, cin);
    Tristate c1 = computeCarry(a1, b1, cin);
    Tristate s2 = computeSum(a2, b2, c1);
    Tristate c2 = computeCarry(a2, b2, c1);
    Tristate s3 = computeSum(a3, b3, c2);
    Tristate c3 = computeCarry(a3, b3, c2);
    Tristate s4 = computeSum(a4, b4, c3);
    Tristate c4 = computeCarry(a4, b4, c3);
    Tristate s5 = computeSum(a5, b5, c4);
    Tristate c5 = computeCarry(a5, b5, c4);
    Tristate s6 = computeSum(a6, b6, c5);
    Tristate c6 = computeCarry(a6, b6, c5);
    Tristate s7 = computeSum(a7, b7, c6);
    Tristate c7 = computeCarry(a7, b7, c6);
    Tristate s8 = computeSum(a8, b8, c7);
    Tristate cout = computeCarry(a8, b8, c7);

    switch (pin)
        {
        case 10: return s1;
        case 11: return s2;
        case 12: return s3;
        case 13: return s4;
        case 14: return cout;
        case 24: return s5;
        case 25: return s6;
        case 26: return s7;
        case 27: return s8;
        default: return Undefined;
    }
}
