/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Cyberleader
*/

#ifndef CYBERLEADER_HPP_
    #include "Human.hpp"
    #define CYBERLEADER_HPP_

namespace Mondas {
    class Cyberleader {
        public:
            Cyberleader(Human& human_ptr);
            ~Cyberleader();
            void upgrade(Human& human_ptr);
            void upgrade(Cyberman::Inhibitor& inhib_ptr);
            void upgrade(Cyberman& cyberman_ptr);
            std::string getClname(void);

        private:
           Human& _human;
           Cyberman::Inhibitor *_inhib = _human.getInhibitor();
           std::string _clname;
    };
}

#endif /* !CYBERLEADER_HPP_ */
