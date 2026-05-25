/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** ICharacter
*/

#ifndef ICHARACTER_HPP_
    #include <iostream>
    #include <string>
    #include <fstream>
    #include <iomanip>
    #include <cstdio>
    #include <filesystem>
    #include <list>
    #include <iterator>
    #include <cstdlib>
    #include <ctime>
    #include "PoisonPotion.hpp"
    #include "PowerPotion.hpp"
    #include "HealthPotion.hpp"
    #define ICHARACTER_HPP_

class IPotion;

class ICharacter {
    public:
        virtual const std::string& getName(void) = 0;
        virtual int getPower(void) const = 0;
        virtual int getHp(void) const = 0;
        virtual void addPower(int power) = 0;
        virtual void addHp(int hp) = 0;
        virtual int attack(void) = 0;
        virtual int special(void) = 0;
        virtual void rest(void) = 0;
        virtual void damage(int damage) = 0;
        virtual ~ICharacter() {};
        virtual void drink(const HealthPotion& potion) = 0;
        virtual void drink(const PoisonPotion& potion) = 0;
        virtual void drink(const PowerPotion& potion) = 0;
        virtual void drink(const IPotion& potion) = 0;

    private:
};

#endif /* !ICHARACTER_HPP_ */
