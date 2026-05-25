/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Peasant
*/

#ifndef PEASANT_HPP_
    #include "ICharacter.hpp"
    #define PEASANT_HPP_

class Peasant : public ICharacter {
    public:
        Peasant(const std::string& name, int power);
        const std::string& getName(void);
        int getPower(void) const;
        int getHp(void) const;
        void addPower(int power);
        void addHp(int hp);
        int attack(void);
        int special(void);
        void rest(void);
        void damage(int damage);
        void drink(const HealthPotion& potion);
        void drink(const PoisonPotion& potion);
        void drink(const PowerPotion& potion);
        void drink(const IPotion& potion);
        ~Peasant();

    protected:
        std::string _name;
        int _power;
        int _hp = 100;
};

#endif /* !PEASANT_HPP_ */
