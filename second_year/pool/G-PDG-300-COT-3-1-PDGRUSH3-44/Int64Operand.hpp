/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Int64Operand
*/

#ifndef INT64OPERAND_HPP_
    #include "IOperand.hpp"
    #define INT64OPERAND_HPP_

class Int64Operand : public IOperand {
private:
    int64_t value;

public:
    Int64Operand(int64_t val);

    std::string toString() const override;
    OperandType getType() const override;
    IOperand* operator+(const IOperand& rhs) const override;
    IOperand* operator-(const IOperand& rhs) const override;
    IOperand* operator*(const IOperand& rhs) const override;
    IOperand* operator/(const IOperand& rhs) const override;
    IOperand* operator%(const IOperand& rhs) const override;
};

#endif /* !INT64OPERAND_HPP_ */
