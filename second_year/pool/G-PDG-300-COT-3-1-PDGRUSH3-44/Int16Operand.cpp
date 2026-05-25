/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Int16Operand
*/

#include "Int16Operand.hpp"

Int16Operand::Int16Operand(int16_t val) : value(val) {}

std::string Int16Operand::toString() const 
{
    return std::to_string(value);
}

OperandType Int16Operand::getType() const 
{
    return OperandType::Int16;
}

IOperand* Int16Operand::operator+(const IOperand& rhs) const 
{
    int result = value + std::stoi(rhs.toString());
    return new Int16Operand(static_cast<int16_t>(result));
}

IOperand* Int16Operand::operator-(const IOperand& rhs) const 
{
    int result = value - std::stoi(rhs.toString());
    return new Int16Operand(static_cast<int16_t>(result));
}

IOperand* Int16Operand::operator*(const IOperand& rhs) const 
{
    int result = value * std::stoi(rhs.toString());
    return new Int16Operand(static_cast<int16_t>(result));
}

IOperand* Int16Operand::operator/(const IOperand& rhs) const 
{
    int result = value / std::stoi(rhs.toString());
    return new Int16Operand(static_cast<int16_t>(result));
}

IOperand* Int16Operand::operator%(const IOperand& rhs) const 
{
    int result = value % std::stoi(rhs.toString());
    return new Int16Operand(static_cast<int16_t>(result));
}
