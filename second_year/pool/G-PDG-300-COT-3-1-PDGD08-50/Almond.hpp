/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Almond
*/

#ifndef ALMOND_HPP_
    #include "ANut.hpp"
    #define ALMOND_HPP_

class Almond : virtual public ANut {
    public:
        Almond();
        ~Almond();
        IFruit *clone() const override;

    protected:
};

#endif /* !ALMOND_HPP_ */
