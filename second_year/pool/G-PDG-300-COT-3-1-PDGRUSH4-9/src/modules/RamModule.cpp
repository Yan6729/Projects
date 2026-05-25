/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** RamModule
*/

#include "../../include/modules/RamModule.hpp"

Krell::RamModule::RamModule()
{
}

Krell::RamModule::~RamModule()
{
}

std::map<std::string, double> getMemInfo(void)
{
    std::ifstream file("/proc/meminfo");
    std::map<std::string, double> meminfo;
    std::string line = "";
    std::string name;
    std::string sep;
    double value;

    while (std::getline(file, line)) {
        std::stringstream buf(line);
        buf >> name >> value;
        name.erase(name.size()-1, ':');
        meminfo.insert({name, value});
        buf.clear();
    }
    return meminfo;
}

std::string Krell::RamModule::getName() const
{
    return "Ram module";
}

std::map<std::string, std::string> Krell::RamModule::getData() const
{
    return _ramInfo;
}

std::string convert_to_string(double num)
{
    std::stringstream ss;

    ss << std::fixed << std::setprecision(1) << num;

    return ss.str(); 
}

void Krell::RamModule::update(void)
{
    std::map<std::string, double> meminfo = getMemInfo();

    _ramInfo["MemTotal"] = convert_to_string(meminfo["MemTotal"]/1024);
    _ramInfo["MemFree"] = convert_to_string(meminfo["MemFree"]/1024);
    _ramInfo["MemAvailable"] = convert_to_string(meminfo["MemAvailable"]/1024);
    _ramInfo["buff/cache"] = convert_to_string((meminfo["Buffers"] + meminfo["Cached"] + meminfo["SReclaimable"])/1024);
    _ramInfo["SwapTotal"] = convert_to_string(meminfo["SwapTotal"]/1024);
    _ramInfo["SwapFree"] = convert_to_string(meminfo["SwapFree"]/1024);
    _ramInfo["MemUsed"] = convert_to_string((meminfo["MemTotal"]-meminfo["MemAvailable"])/1024);
    _ramInfo["SwapUsed"] = convert_to_string((meminfo["SwapTotal"]-meminfo["SwapFree"]) / 1024);
}
