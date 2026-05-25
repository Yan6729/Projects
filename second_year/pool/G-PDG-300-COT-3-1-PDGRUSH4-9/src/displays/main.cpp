/*
** EPITECH PROJECT, 2026
** G-PDG-300-COT-3-1-PDGRUSH4-9
** File description:
** main
*/

#include "../../include/MonitorCore.hpp"
#include "../../include/displays/NcurseDisplay.hpp"
#include "../../include/displays/SfmlDisplay.hpp"
#include "../../include/modules/CpuModule.hpp"
#include "../../include/modules/RamModule.hpp"
#include "../../include/modules/Battery.hpp"
#include "../../include/modules/Network.hpp"
#include "../../include/modules/DiskUsage.hpp"
#include "../../include/modules/HostUserModule.hpp"
#include "../../include/modules/OSKernelModule.hpp"
#include "../../include/modules/DateTimeModule.hpp"
#include "../../include/modules/ProcessModule.hpp"

int main(int ac, char *av[])
{
    Krell::MonitorCore core;

    if (ac == 1 || ac > 2) {
        std::cout << "Usage:" << std::endl;
        std::cout << "        -h (--help):      try this to see how the program work" << std::endl;
        std::cout << "        -g (--graphical): see the sfml displaying" <<  std::endl;
        std::cout << "        -t (--text):      see the ncurses displaying" << std::endl;
        exit(-1);
    }
    std::string arg = av[1];
    if (arg != "-h" && arg != "--help" && arg != "-g" && arg != "--graphical" && arg != "-t" && arg != "--text") {
        std::cout << "Usage:" << std::endl;
        std::cout << "        -h (--help):      try this to see how the program work" << std::endl;
        std::cout << "        -g (--graphical): see the sfml displaying" <<  std::endl;
        std::cout << "        -t (--text):      see the ncurses displaying" << std::endl;
        exit(-1);
    }
    if (arg == "-h" || arg == "--help") {
        std::cout << "Usage:" << std::endl;
        std::cout << "        -g (--graphical): see the sfml mode's displaying of all the module (cpu, ram, date...)\n"
                  << "                          You can click on ne keyboard touch 's' to switch to text mode.\n"
                  << "                          Thanks for using our program, we hope you'll have a great journey." << std::endl;
        std::cout << "        -t (--text):      see the ncurses mode's displaying of all the module (cpu, ram, date...)\n"
                  << "                          You can click on ne keyboard touch 's' to switch to graphical mode.\n"
                  << "                          Thanks for using our program, we hope you'll have a great journey." << std::endl;
    }
    int count = getCpuCount();

    for (int a = 0; a < count-1; a++) {
         core.addModule(new Krell::CpuInfo(std::to_string(a)));
    }

    core.addModule(new Krell::RamModule());
    core.addModule(new Krell::Battery());
    core.addModule(new Krell::Network());
    core.addModule(new Krell::DiskModule());
    core.addModule(new Krell::HostUserModule());
    core.addModule(new Krell::OSKernelModule());
    core.addModule(new Krell::DateTimeModule());
    core.addModule(new Krell::ProcessModule());

    if (arg == "-g" || arg == "--graphical")
        core.setDisplay(new Krell::SfmlDisplay);
    else if (arg == "-t" || arg == "--text")
        core.setDisplay(new Krell::NcursesDisplay);
    core.run();

    return 0;
}
