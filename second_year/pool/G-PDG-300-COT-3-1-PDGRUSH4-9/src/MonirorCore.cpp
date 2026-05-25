/*
** EPITECH PROJECT, 2026
** Core.cpp
** File description:
** Core.cpp
*/

#include "../include/MonitorCore.hpp"
#include <unistd.h>

namespace Krell {
    MonitorCore::MonitorCore()
        : _display(nullptr), _running(false)
    {}

    MonitorCore::~MonitorCore()
    {
        for (IModule* m : _modules)
            delete m;
        delete _display;
    }

    void MonitorCore::setDisplay(IDisplay* display)
    {
        if (_display)
            _display->stop();
        _display = display;
        if (_display)
            _display->init();
    }

    void MonitorCore::addModule(IModule* module)
    {
        _modules.push_back(module);
    }

    void MonitorCore::removeModule(IModule* module)
    {
        for (auto it = _modules.begin(); it != _modules.end(); it++) {
            if (*it == module) {
                delete *it;
                _modules.erase(it);
                return;
            }
        }
    }

    void MonitorCore::run()
    {
        if (!_display)
            return;
        _running = true;
        if (_display)
            _display->init();
        while (_running) {
            for (IModule* m : _modules)
                m->update();
            if (_display)
                _display->display_modules(_modules);
            usleep(500000);
        }
    }

    void MonitorCore::stop()
    {
        _running = false;
    }
}
