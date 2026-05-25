/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Cyberfoundry
*/

#include "Cyberfoundry.hpp"

bool Mondas::Cyberfoundry::takeEnergy(unsigned int take)
{
    if (_natural < take)
        return false;

    _natural -= take;
    return true;
}

void Mondas::Cyberfoundry::restoreEnergy(unsigned int restore)
{
    _natural += restore;
}

Mondas::Cyberfoundry::Cyberfoundry(unsigned int natural_energy_ressouces) : _natural(natural_energy_ressouces)
{
    std::cout << "A new Cyberfoundry has opened." << std::endl;
}

Mondas::Cyberfoundry::~Cyberfoundry()
{
    std::cout << "A Cyberfoundry has closed." << std::endl;
}

Mondas::Cyberman* Mondas::Cyberfoundry::buildCyberman(Mondas::Human& human)
{
    bool state = takeEnergy(50 + human.getIq());

    if (state == false) {
        std::cout << "Not enough energy to build a new Cyberman." << std::endl;
        return nullptr;
    }
    Mondas::Cyberman *ptr;

    std::cout << "Building a new Cyberman from '" << human.getName() << "'." << std::endl;
    ptr = new Mondas::Cyberman(human);
    return ptr;
}

Mondas::Cyberleader* Mondas::Cyberfoundry::buildCyberleader(Mondas::Human& human)
{
    bool state = takeEnergy(150 + (human.getIq() * 2));

    if (state == false) {
        std::cout << "Not enough energy to build a new Cyberleader." << std::endl;
        return nullptr;
    }
    Mondas::Cyberleader *ptr;

    std::cout << "Building a new Cyberleader from '" << human.getName() << "'." << std::endl;
    ptr = new Mondas::Cyberleader(human);
    return ptr;
}

void Mondas::Cyberfoundry::recycle(Mondas::Cyberman*& cyberMan)
{
    if (cyberMan == nullptr) {
        std::cout << "Nothing to recycle." << std::endl;
    } else {
        std::cout << "Recycling Cyberman '" << cyberMan->getCname() << "'." << std::endl;
        delete cyberMan;
        cyberMan = nullptr;
        restoreEnergy(50);
    }
}

void Mondas::Cyberfoundry::recycle(Mondas::Cyberleader*& cyberLeader)
{
    if (cyberLeader == nullptr) {
        std::cout << "Nothing to recycle." << std::endl;
    } else {
        std::cout << "Recycling Cyberleader '" << cyberLeader->getClname() << "'." << std::endl;
        delete cyberLeader;
        cyberLeader = nullptr;
        restoreEnergy(150);
    }
}
