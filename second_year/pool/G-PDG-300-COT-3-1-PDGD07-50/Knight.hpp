/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Knight
*/

#ifndef KNIGHT_HPP_
    #include "Peasant.hpp"
    #define KNIGHT_HPP_

class Knight : virtual public Peasant {
    public:
        Knight(const std::string& name, int power);
        ~Knight();
        int attack(void);
        int special(void);
        void rest(void);
    private:
};

#endif /* !KNIGHT_HPP_ */
