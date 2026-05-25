/*
** EPITECH PROJECT, 2026
** IDisplay.hpp
** File description:
** IDisplay.hpp
*/

#pragma once
#include <vector>
#include "IModule.hpp"
#include "modules/Battery.hpp"
#include "modules/CpuModule.hpp"
#include "modules/Date_time.hpp"
#include "modules/DateTimeModule.hpp"
#include "modules/DiskUsage.hpp"
#include "modules/HostUserModule.hpp"
#include "modules/Network.hpp"
#include "modules/OSKernelModule.hpp"
#include "modules/ProcessModule.hpp"
#include "modules/RamModule.hpp"

namespace Krell {
    class IModule;

    class IDisplay {
        public:
            virtual ~IDisplay() {}
            virtual void init() = 0;
            virtual void stop() = 0;
            virtual void Events() = 0;
            virtual void display_modules(const std::vector<IModule*>& modules) = 0;
    };
}
