/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(unsigned int size) : _size(size)
{
    _fruitbox.back() = nullptr;
}

FruitBox::~FruitBox()
{
    for (IFruit *fruit : _fruitbox) {
        if (fruit != nullptr) {
            delete(fruit);
            fruit = nullptr;
        }
    }
}

unsigned int FruitBox::getSize(void) const
{
    return _size;
}

bool FruitBox::isInTheBox(IFruit *fruit)
{
    if (_fruitbox.empty()) {
        return false;
    }
    for (IFruit *_fruit : _fruitbox) {
        if (fruit != nullptr && fruit == _fruit) {
            return true;
        }
    }
    return false;
}

bool FruitBox::pushFruit(IFruit *fruit)
{
    if ((_fruitbox.size() == _size) || isInTheBox(fruit)) {
        return false;
    }
    _fruitbox.push_back(fruit);
    return true;
}

std::list<std::string> FruitBox::toString(void) const
{
    std::ostringstream to_string;
    std::list<std::string> result;

    for (IFruit *fruit : _fruitbox) {
        if (fruit != nullptr) {
            to_string.str("");
            to_string.clear();
            to_string << *fruit;
            result.push_back(to_string.str());
        }
    }
    return result;
}

IFruit *FruitBox::popFruit(void)
{
    IFruit *last;

    if (_fruitbox.size() >= 1) {
        last = _fruitbox.front();
        _fruitbox.pop_front();
        return last;
    }
    return nullptr;
}

unsigned int FruitBox::nbFruits(void) const
{
    return _fruitbox.size();
}

bool FruitBox::IsFull(void) const
{
    if (_fruitbox.size() == _size) {
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& redirect, const FruitBox& fruitbox)
{
    std::list<std::string> result = fruitbox.toString();
    redirect << "[";

    if (result.empty()) {
        redirect << "]";
        return redirect;
    }
    std::string last_elem = result.back();
    result.pop_back();

    for (std::string def : result) {
        redirect << def << ", ";
    }
    redirect << last_elem << "]";
    return redirect;
}

std::list<IFruit *> FruitBox::getList(void) const
{
    return _fruitbox;
}
