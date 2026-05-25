/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** IOperand
*/

#ifndef IOPERAND_HPP_
    #include <sstream>
    #include <iomanip>
    #include <iostream>
    #include <string>
#define IOPERAND_HPP_

enum class OperandType {
    Int8,
    Int16,
    Int32,
    Int64,
    Float32,
    Float64,
    Error
};

class IOperand{
    public:
        virtual std::string toString() const = 0; // string that represents the instance
        virtual OperandType getType() const = 0; // returns the type of instance
        virtual IOperand *operator+(const IOperand& rhs) const = 0; // sum
        virtual IOperand *operator-(const IOperand& rhs) const = 0; // difference
        virtual IOperand *operator*(const IOperand& rhs) const = 0; // product
        virtual IOperand *operator/(const IOperand& rhs) const = 0; // quotient
        virtual IOperand *operator%(const IOperand& rhs) const = 0; // modulo
        virtual ~IOperand() = default;

    private:
};

std::ostream& operator<<(std::ostream& redirect, const IOperand& object);
#endif /* !IOPERAND_HPP_ */
