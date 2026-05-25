/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Raspberry
*/

#ifndef RASPBERRY_HPP_
    #include "ABerry.hpp"
    #define RASPBERRY_HPP_

class Raspberry : virtual public ABerry {
    public:
        Raspberry();
        ~Raspberry();
        IFruit *clone()  const override;

    protected:
    private:
};

#endif /* !RASPBERRY_HPP_ */
