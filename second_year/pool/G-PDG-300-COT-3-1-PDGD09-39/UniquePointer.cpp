/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** UniquePointer
*/

#include "UniquePointer.hpp"

UniquePointer::UniquePointer()
{
    _ptr = nullptr;
}

UniquePointer::UniquePointer(IObject *object)
{
    _ptr = object;
}

UniquePointer& UniquePointer::operator=(IObject *object)
{
    if (_ptr != nullptr) {
        delete(_ptr);
    }
    _ptr = object;
    return *this;
}

void UniquePointer::reset(IObject* object)
{
    if (_ptr != nullptr) {
        delete(_ptr);
    }
    _ptr = object;
}

void UniquePointer::reset(void)
{
    if (_ptr != nullptr) {
        delete(_ptr);
        _ptr = nullptr;
    }
}

void UniquePointer::swap(UniquePointer& other)
{
    IObject *temp = _ptr;
    _ptr = other._ptr;
    other._ptr = temp;
}

UniquePointer::~UniquePointer()
{
    if (_ptr != nullptr)
       delete(_ptr);
}
