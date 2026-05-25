/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Int32Operand
*/

#ifndef INT32OPERAND_HPP_
    #include "IOperand.hpp"
    #define INT32OPERAND_HPP_

class Int32Operand : public IOperand {
private:
    int32_t value;

public:
    Int32Operand(int32_t val);

    std::string toString() const override;
    OperandType getType() const override;

    IOperand* operator+(const IOperand& rhs) const override;
    IOperand* operator-(const IOperand& rhs) const override;
    IOperand* operator*(const IOperand& rhs) const override;
    IOperand* operator/(const IOperand& rhs) const override;
    IOperand* operator%(const IOperand& rhs) const override;
};

#endif /* !INT32OPERAND_HPP_ */
