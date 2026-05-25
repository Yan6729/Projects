/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Cyberman
*/

#ifndef CYBERMAN_HPP_
    #include <iostream>
    #include <string>
    #include <list>
    #include <fstream>
    #include <memory>
    #include <algorithm>
    #define CYBERMAN_HPP_

namespace Mondas {
    class Human;

    class Cyberman {
        public:
            Cyberman(Human& address_human);
            ~Cyberman();
            Human& getHuman(void) const;
            Human& getHuman(void);
            void think(void) const;
            unsigned int getIq(void);
            unsigned int getIq(void) const;
            std::string getCname(void) const;
            void setIq(unsigned int newIq);

            class Inhibitor {
                public:
                    Inhibitor();
                    ~Inhibitor();
                    void set(bool newValue);
                    bool get(void);

                private:
                    bool value = false;
            };

        private:
            Human& _human;
            std::string _cname;
    };
}

void lowerSpecificChar(std::string& str);
void replaceLetter(std::string& str);


#endif /* !CYBERMAN_HPP_ */
