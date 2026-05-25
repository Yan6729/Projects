/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Int64Operand
*/

#include "Int64Operand.hpp"

Int64Operand::Int64Operand(int64_t val) : value(val) {}

std::string Int64Operand::toString() const 
{
    return std::to_string(value);
}

OperandType Int64Operand::getType() const 
{
    return OperandType::Int64;
}

IOperand* Int64Operand::operator+(const IOperand& rhs) const 
{
    int64_t result = value + std::stoll(rhs.toString());
    return new Int64Operand(result);
}

IOperand* Int64Operand::operator-(const IOperand& rhs) const 
{
    int64_t result = value - std::stoll(rhs.toString());
    return new Int64Operand(result);
}

IOperand* Int64Operand::operator*(const IOperand& rhs) const 
{
    int64_t result = value * std::stoll(rhs.toString());
    return new Int64Operand(result);
}

IOperand* Int64Operand::operator/(const IOperand& rhs) const 
{
    int64_t result = value / std::stoll(rhs.toString());
    return new Int64Operand(result);
}

IOperand* Int64Operand::operator%(const IOperand& rhs) const 
{
    int64_t result = value % std::stoll(rhs.toString());
    return new Int64Operand(result);
}
