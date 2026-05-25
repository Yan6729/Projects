/*
** EPITECH PROJECT, 2026
** ProcessModule.cpp
** File description:
** ProcessModule.cpp
*/

#include "../../include/modules/ProcessModule.hpp"
#include <string>
#include <dirent.h>
#include <fstream>
#include <sstream>
#include <algorithm>

namespace Krell {
    ProcessModule::ProcessModule() {}
    ProcessModule::~ProcessModule() {}

    std::string ProcessModule::getName() const
    {
        return "Processes";
    }

    std::map<std::string, std::string> ProcessModule::getData() const
    {
        return _data;
    }

    std::string ProcessModule::getProcessName(int pid) const
    {
        std::ifstream file("/proc/" + std::to_string(pid) + "/comm");
        std::string name;

        if (file)
            std::getline(file, name);
        return name;
    }

    long ProcessModule::getProcessMemory(int pid) const {
        std::ifstream file("/proc/" + std::to_string(pid) + "/status");
        std::string line;

        while (std::getline(file, line)) {
            if (line.rfind("VmRSS:", 0) == 0) {
                std::istringstream iss(line);
                std::string key;
                long value;
                std::string unit;

                iss >> key >> value >> unit;
                return value;
            }
        }
        return 0;
    }

    void ProcessModule::update() {
        _data.clear();

        DIR* dir = opendir("/proc");
        if (!dir)
            return;

        struct dirent* entry;
        int processCount = 0;

        struct ProcInfo {
            std::string name;
            long memory;
        };

        std::vector<ProcInfo> processes;

        while ((entry = readdir(dir)) != nullptr) {
            if (entry->d_type != DT_DIR)
                continue;

            std::string name = entry->d_name;
            if (name.empty() ||
                !std::all_of(name.begin(), name.end(), ::isdigit))
                continue;

            int pid = std::stoi(name);
            processCount++;

            std::string procName = getProcessName(pid);
            long mem = getProcessMemory(pid);

            if (!procName.empty() && mem > 0) {
                processes.push_back({procName, mem});
            }
        }

        closedir(dir);

        _data["Total processes"] = std::to_string(processCount);

        std::sort(processes.begin(), processes.end(),
                  [](const ProcInfo& a, const ProcInfo& b) {
                      return a.memory > b.memory;
                  });
        int limit = std::min(5, static_cast<int>(processes.size()));
        for (int i = 0; i < limit; i++) {
            long memMB = processes[i].memory;
            _data["Top " + std::to_string(i + 1)] =
                processes[i].name + " - " + std::to_string(memMB) + " KB";
        }
    }
}
