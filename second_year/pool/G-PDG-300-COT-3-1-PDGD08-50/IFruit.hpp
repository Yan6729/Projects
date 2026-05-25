/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** IFruit
*/

#ifndef IFRUIT_HPP_
    #include <iostream>
    #include <string>
    #include <list>
    #include <sstream>
#define IFRUIT_HPP_

class IFruit {
    public:
        virtual ~IFruit();
        virtual unsigned int getVitamins(void) const = 0;
        virtual std::string getName(void) const = 0;
        virtual bool isPeeled(void) const = 0;
        virtual void peel(void) = 0;
        virtual IFruit* clone() const = 0;
    
    protected:
};

std::ostream& operator<<(std::ostream& redirect, const IFruit& fruit);
#endif /* !IFRUIT_HPP_ */
