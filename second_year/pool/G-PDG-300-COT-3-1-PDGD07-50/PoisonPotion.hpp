/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** PoisonPotion
*/

#ifndef POISONPOTION_HPP_
    #include "IPotion.hpp"
    #define POISONPOTION_HPP_

class PoisonPotion : public IPotion {
    public:
        PoisonPotion();
        ~PoisonPotion();
        int apply(ICharacter& character) const override;

    private:
};

#endif /* !POISONPOTION_HPP_ */
