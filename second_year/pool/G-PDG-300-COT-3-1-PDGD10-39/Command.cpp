/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Command
*/

#include "Command.hpp"

Command::Error::Error(std::string message) : _msg(message)
{}

const char *Command::Error::what() const noexcept
{
    return _msg.c_str();
}

Command::Command()
{
}

Command::~Command()
{
}

void Command::registerCommand(const std::string& name, const std::function<void()>& function)
{
    if (_map.count(name) == 0)
        _map.emplace(name, function);
    else
        throw Command::Error("Already registered command");
}

void Command::executeCommand(const std::string& name)
{
    if (_map.count(name) == 0)
        throw Command::Error("Unknow command");
    else
        _map[name]();
}
