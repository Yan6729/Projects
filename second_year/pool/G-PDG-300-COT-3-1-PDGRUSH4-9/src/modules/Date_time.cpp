/*
** EPITECH PROJECT, 2026
** Date_time.cpp
** File description:
** Date_time.hpp
*/

#include "../../include/modules/Date_time.hpp"

Krell::Date_time::Date_time() : hour(0), minute(0), second(0), now(0)
{
}

void Krell::Date_time::update() {
        now = std::time(nullptr);
        std::tm* ltm = std::localtime(&now);
        
        hour = ltm->tm_hour;
        minute = ltm->tm_min;
        second = ltm->tm_sec;
}

std::string Krell::Date_time::getName() const
{
    return "Time";
}

std::map<std::string, std::string> Krell::Date_time::getData() const
{
    std::map<std::string, std::string> time;
    std::stringstream tt;
    std::string val_hour = std::to_string(hour);
    std::string val_min = std::to_string(minute);
    std::string val_sec = std::to_string(second);
    std::vector<std::string > value = {val_hour, val_min, val_sec};
            for (size_t i = 0; i < value.size(); i++) {
                tt << value[i];
                if (i != value.size() - 1) {
                    tt << ":";
                }
            }
            std::string val = tt.str();
    time["time"] = val;
    return time;
}
