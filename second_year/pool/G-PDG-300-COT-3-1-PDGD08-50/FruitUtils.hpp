/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** FruitUtils
*/

#ifndef FRUITUTILS_HPP_
    #include "FruitBox.hpp"
    #include "Lemon.hpp"
    #include "ABerry.hpp"
    #include "ACitrus.hpp"
    #include "ANut.hpp"
    #define FRUITUTILS_HPP_

class FruitUtils {
    public:
        FruitUtils();
        ~FruitUtils();
        static void sort(FruitBox& unsorted, FruitBox& lemon, FruitBox& citrus, FruitBox& berry);
        static FruitBox** pack(IFruit** fruits, unsigned int boxSize);
        static IFruit** unpack(FruitBox** fruitBoxes);

    private:
};

#endif /* !FRUITUTILS_HPP_ */
