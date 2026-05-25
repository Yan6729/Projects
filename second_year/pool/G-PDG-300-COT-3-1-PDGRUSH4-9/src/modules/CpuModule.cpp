/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Cpu_info
*/

#include "../../include/modules/CpuModule.hpp"
#include <thread>   // Required for std::this_thread::sleep_for
#include <chrono>

Krell::CpuInfo::CpuInfo(std::string name)
{
    if (name.find("cpu") != std::string::npos) {
        _cpu_name = name.substr(3);
    } else
        _cpu_name = name;
}

Krell::CpuInfo::~CpuInfo()
{}

void Krell::CpuInfo::update()
{
    if (_cpu_data.empty())
        _cpu_data.clear();
    std::map<std::string, std::string> data = getProcInfo(_cpu_name);
    _cpu_data["processor"] = data["processor"];
    _cpu_data["core id"] = data["core id"];
    _cpu_data["model"] = data["model"];
    _cpu_data["model name"] = data["model name"];
    _cpu_data["cpu family"] = data["cpu family"];
    _cpu_data["core id"] = data["core id"];
    _cpu_data["cpu MHz"] = data["cpu MHz"];
    _cpu_data["stat line"] = data["stat line"];
}

std::map<std::string, std::string> getProcInfo(std::string name) {
    std::ifstream file("/proc/cpuinfo");
    std::string line;
    bool stock = false;
    std::map<std::string, std::string> cpuinfo;

    if (!file.is_open()) {
        perror("Failed to open the \"/proc/cpuinfo\" file");
    }
    cpuinfo.insert({"processor", name});
    while (std::getline(file, line)) {
        if (line.find("processor") != std::string::npos && line.find(name) != std::string::npos) {
            stock = true;
            continue;
        }
        if (stock == true) {
            if (line.empty())
                break;
            size_t pos = line.find(":");
            if (pos != std::string::npos) {
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos+ 1);
                key.erase(0, key.find_first_not_of(" \t"));
                key.erase(key.find_last_not_of(" \t")+1);
                value.erase(0, value.find_first_not_of(" \t"));
                value.erase(value.find_last_not_of(" \t\n")+1);
                cpuinfo.insert({key, value});
            }
        }
    }
    file.close();

    std::ifstream file_("/proc/stat");
    std::string line_;

    if (!file_.is_open()) {
        perror("Failed to open the \"/proc/stat\" file");
    }
    while(std::getline(file_, line_)) {
        if (line_.find("cpu"+name) != std::string::npos) {
            size_t pos_ = ("cpu"+name).size();
            cpuinfo.insert({"stat line", line_.substr(pos_+1)});
        }
    }
    file_.close();
    return cpuinfo;
}

std::map<std::string, std::string> Krell::CpuInfo::getData() const
{
    return _cpu_data;
}

std::string Krell::CpuInfo::getName() const
{
    return "cpu" + _cpu_name;
}
