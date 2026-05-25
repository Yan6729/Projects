/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** IPotion
*/

#ifndef IPOTION_HPP_
    #define IPOTION_HPP_

class ICharacter;

class IPotion {
    public:
        virtual ~IPotion() {};
        virtual int apply(ICharacter& character) const = 0;
    private:
};

#endif /* !IPOTION_HPP_ */
