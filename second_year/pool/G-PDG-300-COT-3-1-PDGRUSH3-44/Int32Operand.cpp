/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Int32Operand
*/

#include "Int32Operand.hpp"

Int32Operand::Int32Operand(int32_t val) : value(val) {}

std::string Int32Operand::toString() const 
{ 
    return std::to_string(value); 
}

OperandType Int32Operand::getType() const 
{ 
    return OperandType::Int32; 
}

IOperand* Int32Operand::operator+(const IOperand& rhs) const 
{
    int32_t result = value + std::stoi(rhs.toString());
    return new Int32Operand(result);
}

IOperand* Int32Operand::operator-(const IOperand& rhs) const 
{
    int32_t result = value - std::stoi(rhs.toString());
    return new Int32Operand(result);
}

IOperand* Int32Operand::operator*(const IOperand& rhs) const 
{
    int32_t result = value * std::stoi(rhs.toString());
    return new Int32Operand(result);
}

IOperand* Int32Operand::operator/(const IOperand& rhs) const 
{
    int32_t result = value / std::stoi(rhs.toString());
    return new Int32Operand(result);
}

IOperand* Int32Operand::operator%(const IOperand& rhs) const 
{
    int32_t result = value % std::stoi(rhs.toString());
    return new Int32Operand(result);
}
