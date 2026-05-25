/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** AFruit
*/

#ifndef AFRUIT_HPP_
    #include "IFruit.hpp"
    #define AFRUIT_HPP_

class AFruit : public IFruit {
    public:
        AFruit();
        ~AFruit();
        unsigned int getVitamins(void) const;
        std::string getName(void) const;
        bool isPeeled(void) const;
        std::string getType(void) const;
        void peel(void);
        void setName(std::string name);
        void setVitamins(unsigned int vitamins);
        void setIsPelled(bool ispelled);
        void setType(std::string type);
        IFruit *clone() const;

    protected:
        bool _isPeeled = false;
        unsigned int _vitamins = 0;
        std::string _name = "";
        std::string _type = "";
};

#endif /* !AFRUIT_HPP_ */
