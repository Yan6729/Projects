/*
** EPITECH PROJECT, 2026
** recode_rush3.hpp
** File description:
** default
*/

#ifndef RECODE_RUSH3
#include <iostream>
#include <string>
#define RECODE_RUSH3

enum ValueType {
    INT,
    FLOAT,
    DOUBLE
};

class ValueFactory {
public:
    static IValue *create(ValueType type, std::string& origin);

private:
    static IValue *createInt(std::string& origin);
    static IValue *createFloat(std::string& origin);
    static Ivalue *createDouble(std::string& origin);
}
#endif
