/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Float64Operand
*/

#include <cmath>
#include "Float64Operand.hpp"

Float64Operand::Float64Operand(double val) : value(val) {}

std::string Float64Operand::toString() const 
{
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(15) << value;
    return stream.str();
}

OperandType Float64Operand::getType() const 
{
    return OperandType::Float64;
}

IOperand* Float64Operand::operator+(const IOperand& rhs) const 
{
    double result = value + std::stod(rhs.toString());
    return new Float64Operand(result);
}

IOperand* Float64Operand::operator-(const IOperand& rhs) const 
{
    double result = value - std::stod(rhs.toString());
    return new Float64Operand(result);
}

IOperand* Float64Operand::operator*(const IOperand& rhs) const
{
    double result = value * std::stod(rhs.toString());
    return new Float64Operand(result);
}

IOperand* Float64Operand::operator/(const IOperand& rhs) const 
{
    float result = value / std::stof(rhs.toString());
    return new Float64Operand(result);
}

IOperand* Float64Operand::operator%(const IOperand& rhs) const 
{
    double result = std::fmod(value, std::stod(rhs.toString()));
    return new Float64Operand(result);
}
