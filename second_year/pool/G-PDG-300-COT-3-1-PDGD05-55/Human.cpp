/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Human
*/

#include "Human.hpp"

Mondas::Human::Human(std::string human_name, unsigned int human_iq, Cyberman::Inhibitor *inhib_ptr) : _name(human_name), _iq(human_iq), _inhib(inhib_ptr)
{
    std::cout << _name << ": I must save Mondas with my IQ of " << _iq << "." << std::endl;
}

Mondas::Human::Human(std::string human_name, unsigned int human_iq) : _name(human_name), _iq(human_iq)
{
    std::cout << _name << ": I must save Mondas with my IQ of " << _iq << "." << std::endl;
}

Mondas::Human::Human(std::string human_name, Cyberman::Inhibitor *inhib_ptr) : _name(human_name), _inhib(inhib_ptr)
{
    std::cout << _name << ": I must save Mondas with my IQ of " << _iq << "." << std::endl;
}

Mondas::Human::Human(std::string human_name) : _name(human_name) {
    std::cout << _name << ": I must save Mondas with my IQ of " << _iq << "." << std::endl;
}

Mondas::Human::~Human()
{
    std::cout << _name << ": I failed to save my world..." << std::endl;
}

std::string Mondas::Human::getName() const
{
    return _name;
}

unsigned int Mondas::Human::getIq() const
{
    return _iq;
}

void Mondas::Human::setIq(unsigned int newIq)
{
    if (newIq > _iq) {
        _iq = newIq;
        std::cout << _name << ": My IQ is now " << _iq << "." << std::endl;
    } else
        return;
}

void Mondas::Human::think(void) const
{
    std::cout << _name << ": Think, think, think..." << std::endl;
}

void Mondas::Human::setInhibitor(Mondas::Cyberman::Inhibitor* newPtr)
{
    if (_inhib != nullptr) {
        return;
    } else {
        _inhib = newPtr;
    }
}

Mondas::Cyberman::Inhibitor* Mondas::Human::getInhibitor(void)
{
    if (_inhib == nullptr)
        return nullptr;
    else
        return _inhib;
}

const Mondas::Cyberman::Inhibitor* Mondas::Human::getInhibitor(void) const
{
    if (_inhib == nullptr)
        return nullptr;
    else
        return _inhib;
}
