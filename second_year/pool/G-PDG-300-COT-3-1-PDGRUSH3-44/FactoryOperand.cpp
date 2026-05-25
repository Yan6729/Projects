/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, Jan, 2026                                                     *
 * Title           - G-PDG-300-COT-3-1-PDGRUSH3-44                                      *
 * Description     -                                                                    *
 *     FactoryOperand                                                                   *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "FactoryOperand.hpp"
#include "Int32Operand.hpp"
#include "Float64Operand.hpp"
#include "Int8Operand.hpp"
#include "Int16Operand.hpp"
#include "Int64Operand.hpp"
#include "Float32Operand.hpp"
#include <stdexcept>

IOperand *OperandFactory::createInt8(const std::string& value)
{
    int val = std::stoi(value);
    int8_t result = static_cast<int8_t>(val);
    IOperand *ptr = new Int8Operand(result);
    return ptr;
}

IOperand *OperandFactory::createInt16(const std::string& value)
{
    int val = std::stoi(value);
    int16_t result = static_cast<int16_t>(val);
    IOperand *ptr = new Int16Operand(result);
    return ptr;
}

IOperand *OperandFactory::createInt32(const std::string& value)
{
    int val = std::stoi(value);
    int32_t result = static_cast<int32_t>(val);
    IOperand *ptr = new Int32Operand(result);
    return ptr;
}

IOperand *OperandFactory::createInt64(const std::string& value)
{
    long long val = std::stoll(value);
    int64_t result = static_cast<int64_t>(val);
    IOperand *ptr = new Int64Operand(result);
    return ptr;
}

IOperand *OperandFactory::createFloat32(const std::string& value)
{
    float val = std::stof(value);
    IOperand *ptr = new Float32Operand(val);
    return ptr;
}

IOperand *OperandFactory::createFloat64(const std::string& value)
{
    double val = std::stod(value);
    IOperand *ptr = new Float64Operand(val);
    return ptr;
}

IOperand* OperandFactory::createOperand(OperandType type, const std::string& value)
{
    switch (type)
    {
        case OperandType::Int8:
            return createInt8(value);
        case OperandType::Int16:
            return createInt16(value);
        case OperandType::Int32:
            return createInt32(value);
        case OperandType::Int64:
            return createInt64(value);
        case OperandType::Float32:
            return createFloat32(value);
        case OperandType::Float64:
            return createFloat64(value);
        case OperandType::Error:
            return nullptr;
    }
    return nullptr;
}
