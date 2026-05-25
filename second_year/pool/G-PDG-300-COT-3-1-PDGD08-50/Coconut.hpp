/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Coconut
*/

#ifndef COCONUT_HPP_
    #include "ANut.hpp"
    #define COCONUT_HPP_

class Coconut : virtual public ANut {
    public:
        Coconut();
        ~Coconut();
        IFruit *clone() const override;

    private:
};

#endif /* !COCONUT_HPP_ */
