/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** FruitFactory
*/

#ifndef FRUITFACTORY_HPP_
    #include "IFruit.hpp"
    #define FRUITFACTORY_HPP_

class FruitFactory {
    public:
        FruitFactory();
        ~FruitFactory();
        void registerFruit(IFruit* fruit);
        void unregisterFruit(const std::string& name);
        IFruit* createFruit(const std::string& name) const;
    
    private:
        std::list<IFruit *>_registered;
};
#endif /* !FRUITFACTORY_HPP_ */
