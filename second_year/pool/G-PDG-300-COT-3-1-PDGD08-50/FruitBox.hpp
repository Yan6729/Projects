/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
    #include "IFruit.hpp"
#define FRUITBOX_HPP_

class FruitBox {
    public:
        FruitBox(unsigned int size);
        FruitBox(const FruitBox& otherfruit) = delete;
        ~FruitBox();
        unsigned int getSize(void) const;
        unsigned int nbFruits(void) const;
        bool pushFruit(IFruit *fruit);
        bool IsFull(void) const;
        std::list<IFruit *> getList(void) const;
        IFruit *popFruit(void);
        bool isInTheBox(IFruit *fruit);
        std::list<std::string> toString(void) const;
        FruitBox operator=(const FruitBox &otherFruit) = delete;

    private:
        std::list<IFruit *> _fruitbox;
        unsigned int _size;
};

std::ostream& operator<<(std::ostream& redirect, const FruitBox& fruitbox);
#endif /* !FRUITBOX_HPP_ */
