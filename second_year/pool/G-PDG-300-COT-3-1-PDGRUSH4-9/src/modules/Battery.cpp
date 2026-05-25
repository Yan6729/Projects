/*
** EPITECH PROJECT, 2026
** Battery.cpp
** File description:
** Battery.cpp
*/

#include "../../include/modules/Battery.hpp"

Krell::Battery::Battery() : percentage(0), status("Unknown")
{
    batteryPath = "/sys/class/power_supply/BAT0";
}

std::string Krell::Battery::getName() const
{
    return "Battery";
}

void Krell::Battery::update()
{
    std::ifstream capacityFile(batteryPath + "/capacity");
    std::ifstream statusFile(batteryPath + "/status");
    if (capacityFile.is_open()) {
        capacityFile >> percentage;
    }
    if (statusFile.is_open()) {
        std::getline(statusFile, status);
    }
    capacityFile.close();
    statusFile.close();
}
std::map<std::string, std::string> Krell::Battery::getData() const
{
    std::map<std::string, std::string> battery;
    battery["capacity"] = std::to_string(percentage);
    battery["status"] = status;
    return battery;
}

