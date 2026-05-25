/*
** EPITECH PROJECT, 2026
** IModule.hpp
** File description:
** IModule.hpp
*/

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <format>
#include <map>
#include <iomanip>
#include <thread>
#include <chrono>

namespace Krell {
    class IModule {
    public:
        virtual ~IModule() {}
        virtual std::string getName() const = 0;
        virtual void update() = 0;
        virtual std::map<std::string, std::string> getData() const = 0;
    };
}
