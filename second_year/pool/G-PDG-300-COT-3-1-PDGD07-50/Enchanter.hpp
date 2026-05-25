/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Enchanter
*/

#ifndef ENCHANTER_HPP_
    #include "Peasant.hpp"
    #define ENCHANTER_HPP_

class Enchanter : virtual public Peasant {
    public:
        Enchanter(const std::string& name, int power);
        ~Enchanter();
        int attack(void);
        int special(void);
        void rest(void);
    private:
};

#endif /* !ENCHANTER_HPP_ */
