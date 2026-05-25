/*
** EPITECH PROJECT, 2026
** Date_time.hpp
** File description:
** Date_time.hpp
*/

#ifndef DATE_TIME_HPP
    #define DATE_TIME_HPP
    #include "../IModule.hpp"
    #include <iostream>
    #include <ctime>
    #include <iomanip>
    #include <string>
    #include <fstream>
    #include <sstream>
    #include <vector>
namespace Krell {
class Date_time : public IModule{
    public:
        Date_time();
        std::string getName() const override;
        void update() override;
        std::map<std::string, std::string> getData() const override;


    protected:
    private:
        int hour;
        int minute;
        int second;
        std::time_t now;
};
}

#endif /* !DATE_TIME_HPP */
