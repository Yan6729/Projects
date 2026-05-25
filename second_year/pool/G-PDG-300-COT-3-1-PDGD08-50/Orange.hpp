/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Orange
*/

#ifndef ORANGE_HPP_
    #include "ACitrus.hpp"
    #define ORANGE_HPP_

class Orange : virtual public ACitrus {
    public:
        Orange();
        ~Orange();
        IFruit *clone() const override;

    protected:
};

#endif /* !ORANGE_HPP_ */
