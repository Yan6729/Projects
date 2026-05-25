/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Lemon
*/

#ifndef LEMON_HPP_
    #include "ACitrus.hpp"
    #define LEMON_HPP_

class Lemon : public ACitrus {
    public:
        Lemon();
        ~Lemon();
        IFruit *clone() const override;
    protected:
};

#endif /* !LEMON_HPP_ */
