/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** PowerPotion
*/

#ifndef POWERPOTION_HPP_
    #include "IPotion.hpp"
    #define POWERPOTION_HPP_

class PowerPotion : public IPotion {
    public:
        PowerPotion();
        ~PowerPotion();
        int apply(ICharacter& character) const override;

    private:
};

#endif /* !POWERPOTION_HPP_ */
