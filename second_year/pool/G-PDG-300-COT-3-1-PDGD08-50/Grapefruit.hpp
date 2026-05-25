/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Grapefruit
*/

#ifndef GRAPEFRUIT_HPP_
    #include "ACitrus.hpp"
    #define GRAPEFRUIT_HPP_

class Grapefruit : virtual public ACitrus {
    public:
        Grapefruit();
        ~Grapefruit();
        IFruit *clone() const override;

    protected:
    private:
};

#endif /* !GRAPEFRUIT_HPP_ */
