/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** CoreEngine
*/

#ifndef COREENGINE_HPP_
    #include "../../include/Circuit.hpp"
    #include <bitset>
    #define COREENGINE_HPP_
    using namespace nts;

class CoreEngine {
    public:
        CoreEngine();
        ~CoreEngine();
        string calcul(string opperation);

    protected:
    private:
    map<string, Circuit> _opp;
};

#endif /* !COREENGINE_HPP_ */
