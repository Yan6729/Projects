/*
** EPITECH PROJECT, 2026
** Core.hpp
** File description:
** Core.hpp
*/

#pragma once
#include <vector>
#include "IModule.hpp"
#include "IDisplay.hpp"

namespace Krell {
class MonitorCore {
public:
    MonitorCore();
    ~MonitorCore();

    void setDisplay(IDisplay* display);
    void addModule(IModule* module);
    void removeModule(IModule* module);
    void run();
    void stop();

private:
    std::vector<IModule*> _modules;
    IDisplay* _display;
    bool _running;
};
}