/*
** EPITECH PROJECT, 2026
** recode
** File description:
** recode_rush3.cpp
*/

#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include "recode_rush3.hpp"

IValue *create(ValueType type, std::string& origin)
{
    switch(type) {
    case INT:
	return createInt(origin);
    case FLOAT:
	return createFloat(origin);
    case DOUBLE:
	return createDouble(origin);
    }
    return nullptr;	
}

