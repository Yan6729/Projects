/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** FruitMixer
*/

#include "FruitMixer.hpp"

FruitMixer::FruitMixer()
{}

FruitMixer::~FruitMixer()
{}

unsigned int FruitMixer::mixFruits(FruitBox& box) const
{
    if (_blade == nullptr) {
        std::cout << "mixer has no blade" << std::endl;
        return 0;
    }
    if (box.nbFruits() == 0) {
        return 0;
    }
    unsigned int vitamin_sum = 0;

    IFruit *_fruit;

    std::list<IFruit *> contain;
    while ((_fruit = box.popFruit())) {
        if (_fruit->getVitamins() == 0)
            contain.push_front(_fruit);
        vitamin_sum += _fruit->getVitamins();
    }

    for (IFruit *fruit : contain) {
        box.pushFruit(fruit);
    }
    return vitamin_sum;
}

void FruitMixer::setBlade(IBlade* blade)
{
    if (_blade != nullptr) {
        delete(_blade);
    }
    _blade = blade;
}
