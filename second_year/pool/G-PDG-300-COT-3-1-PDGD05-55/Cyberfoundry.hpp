/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Cyberfoundry
*/

#ifndef CYBERFOUNDRY_HPP_
    #include "Cyberleader.hpp"
    #define CYBERFOUNDRY_HPP_

namespace Mondas {
    class Cyberfoundry {
        public:
            Cyberfoundry(unsigned int natural_energy_ressources);
            ~Cyberfoundry();
            Mondas::Cyberman* buildCyberman(Mondas::Human& human);
            Mondas::Cyberleader* buildCyberleader(Mondas::Human& human);
            void recycle(Mondas::Cyberman*& cyberMan);
            void recycle(Mondas::Cyberleader*& cyberLeader);
            bool takeEnergy(unsigned int take);
            void restoreEnergy(unsigned int restore);

        private:
            unsigned int _natural;
    };
}

#endif /* !CYBERFOUNDRY_HPP_ */
