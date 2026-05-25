/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Float64Operand
*/

#ifndef FLOAT64OPERAND_HPP_
    #include "IOperand.hpp"
    #define FLOAT64OPERAND_HPP_

class Float64Operand : public IOperand {
private:
    double value;

public:
    Float64Operand(double val);

    std::string toString() const override;
    OperandType getType() const override;

    IOperand* operator+(const IOperand& rhs) const override;
    IOperand* operator-(const IOperand& rhs) const override;
    IOperand* operator*(const IOperand& rhs) const override;
    IOperand* operator/(const IOperand& rhs) const override;
    IOperand* operator%(const IOperand& rhs) const override;
};

#endif /* !FLOAT64OPERAND_HPP_ */
