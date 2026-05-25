/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Cpu_info
*/

#ifndef CPU_INFO_HPP_
    #include "../IModule.hpp"
    
    #define CPU_INFO_HPP_

namespace Krell {
    class CpuInfo : public IModule {
        public:
            CpuInfo(std::string name);
            ~CpuInfo();
            std::string getName() const;
            void update();
            std::map<std::string, std::string> getData() const;

        private:
            std::string _cpu_name = "";
            std::map<std::string, std::string> _cpu_data;
    };
}

std::map<std::string, std::string> getProcInfo(std::string name);
#endif
