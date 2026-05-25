/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** main
*/

#include "../../include/Core.hpp"

#include <iostream>
#include <string>

static void usage(const std::string &prog)
{
    std::cerr << "Usage:   " << prog << " <path/to/graphical_library.so>\n"
              << "Example: " << prog << " ./lib/arcade_ncurses.so\n";
}

static bool endsWith(const std::string &str, const std::string &suffix)
{
    if (suffix.size() > str.size())
        return false;
    return str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Error: expected exactly 1 argument, got "
                  << (argc - 1) << ".\n";
        usage(argv[0]);
        return 84;
    }

    const std::string lib(argv[1]);

    if (!endsWith(lib, ".so")) {
        std::cerr << "Error: '" << lib << "' is not a shared library (.so).\n";
        return 84;
    }

    try {
        Arcade::Core core(lib);
        core.run();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 84;
    }

    return 0;
}