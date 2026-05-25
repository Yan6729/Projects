/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Cyberleader
*/

#include "Cyberleader.hpp"

Mondas::Cyberleader::Cyberleader(Human& human_ptr) : _human(human_ptr)
{
    _clname = _human.getName();
    replaceLetter(_clname);
    std::cout << _clname << ": Master unit activated." << std::endl;
}

Mondas::Cyberleader::~Cyberleader()
{
    std::cout << _clname << ": Master unit deactivated." << std::endl;
}

std::string Mondas::Cyberleader::getClname(void)
{
    return _clname;
}

void Mondas::Cyberleader::upgrade(Human& human_ptr)
{
    Cyberman::Inhibitor *inhib = human_ptr.getInhibitor();

    if (_human.getInhibitor() == nullptr || _human.getInhibitor()->get() == false) {
        std::cout << _clname << ": Pain, pain, pain..." << std::endl;
    } else {
        unsigned int old_iq = human_ptr.getIq();
        
        std::cout << _clname << ": Upgrading human '" << human_ptr.getName() << "'." << std::endl;
        
        human_ptr.setIq(old_iq * 2);
        
        std::cout << "IQ of unit doubled, increased to " << human_ptr.getIq() << "." << std::endl;
        
        if (inhib == nullptr) {
            std::cout << "No inhibitor installed." << std::endl;
        } else {
            if (inhib->get() == false) {
                std::cout << _clname << ": Activating inhibitor." << std::endl;
                human_ptr.getInhibitor()->set(true);
            } else {
                std::cout << _clname << ": Inhibitor already activated." << std::endl;
            }
        }
    }
}

void Mondas::Cyberleader::upgrade(Cyberman::Inhibitor& inhib_ptr)
{
    if (_human.getInhibitor() == nullptr || _human.getInhibitor()->get() == false) {
        std::cout << _clname << ": Pain, pain, pain..." << std::endl;
    } else {
        if (inhib_ptr.get() == false) {
            std::cout << _clname << ": Activating inhibitor." << std::endl;
            
            inhib_ptr.set(true);
        } else {
            std::cout << _clname << ": Inhibitor already activated." << std::endl;
        }
    }
}

void Mondas::Cyberleader::upgrade(Cyberman& cyberman_ptr)
{
    Cyberman::Inhibitor *stock = cyberman_ptr.getHuman().getInhibitor();

    if (_human.getInhibitor() == nullptr || _human.getInhibitor()->get() == false) {
        std::cout << _clname << ": Pain, pain, pain..." << std::endl;
    } else {
        unsigned int old_iq = cyberman_ptr.getHuman().getIq();
        
        std::cout << _clname << ": Upgrading unit '" << cyberman_ptr.getCname() << "'." << std::endl;
        std::cout << _clname << ": Upgrading human '" << cyberman_ptr.getHuman().getName() << "'." << std::endl;
        
        cyberman_ptr.getHuman().setIq(old_iq * 2);
        
        std::cout << "IQ of unit doubled, increased to " << cyberman_ptr.getHuman().getIq() << "." << std::endl;
        
        if (stock == nullptr) {
            std::cout << "No inhibitor installed." << std::endl;
        } else {
            if (stock->get() == false) {
                std::cout << _clname << ": Activating inhibitor." << std::endl;
                cyberman_ptr.getHuman().getInhibitor()->set(true);
            } else {
                std::cout << _clname << ": Inhibitor already activated." << std::endl;
            }
        }
    }
}
