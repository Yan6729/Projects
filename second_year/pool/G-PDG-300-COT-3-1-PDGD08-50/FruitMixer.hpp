/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** FruitMixer
*/

#ifndef FRUITMIXER_HPP_
    #include "IFruitMixer.hpp"
    #define FRUITMIXER_HPP_

class FruitMixer : public IFruitMixer {
    public:
        FruitMixer();
        ~FruitMixer();
        unsigned int mixFruits(FruitBox& box) const;
        void setBlade(IBlade* blade);

    private:
        IBlade *_blade = nullptr;
};

#endif /* !FRUITMIXER_HPP_ */
