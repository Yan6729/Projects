/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** ABerry
*/

#ifndef ABERRY_HPP_
    #include "AFruit.hpp"
    #define ABERRY_HPP_

class ABerry : virtual public AFruit {
    public:
        ABerry(const std::string& name, unsigned int vitamins);
        ~ABerry();

    protected:
};

#endif /* !ABERRY_HPP_ */
