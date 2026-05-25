/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** StupidUnitConverter
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class StupidUnitConverter
{
    public:
        double temperature;
        std::string scale;
    
        int convert(void) {
            if (scale.compare("Celsius") == 0) {
                double fartemp = ((9.0 / 5.0) * temperature) + 32;
                std::cout << std::setw(16) << std::fixed << std::setprecision(3) << fartemp << std::setw(16) << "Fahrenheit" << std::endl;
                return 0;
            } else if (scale.compare("Fahrenheit") == 0) {
                double celtemp = 5.0 / 9.0 * (temperature - 32);
                std::cout << std::setw(16) << std::fixed << std::setprecision(3) << celtemp << std::setw(16) << "Celsius" << std::endl;
                return 0;
            } else {
                exit(84);
            }
        }
        StupidUnitConverter(double temp, std::string state) : temperature(temp), scale(state) {};
        ~StupidUnitConverter() {};
};

void soloResult(std::string line)
{
    double temp;
    std::string scale;
    std::stringstream values(line);

    values >> temp >> scale;

    if (temp != 0 && scale.empty()) {
        exit(84);
    }
    StupidUnitConverter solo(temp, scale);
    solo.convert();
}

int main(void)
{
    std::string line;

    while (std::getline (std::cin, line)) {
        if (!line.empty())
            soloResult(line);
        else
            return 84;
    }
}
