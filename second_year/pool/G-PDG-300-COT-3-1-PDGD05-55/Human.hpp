/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Human
*/

#ifndef HUMAN_HPP_
#define HUMAN_HPP_
#include "Cyberman.hpp"

namespace Mondas {
    class Human {
        public:
            Human(std::string human_name, unsigned int human_iq, Cyberman::Inhibitor *inhib_ptr);
            Human(std::string human_name, unsigned int human_iq);
            Human(std::string human_name, Cyberman::Inhibitor *inhib_ptr);
            Human(std::string human_name);
            ~Human();
            std::string getName() const;
            unsigned int getIq() const;
            void setIq(unsigned int newIq);
            void think(void) const;
            void setInhibitor(Cyberman::Inhibitor* newPtr);
            Cyberman::Inhibitor* getInhibitor();
            const Cyberman::Inhibitor* getInhibitor() const;

        private:
            std::string _name;
            unsigned int _iq = 192;
            Cyberman::Inhibitor *_inhib = nullptr;
    };
};
#endif /* !HUMAN_HPP_ */
