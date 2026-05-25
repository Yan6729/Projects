/*
** EPITECH PROJECT, 2026
** Battery.hpp
** File description:
** Battery.hpp
*/

#ifndef BATTERY_HPP
    #define BATTERY_HPP
    #include "../IModule.hpp"
    #include <iostream>
    #include <string>
    #include <fstream>
    #include <sstream>
    #include <vector>

namespace Krell {
    class Battery : public IModule{
        public:
            Battery();
            std::string getName() const override;
            void update() override;
            std::map<std::string, std::string> getData() const override;

        protected:
        private:
            int percentage;
            std::string status;
            std::string batteryPath;
    };
}

#endif /* !BATTERY_HPP */
