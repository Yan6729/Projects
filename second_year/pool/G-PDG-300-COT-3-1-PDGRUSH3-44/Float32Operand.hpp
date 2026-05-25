/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Float32Operand
*/

#ifndef FLOAT32OPERAND_HPP_
    #include "IOperand.hpp"
    #define FLOAT32OPERAND_HPP_

class Float32Operand : public IOperand {
private:
    float value;

public:
    Float32Operand(float val);

    std::string toString() const override;
    OperandType getType() const override;

    IOperand* operator+(const IOperand& rhs) const override;
    IOperand* operator-(const IOperand& rhs) const override;
    IOperand* operator*(const IOperand& rhs) const override;
    IOperand* operator/(const IOperand& rhs) const override;
    IOperand* operator%(const IOperand& rhs) const override;
};

#endif /* !FLOAT32OPERAND_HPP_ */
