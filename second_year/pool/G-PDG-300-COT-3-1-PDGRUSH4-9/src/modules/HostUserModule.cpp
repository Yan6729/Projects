/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, Jan, 2026                                                     *
 * Title           - G-PDG-300-COT-3-1-PDGRUSH4-9                                       *
 * Description     -                                                                    *
 *     HostUserModule                                                                   *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *         ░        ░       ░░        ░        ░        ░░      ░░  ░░░░  ░             *
 *         ▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒  ▒▒▒▒  ▒             *
 *         ▓      ▓▓▓       ▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓      ▓▓▓  ▓▓▓▓▓▓▓        ▓             *
 *         █  ███████  ██████████  ███████  ████  ███████  ████  █  ████  █             *
 *         █        █  ███████        ████  ████        ██      ██  ████  █             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "../../include/modules/HostUserModule.hpp"
#include <unistd.h>
#include <pwd.h>

Krell::HostUserModule::HostUserModule()
{}

Krell::HostUserModule::~HostUserModule()
{}

void Krell::HostUserModule::update(){
    char hostname[256];
    gethostname(hostname, sizeof(hostname));

    struct passwd *pw = getpwuid(getuid());
    
    std::string data = "User: ";
    data += pw->pw_name;
    data += " | Host: ";
    data += hostname;

    _data.insert({"Host / user", data});
}

std::string Krell::HostUserModule::getName() const{
    return "Host / user";
}
std::map<std::string, std::string> Krell::HostUserModule::getData() const {
    return _data;
}
