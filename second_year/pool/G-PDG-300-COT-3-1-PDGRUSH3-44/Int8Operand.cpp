/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Int8Operand
*/

#include "Int8Operand.hpp"

Int8Operand::Int8Operand(int8_t val) : value(val) {}

std::string Int8Operand::toString() const 
{
    return std::to_string(value);
}

OperandType Int8Operand::getType() const 
{
    return OperandType::Int8;
}

IOperand* Int8Operand::operator+(const IOperand& rhs) const 
{
    int result = value + std::stoi(rhs.toString());
    return new Int8Operand(static_cast<int8_t>(result));
}

IOperand* Int8Operand::operator-(const IOperand& rhs) const 
{
    int result = value - std::stoi(rhs.toString());
    return new Int8Operand(static_cast<int8_t>(result));
}

IOperand* Int8Operand::operator*(const IOperand& rhs) const 
{
    int result = value * std::stoi(rhs.toString());
    return new Int8Operand(static_cast<int8_t>(result));
}

IOperand* Int8Operand::operator/(const IOperand& rhs) const 
{
    int result = value / std::stoi(rhs.toString());
    return new Int8Operand(static_cast<int8_t>(result));
}

IOperand* Int8Operand::operator%(const IOperand& rhs) const 
{
    int result = value % std::stoi(rhs.toString());
    return new Int8Operand(static_cast<int8_t>(result));
}
