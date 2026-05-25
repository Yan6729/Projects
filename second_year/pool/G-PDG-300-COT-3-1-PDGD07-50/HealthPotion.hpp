/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** HealthPotion
*/

#ifndef HEALTHPOTION_HPP_
    #include "IPotion.hpp"
    #define HEALTHPOTION_HPP_

class HealthPotion : public IPotion {
    public:
        HealthPotion();
        ~HealthPotion();
        int apply(ICharacter& character) const override;

    private:
};

#endif /* !HEALTHPOTION_HPP_ */
