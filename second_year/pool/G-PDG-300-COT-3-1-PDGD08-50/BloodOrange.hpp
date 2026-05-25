/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** BloodOrange
*/

#ifndef BLOODORANGE_HPP_
    #include "Orange.hpp"
    #define BLOODORANGE_HPP_

class BloodOrange : public Orange {
    public:
        BloodOrange();
        ~BloodOrange();
        IFruit *clone() const override;

    private:
};

#endif /* !BLOODORANGE_HPP_ */
