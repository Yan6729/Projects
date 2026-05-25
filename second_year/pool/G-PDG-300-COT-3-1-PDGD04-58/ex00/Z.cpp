/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Z
*/

#include <iostream>

class Z
{
    public:
        std::string str;

        Z(std::string z) : str(z) {};
        ~Z() {};
};

int main(void)
{
    Z content("z");
    std::cout << content.str << std::endl;
}