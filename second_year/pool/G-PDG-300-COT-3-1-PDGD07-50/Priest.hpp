/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
    #include "Enchanter.hpp"
    #define PRIEST_HPP_

class Priest : public Enchanter {
    public:
        Priest(const std::string& name, int power);
        ~Priest();
        void rest(void);

    private:
};

#endif /* !PRIEST_HPP_ */
