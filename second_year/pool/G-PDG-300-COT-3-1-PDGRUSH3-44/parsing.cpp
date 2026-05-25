/*
** EPITECH PROJECT, 2026
** parsing_hpp
** File description:
** parsing of rush3
*/

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <regex>
#include <list>
#include <stdexcept>
#include "instruction.hpp"

OperandType isThisType(std::string type_str)
{
    std::list<std::pair<std::string, OperandType>>type = {
        {"int8", OperandType::Int8},
        {"int16", OperandType::Int16},
        {"int32", OperandType::Int32},
        {"int64", OperandType::Int64},
        {"float32", OperandType::Float32},
        {"float64", OperandType::Float64}
    };

    for (std::pair pair : type) {
        if (pair.first == type_str) {
            return pair.second;
        } else {
            continue;
        }
    }
    return OperandType::Error;
}

void arrithmeticCommands(bistroMatic& object, std::string cmd)
{
    if (cmd == "add")
        object.add();
    if (cmd == "sub")
        object.sub();
    if (cmd == "mul")
        object.mul();
    if (cmd == "mod")
        object.mod();
    if (cmd == "div")
        object.div();
}

void executeCommands(bistroMatic& object, std::string cmd, std::stringstream& buf)
{
    OperandFactory factory;
    std::string type;
    std::string value;

    if (cmd == "push") {
        buf >> type >> value;
        verifyCommands(cmd, type);
        object.push(factory.createOperand(isThisType(type), value));
    }
    if (cmd == "display") {
        object.display();
    }
    if (cmd == "pop") {
        object.pop();
    }
    if (cmd == "assert") {
        buf >> type >> value;
        verifyCommands(cmd, type);
        object.assert(factory.createOperand(isThisType(type), value));
    }
    if (cmd == "swap") {
        object.swap();
    }
    if (cmd == "clear") {
        object.clear();
    }
    if (cmd == "exit") {
        std::exit(EXIT_SUCCESS);
    }
    arrithmeticCommands(object, cmd);
}

void noParameterFunctions(std::string str)
{
    checkArgs(str, "display");
    checkArgs(str, "pop");
    checkArgs(str, "clear");
    checkArgs(str, "exit");
    checkArgs(str, "swap");
    checkArgs(str, "add");
    checkArgs(str, "sub");
    checkArgs(str, "mod");
    checkArgs(str, "div");
    checkArgs(str, "mul");
}

void parsing()
{
    std::string user_input;
    std::string cmd;
    bistroMatic object;


    while (std::getline(std::cin, user_input)) {
        try {
            if (remove_comment(user_input) != "") {
                std::stringstream ss(remove_comment(user_input));
                noParameterFunctions(ss.str());
                ss >> cmd;
                executeCommands(object, cmd, ss);
                ss.clear();
            }
        } catch (const std::runtime_error& e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
            exit(84);
        }
    }
}

int main(int ac, char *av[])
{
    if (ac == 2 && av[1]) {
        usage();
        return 0;
    }
    parsing();
}
