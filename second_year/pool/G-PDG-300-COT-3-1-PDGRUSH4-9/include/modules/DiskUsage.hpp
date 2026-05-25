/*
** EPITECH PROJECT, 2026
** DiskUsage.hpp
** File description:
** DiskUsage.hpp
*/

#pragma once
#include "../IModule.hpp"
#include <map>
#include <string>

namespace Krell {
    class DiskModule : public IModule {
        private:
            std::map<std::string, std::string> _data;
        public:
            DiskModule();
            ~DiskModule() override;

            std::string getName() const override;
            void update() override;
            std::map<std::string, std::string> getData() const override;
        };
}
