/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** error_case
*/

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <regex>
#include <list>
#include <stdexcept>

std::string remove_space(std::string str)
{
    str.erase(0,str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
    std::string modifStr = std::regex_replace(str, std::regex("\\s+"), " ");
    return modifStr;
}

std::string remove_comment(std::string &input) {
    size_t pos = input.find(";");

    if (pos != std::string::npos)
	return remove_space(input.substr(0,pos));
    return remove_space(input);
}

void verifyType(std::string cmd, std::string type)
{
    if ((cmd == "push" || cmd == "assert" || cmd == "load" || cmd == "store" || cmd == "display")
        && (type == "int8" || type == "int16" ||
        type == "int32" || type == "int64" ||
        type == "float32" || type == "float64")) {
            return;
    } else {
        throw std::runtime_error(type + ": Invalid type.");
        return;
    }
}

bool checkArgs(std::string cmd, std::string _find)
{
    if ((cmd.find(_find) != std::string::npos) && cmd != _find) {
        throw std::runtime_error(_find + " Isn't suppose to take any arguments");
        return true;
    }
    return false;
}

void verifyCommands(std::string cmd, std::string type)
{
    if (cmd == "push" || cmd == "pop" ||
        cmd == "display" || cmd == "clear" ||
        cmd == "swap" || cmd == "assert" ||
        cmd == "add" || cmd == "sub" || cmd == "mul" ||
        cmd == "div" || cmd == "mod" || cmd == "load" ||
        cmd == "store" || cmd == "exit") {
            verifyType(cmd, type);
            return;
    } else {
        throw std::runtime_error(cmd + ": Command not found.");
    }
}
