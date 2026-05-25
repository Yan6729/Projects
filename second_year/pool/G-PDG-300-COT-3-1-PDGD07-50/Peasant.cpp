/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Peasant
*/

#include "Peasant.hpp"

Peasant::Peasant(const std::string& name, int power) : _name(name), _power(power)
{
    std::cout << _name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << _name << " is back to his crops." << std::endl;
}

const std::string& Peasant::getName(void)
{
    return _name;
}

int Peasant::getPower(void) const
{
    return _power;
}

int Peasant::getHp(void) const
{
    return _hp;
}

void Peasant::addPower(int power)
{
    if (_power + power > 100) {
        _power = 100;
        return;
    } else if (_power + power <= 0) {
        _power = 0;
    } else
        _power += power;
}

void Peasant::addHp(int hp)
{
    if (_hp + hp > 100) {
        _hp = 100;
        return;
    } else if (_hp + hp <= 0) {
        _hp = 0;
        return;
    } else 
        _hp += hp;
}

void Peasant::damage(int damage)
{
    if ((_hp - damage) > 0) {
        std::cout << _name << " takes " << damage << " damage." << std::endl;
        _hp -= damage;
    } else {
        std::cout << _name << " is out of combat." << std::endl;
        _hp = 0;
    }
}

void Peasant::rest(void)
{
    if (_hp == 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    if (_power + 30 > 100) {
        _power = 100;
    } else 
        _power += 30;
    std::cout << _name << " takes a nap." << std::endl;
}

int Peasant::special(void)
{
    if (_hp == 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
    std::cout << _name << " doesn't know any special move." << std::endl;
    return 0;
}

int Peasant::attack(void)
{
    if (((_power - 10) >= 0) && _hp != 0) {
        _power -= 10;
        std::cout << _name << " tosses a stone." << std::endl;
        return 5;
    } else {
        if (_hp == 0) {
            std::cout << _name << " is out of combat." << std::endl;
            return 0;
        } else if ((_power - 10) < 0) {
            std::cout << _name << " is out of power." << std::endl;
            return 0;
        }
    }
    return 0;
}

void Peasant::drink(const HealthPotion& potion)
{
    potion.apply(*this);
    std::cout << _name << " feels rejuvenated." << std::endl;
}

void Peasant::drink(const PoisonPotion& potion)
{
    potion.apply(*this);
    std::cout << _name << " has been poisoned." << std::endl;
}

void Peasant::drink(const PowerPotion& potion)
{
    potion.apply(*this);
    std::cout << _name << "'s power is restored." << std::endl;
}

void Peasant::drink(const IPotion& potion)
{
    potion.apply(*this);
    std::cout << _name << " drinks a mysterious potion." << std::endl;
}
