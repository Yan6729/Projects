/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Float32Operand
*/

#include "Float32Operand.hpp"
#include <cmath>

Float32Operand::Float32Operand(float val) : value(val) {}

std::string Float32Operand::toString() const 
{
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(7) << value;
    return stream.str();
}

OperandType Float32Operand::getType() const 
{
    return OperandType::Float32;
}

IOperand* Float32Operand::operator+(const IOperand& rhs) const 
{
    float result = value + std::stof(rhs.toString());
    return new Float32Operand(result);
}

IOperand* Float32Operand::operator-(const IOperand& rhs) const 
{
    float result = value - std::stof(rhs.toString());
    return new Float32Operand(result);
}

IOperand* Float32Operand::operator*(const IOperand& rhs) const 
{
    float result = value * std::stof(rhs.toString());
    return new Float32Operand(result);
}

IOperand* Float32Operand::operator/(const IOperand& rhs) const 
{
    float result = value / std::stof(rhs.toString());
    return new Float32Operand(result);
}

IOperand* Float32Operand::operator%(const IOperand& rhs) const 
{
    float result = std::fmod(value, std::stof(rhs.toString()));
    return new Float32Operand(result);
}
