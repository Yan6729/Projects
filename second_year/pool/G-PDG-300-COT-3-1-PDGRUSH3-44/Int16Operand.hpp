/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Int16Operand
*/

#ifndef INT16OPERAND_HPP_
    #include "IOperand.hpp"
    #define INT16OPERAND_HPP_

class Int16Operand : public IOperand {
private:
    int16_t value;

public:
    Int16Operand(int16_t val);

    std::string toString() const override;
    OperandType getType() const override;

    IOperand* operator+(const IOperand& rhs) const override;
    IOperand* operator-(const IOperand& rhs) const override;
    IOperand* operator*(const IOperand& rhs) const override;
    IOperand* operator/(const IOperand& rhs) const override;
    IOperand* operator%(const IOperand& rhs) const override;
};

#endif /* !INT16OPERAND_HPP_ */
