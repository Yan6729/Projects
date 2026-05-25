/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** FruitFactory
*/

#include "FruitFactory.hpp"

FruitFactory::FruitFactory()
{}

FruitFactory::~FruitFactory()
{
    for (IFruit *_regFruit : _registered) {
        if (_regFruit != nullptr) {
            delete (_regFruit);
            _regFruit = nullptr;
        }
    }
    _registered.clear();
}

void FruitFactory::registerFruit(IFruit *fruit)
{
    if (fruit == nullptr) {
        return;
    }

    for (IFruit *_regFruit : _registered) {
        if ((_regFruit != nullptr) && (_regFruit->getName() == fruit->getName())) {
            _regFruit = fruit;
            return;
        }
    }
    _registered.push_back(fruit);
    return;
}

void FruitFactory::unregisterFruit(const std::string& name)
{
    if (_registered.size() == 0) {
        return;
    }

    for (IFruit *_regFruit : _registered) {
        if (_regFruit != nullptr && (_regFruit->getName() == name)) {
            delete(_regFruit);
            _registered.remove(_regFruit);
            return;
        }
    }
    return;
}

IFruit *FruitFactory::createFruit(const std::string& name) const
{
    if (_registered.size() == 0)
        return nullptr;
    
    for (IFruit *_regFruit : _registered) {
        if (_regFruit != nullptr && (_regFruit->getName() == name)) {
            return _regFruit->clone();
        }
    }
    return nullptr;
}
