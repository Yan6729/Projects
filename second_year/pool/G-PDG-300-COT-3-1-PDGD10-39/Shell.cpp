/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Shell
*/

#include "Shell.hpp"

Shell::Warning::Warning(std::string message) : _msg(message)
{}

const char *Shell::Warning::what() const noexcept
{
    return _msg.c_str();
}

Shell::Error::Error(std::string message) : _msg(message)
{}

const char *Shell::Error::what() const noexcept
{
    return _msg.c_str();
}

Shell::Shell(std::istream& stream) : _shell(stream)
{}

Shell::~Shell()
{}

void Shell::next(void)
{
    std::string _line;

    if (!(std::getline(_shell, _line))) {
        if (_shell.eof()) {
            throw Shell::Error("End of input");
            std::cout << "ctrl+d" << std::endl;
        }
        throw Shell::Error("Input failed");
    }
    _buf.clear();
    _buf.str(_line);
    return;
}
