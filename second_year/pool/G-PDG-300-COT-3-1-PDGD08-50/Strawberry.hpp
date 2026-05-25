/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Strawberry
*/

#ifndef STRAWBERRY_HPP_
    #include "ABerry.hpp"
    #define STRAWBERRY_HPP_

class Strawberry : virtual public ABerry {
    public:
        Strawberry();
        ~Strawberry();
        IFruit *clone() const override;

    protected:
};

#endif /* !STRAWBERRY_HPP_ */
