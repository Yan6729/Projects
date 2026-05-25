/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, Jan, 2026                                                     *
 * Title           - G-PDG-300-COT-3-1-PDGRUSH4-9                                       *
 * Description     -                                                                    *
 *     OSKernelModule                                                                   *
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
#include "../../include/modules/OSKernelModule.hpp"
#include <sys/utsname.h>

Krell::OSKernelModule::OSKernelModule() 
{

}

Krell::OSKernelModule::~OSKernelModule()
{

}

void Krell::OSKernelModule::update()
{
    struct utsname info;
    if (uname(&info) == -1) {
        return; 
    }

    std::string data = info.sysname;
    data += " ";
    data += info.release;

    _data["OS / Kernel"] = data;
}

std::string Krell::OSKernelModule::getName() const
{
    return "OS / Kernel";
}

std::map<std::string, std::string> Krell::OSKernelModule::getData() const
{
    return _data;
}
