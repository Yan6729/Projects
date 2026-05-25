/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** ANut
*/

#ifndef ANUT_HPP_
    #include "AFruit.hpp"
    #define ANUT_HPP_

class ANut : virtual public AFruit {
    public:
        ANut(const std::string& name, unsigned int vitamins);
        ~ANut();

    protected:
};

#endif /* !ANUT_HPP_ */
