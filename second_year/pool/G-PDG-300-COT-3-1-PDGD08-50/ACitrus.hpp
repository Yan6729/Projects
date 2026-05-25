/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** ACitrus
*/

#ifndef ACITRUS_HPP_
    #include "AFruit.hpp"
    #define ACITRUS_HPP_

class ACitrus : virtual public AFruit {
    public:
        ACitrus(const std::string& name, unsigned int vitamins);
        ~ACitrus();

    protected:
};

#endif /* !ACITRUS_HPP_ */
