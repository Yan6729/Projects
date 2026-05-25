/*
** EPITECH PROJECT, 2026
** Network.cpp
** File description:
** Network.cpp
*/

#include "../../include/modules/Network.hpp"

Krell::Network::Network()
{
}

std::string Krell::Network::getName() const
{
    return "Network";
}

std::string Net(std::string interfaceName)
{
    std::ifstream file("/proc/net/dev");
    std::string line;
    std::getline(file, line);
    std::getline(file, line);
    std::stringstream tt;

    while (std::getline(file, line)) {
        if (line.find(interfaceName) != std::string::npos) {
            std::stringstream ss(line);
            std::string iface;
            std::string dummy, rx, tx;
            std::string packets, errs, drop;
            std::string packets1, errs1, drop1;
            ss >> iface >> rx >> packets >> errs >> drop >> dummy >> dummy >> dummy >> dummy >> tx >> packets1 >> errs1 >> drop1 >> dummy;
            std::vector<std::string > value = {iface, rx, packets, errs, drop,"\t", tx, packets1, errs1, drop1};
            for (size_t i = 0; i < value.size(); i++) {
                tt << value[i];
                if (i != value.size() - 1) {
                    tt << " ";
                }
            }
            std::string val = tt.str();
            return val;
        }
    }
    return nullptr;
}

void Krell::Network::update()
{
    std::ifstream file("/proc/net/dev");
    std::string line;
    std::getline(file, line);
    std::getline(file, line);
    

    while (std::getline(file, line)) {
        std::stringstream tt(line);
        std::string new_iface;
        tt >> new_iface;
        std::string ret = Net(new_iface);
        monNet[new_iface] =  ret;
    };
}

std::map<std::string, std::string> Krell::Network::getData() const
{
    return monNet;
}
