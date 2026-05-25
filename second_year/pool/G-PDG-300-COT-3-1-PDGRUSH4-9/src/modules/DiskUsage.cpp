/*
** EPITECH PROJECT, 2026
** DiskUsage.cpp
** File description:
** DiskUsage.cpp
*/

#include "../../include/modules/DiskUsage.hpp"
#include <sys/statvfs.h>
#include <sstream>
#include <iomanip>

namespace Krell {
    DiskModule::DiskModule() = default;
    DiskModule::~DiskModule() = default;

    std::string DiskModule::getName() const {
        return "Disk Usage";
    }

    void DiskModule::update() {
        _data.clear();
        struct statvfs ls;
        if (statvfs("/", &ls) == 0) {
            float used = 100.0f * (ls.f_blocks - ls.f_bfree) / ls.f_blocks;
            std::ostringstream ss;
            ss << std::fixed << std::setprecision(1) << used << "%";
            _data["/"] = ss.str();
        }
    }

    std::map<std::string, std::string> DiskModule::getData() const {
        return _data;
    }
}
