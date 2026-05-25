/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Int8Operand
*/

#ifndef INT8OPERAND_HPP_
    #include "IOperand.hpp"
    #define INT8OPERAND_HPP_

class Int8Operand : public IOperand {
private:
    int8_t value;

public:
    Int8Operand(int8_t val);

    std::string toString() const override;
    OperandType getType() const override;

    IOperand* operator+(const IOperand& rhs) const override;
    IOperand* operator-(const IOperand& rhs) const override;
    IOperand* operator*(const IOperand& rhs) const override;
    IOperand* operator/(const IOperand& rhs) const override;
    IOperand* operator%(const IOperand& rhs) const override;
};

#endif /* !INT8OPERAND_HPP_ */
