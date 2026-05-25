/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
    #include "Priest.hpp"
    #include "Knight.hpp"
    #define PALADIN_HPP_

class Paladin : public Knight, public Priest{
    public:
        Paladin(const std::string& name, int power);
        ~Paladin();
        int attack(void);
        int special(void);
        void rest(void);

    private:
};

#endif /* !PALADIN_HPP_ */
