/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** FruitUtils
*/

#include "FruitUtils.hpp"

FruitUtils::FruitUtils()
{
}

FruitUtils::~FruitUtils()
{
}

void FruitUtils::sort(FruitBox& unsorted, FruitBox& lemon, FruitBox& citrus, FruitBox& berry)
{
    unsigned int size_unsorted = unsorted.nbFruits();
    IFruit *fruit;
    FruitBox stock(size_unsorted);

    bool success = false;
    for (unsigned int a = 0; a < size_unsorted; a++) {
        if ((fruit = unsorted.popFruit())) {
            if (dynamic_cast<Lemon *>(fruit)) {
                success = lemon.pushFruit(fruit);
            } else if (dynamic_cast<ACitrus *>(fruit)) {
                success = citrus.pushFruit(fruit);
            } else if (dynamic_cast<ABerry *>(fruit)) {
                success = berry.pushFruit(fruit);
            } else {
                unsorted.pushFruit(fruit);
            }
            if (success == false) {
                unsorted.pushFruit(fruit);
            }
        }
    }
}

FruitBox** FruitUtils::pack(IFruit** fruits, unsigned int boxSize)
{
    if (boxSize == 0) {
        return nullptr;
    }

    int countFruit = 0;
    for (; fruits[countFruit] != nullptr; countFruit++);

    int nbBoxes = (countFruit + boxSize - 1) / boxSize;
    FruitBox **packFruit = new FruitBox *[nbBoxes + 1];

    for (int a = 0; a < nbBoxes; a++) {
        packFruit[a] = new FruitBox(boxSize);
    }

    unsigned int c = 0;
    for (unsigned int b = 0; fruits[b] != nullptr; b++) {
        packFruit[c]->pushFruit(fruits[b]);
        fruits[b] = nullptr;
        if (packFruit[c]->IsFull()) {
            c += 1;
        }
    }
    packFruit[nbBoxes] = nullptr;
    return packFruit;
}

IFruit** FruitUtils::unpack(FruitBox** fruitBoxes)
{
    if (fruitBoxes == nullptr) {
        return nullptr;
    }
    int nbFruits = 0;
    for (int a = 0; fruitBoxes[a] != nullptr; a++)
        nbFruits += fruitBoxes[a]->nbFruits();

    std::cout << nbFruits << std::endl;
    if (nbFruits == 0) {
        return nullptr;
    }
    IFruit **unpackFruit = new IFruit *[nbFruits + 1];

    int c = 0;
    for (int a = 0; fruitBoxes[a] != nullptr; a++) {
        IFruit *fruit;
        while ((fruit = fruitBoxes[a]->popFruit())) {
            unpackFruit[c] = fruit;
            c++;
        }
        
    }
    unpackFruit[nbFruits] = nullptr;
    return unpackFruit;
}
