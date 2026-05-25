/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Stack
*/

#include "Stack.hpp"

Stack::Error::Error(std::string message) : _msg(message)
{}

const char *Stack::Error::what() const noexcept
{
    return _msg.c_str();
}

Stack::Stack()
{
}

Stack::~Stack()
{
}

void Stack::push(double value)
{
    _stack.push(value);
}

double Stack::pop()
{
    if (_stack.empty()) {
        throw Stack::Error("Empty stack");
        return 0;
    }
    double value = _stack.top();
    _stack.pop();
    return value;
}

double Stack::top() const
{
    if (_stack.empty()) {
        throw Stack::Error("Empty stack");
        return 0;
    }
    return _stack.top();
}

void Stack::add()
{
    if (_stack.size() < 2) {
        throw  Stack::Error("Not enough operands");
        return;
    }
    double first = _stack.top();
    _stack.pop();
    double second = _stack.top();
    _stack.pop();
    _stack.push(first + second);
}

void Stack::sub()
{
    if (_stack.size() < 2) {
        throw  Stack::Error("Not enough operands");
        return;
    }
    double first = _stack.top();
    _stack.pop();
    double second = _stack.top();
    _stack.pop();
    _stack.push(first - second);
}

void Stack::mul()
{
    if (_stack.size() < 2) {
        throw  Stack::Error("Not enough operands");
        return;
    }
    double first = _stack.top();
    _stack.pop();
    double second = _stack.top();
    _stack.pop();
    _stack.push(first * second);
}

void Stack::div()
{
    if (_stack.size() < 2) {
        throw  Stack::Error("Not enough operands");
        return;
    }
    std::stack<double> copie = _stack;
    double first = copie.top();
    copie.pop();
    double second = copie.top();
    copie.pop();

    if (second == 0) {
        throw Stack::Error("Division by 0 not possible");
        return;
    }
    _stack.pop();
    _stack.pop();
    _stack.push(first / second);
}
