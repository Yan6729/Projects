/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Cyberman
*/

#include "Human.hpp"

Mondas::Cyberman::Cyberman(Human& address_humain) : _human(address_humain)
{
    _cname = _human.getName();
    replaceLetter(_cname);
    std::cout << _cname << ": Unit activated." << std::endl;
}

Mondas::Cyberman::~Cyberman()
{
    std::cout << _cname << ": Unit deactivated." << std::endl;
}

void lowerSpecificChar(std::string& str)
{
    std::string str2 = "";

    for (std::size_t a = 0; a < str.size(); a++) {
        if (str[a] == 'A' ||
            str[a] == 'B' ||
            str[a] == 'E' ||
            str[a] == 'G' ||
            str[a] == 'I' ||
            str[a] == 'L' ||
            str[a] == 'O' ||
            str[a] == 'R' ||
            str[a] == 'S' ||
            str[a] == 'T' ||
            str[a] == 'Y') {
                str2.push_back(std::tolower(str[a]));
        } else {
            str2.push_back(str[a]);
        }
    }
    str = str2;
}

Mondas::Cyberman::Inhibitor::Inhibitor() {}

Mondas::Cyberman::Inhibitor::~Inhibitor() {}

bool Mondas::Cyberman::Inhibitor::get(void)
{
    return value;
}

void Mondas::Cyberman::Inhibitor::set(bool newValue)
{
    value = newValue;
}

void replaceLetter(std::string& str)
{
    if (str.empty())
        return;
    lowerSpecificChar(str);
    std::replace(str.begin(), str.end(), 'a', '4');
    std::replace(str.begin(), str.end(), 'b', '8');
    std::replace(str.begin(), str.end(), 'e', '3');
    std::replace(str.begin(), str.end(), 'g', '6');
    std::replace(str.begin(), str.end(), 'i', '1');
    std::replace(str.begin(), str.end(), 'l', '1');
    std::replace(str.begin(), str.end(), 'o', '0');
    std::replace(str.begin(), str.end(), 'r', '2');
    std::replace(str.begin(), str.end(), 's', '5');
    std::replace(str.begin(), str.end(), 't', '7');
    std::replace(str.begin(), str.end(), 'y', '7');
    std::replace(str.begin(), str.end(), ' ', '_');
}

Mondas::Human& Mondas::Cyberman::getHuman(void)
{
    return _human;
}

Mondas::Human& Mondas::Cyberman::getHuman(void) const
{
    return _human;
}

void Mondas::Cyberman::think(void) const
{
    if (_human.getInhibitor() == nullptr) {
        std::cout << _cname << ": Pain, pain, pain..." << std::endl;
    } else {
        if (_human.getInhibitor()->get() == false) {
            std::cout << _cname << ": Pain, pain, pain..." << std::endl;
        } else {
            std::cout << _cname << ": Computation in progress." << std::endl;
        }
    }
}

unsigned int Mondas::Cyberman::getIq(void)
{
    if (_human.getInhibitor() == nullptr) {
        return 0;
    } else {
        if (_human.getInhibitor()->get() == false) {
            return 0;
        } else {
            return _human.getIq();
        }
    }
}

void Mondas::Cyberman::setIq(unsigned int newValue)
{
    if (_human.getInhibitor() == nullptr) {
        return;
    } else {
        _human.setIq(newValue);
    }
}

unsigned int Mondas::Cyberman::getIq(void) const
{
    if (_human.getInhibitor() == nullptr) {
        return 0;
    } else {
        if (_human.getInhibitor()->get() == false) {
            return 0;
        } else {
            return _human.getIq();
        }
    }
}

std::string Mondas::Cyberman::getCname(void) const
{
    return _cname;
}
