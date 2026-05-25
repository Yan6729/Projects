/*
** EPITECH PROJECT, 2026
** ProcessModule.hpp
** File description:
** ProcessModule.hpp
*/

#pragma once
#include "../IModule.hpp"
#include <map>
#include <string>
#include <vector>

namespace Krell {

    class ProcessModule : public IModule {
    private:
        std::map<std::string, std::string> _data;

        std::string getProcessName(int pid) const;
        long getProcessMemory(int pid) const;

    public:
        ProcessModule();
        ~ProcessModule() override;

        std::string getName() const override;
        void update() override;
        std::map<std::string, std::string> getData() const override;
    };
}
