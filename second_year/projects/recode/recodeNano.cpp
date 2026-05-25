/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** recodeNano
*/

#include "recodeNano.hpp"
using namespace nts;

Tristate triAnd(Tristate a, Tristate b) {
    if (a == Tristate::True && b == Tristate::True) {
	return Tristate::True;
    } else if (a == Tristate::False || b == Tristate::False) {
	return Tristate::False;
    } else {
	return Tristate::Undefined;
    }
}

Tristate triOr(Tristate a, Tristate b) {
    if (a == Tristate::True || b == Tristate::True) {
	return Tristate::True;
    } else if (a == Tristate::False) {
	return b;
    }
    return Tristate::Undefined;
}

Tristate triNot(Tristate a) {
    if (a == Tristate::True) {
	return Tristate::False;
    } else if (a == Tristate::False) {
	return Tristate::True;
    }
    return Tristate::Undefined;
}

Tristate triXor(Tristate a, Tristate b) {
    if (a == Tristate::Undefined && b == Tristate::Undefined) {
	return Tristate::Undefined;
    } else if (a == b) {
	return Tristate::False;
    } else {
	return Tristate::True;
    }
}
