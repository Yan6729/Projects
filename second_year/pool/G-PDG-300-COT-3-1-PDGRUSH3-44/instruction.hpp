/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** instruction
*/

#ifndef INSTRUCTION_HPP_
    #include <iostream>
    #include <string>
    #include <list>
    #include <tuple>
    #include <stdfloat>
    #include "IOperand.hpp"
    #include <stdexcept>
    #include "FactoryOperand.hpp"
    #define INSTRUCTION_HPP_

class bistroMatic {
    public:
        bistroMatic();
        ~bistroMatic();
        void add(void);
        void sub(void);
        void mul(void);
        void div(void);
        void mod(void);
        void load(void);
        void pop(void);
        void push(IOperand *object);
        void clear(void);
        void swap(void);
        void display(void);
        void assert(IOperand *object);

    private:
        std::list<IOperand *> stack;
};
void usage(void);
void parsing(void);
bool checkArgs(std::string cmd, std::string _find);
void verifyCommands(std::string cmd, std::string type);
void verifyTypePresence(std::string cmd, std::string type);
void verifyType(std::string cmd, std::string type);
std::string remove_comment(std::string &input);
std::string remove_space(std::string str);
#endif /* !INSTRUCTION_HPP_ */
