/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** instruction
*/

#include "instruction.hpp"

void usage(void)
{
    std::cout << "usage: bistroMatic [options]\n"
            << "options:\n"
            << "-h, --help Show this help\n"
            << "-b, --bonus Add any flag you want for bonuses!" << std::endl;
}

bistroMatic::bistroMatic()
{
    stack.back() = nullptr;
}

bistroMatic::~bistroMatic()
{
    for (IOperand *ptr : stack) {
        if (ptr != nullptr) {
            delete(ptr);
            ptr = nullptr;
        }
    }
}

void bistroMatic::push(IOperand *object)
{
    stack.push_back(object);
}

void bistroMatic::display(void)
{
    if ((stack.back() != nullptr) && stack.size() >= 1) {
        std::cout << *stack.back() << std::endl;
    } else {
        return;
    }
}

void bistroMatic::pop(void)
{
    if (!stack.empty())
        stack.pop_back();
    else
        throw std::runtime_error("The stack is empty");
}

void bistroMatic::assert(IOperand *object)
{
    if (!stack.empty() && (object->getType() == stack.back()->getType()) && object->toString() == stack.back()->toString()) {
        delete(object);
        object = nullptr;
        return;
    } else {
        delete(object);
        object = nullptr;
        throw std::runtime_error("Element is not the stack's head");
    }
}

void bistroMatic::swap(void)
{
    if (stack.size() >= 2) {
        IOperand *first = stack.back();
        stack.pop_back();
        IOperand *second = stack.back();
        stack.pop_back();

        stack.push_back(first);
        stack.push_back(second);
    } else {
        throw std::runtime_error("Not enought element in the stack");
    }
}


void bistroMatic::clear(void)
{
    if (stack.empty()) {
        return;
    } else {
        for (IOperand *ptr : stack) {
            delete(ptr);
            ptr = nullptr;
        }
    }
    stack.clear();
}

void bistroMatic::add(void)
{
    if (stack.size() < 2) {
        throw std::runtime_error("Not enought element in the stack");
    }

}

void bistroMatic::sub(void)
{
    if (stack.size() < 2) {
        throw std::runtime_error("Not enought element in the stack");
    }
    IOperand *first = stack.back();
    stack.pop_back();
    IOperand *second = stack.back();
    stack.pop_back();

}

void bistroMatic::div(void)
{
    if (stack.size() < 2) {
        throw std::runtime_error("Not enought element in the stack");
    }
    IOperand *first = stack.back();
    stack.pop_back();
    IOperand *second = stack.back();
    stack.pop_back();
    if ((std::stol(first->toString()) == 0) || (std::stol(first->toString()) == 0)) {
        throw std::runtime_error("Operation can't happen with null value");
    }
}

void bistroMatic::mul(void)
{
    if (stack.size() < 2) {
        throw std::runtime_error("Not enought element in the stack");
    }
    IOperand *first = stack.back();
    stack.pop_back();
    IOperand *second = stack.back();
    stack.pop_back();
}

void bistroMatic::mod(void)
{
    if (stack.size() < 2) {
        throw std::runtime_error("Not enought element in the stack");
    }
    IOperand *first = stack.back();
    stack.pop_back();
    IOperand *second = stack.back();
    stack.pop_back();
    if ((std::stol(first->toString()) == 0) || (std::stol(first->toString()) == 0)) {
        throw std::runtime_error("Operation can't happen with null value");
    }
}