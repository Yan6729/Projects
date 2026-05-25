/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
{
    _fingerPrint = random();
}

DroidMemory::DroidMemory(const DroidMemory& existingDroidMemory)
{
    _exp = existingDroidMemory.getExp();
    _fingerPrint = existingDroidMemory.getFingerprint();
}

DroidMemory::~DroidMemory()
{}

std::size_t DroidMemory::getExp(void) const
{
    return _exp;
}

std::size_t DroidMemory::getFingerprint(void) const
{
    return _fingerPrint;
}

void DroidMemory::setExp(std::size_t newExp)
{
    _exp = newExp;
}

void DroidMemory::setFingerprint(std::size_t newFingerprint)
{
    _fingerPrint = newFingerprint;
}

std::ostream& operator<<(std::ostream& redirect, const DroidMemory& droidMemory)
{
    redirect << "DroidMemory '" << droidMemory.getFingerprint() << "', " << droidMemory.getExp();
    return redirect;
}

DroidMemory& DroidMemory::operator<<(DroidMemory& otherDroidMemory)
{
    _exp += otherDroidMemory._exp;
    _fingerPrint ^= otherDroidMemory._fingerPrint;
    return *this;
}

DroidMemory& DroidMemory::operator>>(DroidMemory& otherDroidMemory)
{
    otherDroidMemory._exp += _exp;
    otherDroidMemory._fingerPrint ^= _fingerPrint;
    return *this;
}

DroidMemory& DroidMemory::operator+=(DroidMemory& otherDroidMemory)
{
    this->_exp += otherDroidMemory._exp;
    this->_fingerPrint ^= otherDroidMemory._fingerPrint;
    return *this;
}

DroidMemory& DroidMemory::operator+=(std::size_t value)
{
    this->_exp += value;
    this->_fingerPrint ^= value;
    return *this;
}

DroidMemory DroidMemory::operator+(DroidMemory& otherDroidMemory)
{
    DroidMemory newObject;
    newObject.setExp(this->_exp + otherDroidMemory.getExp());
    newObject.setFingerprint(otherDroidMemory.getFingerprint() ^ this->_fingerPrint);
    return newObject;
}

DroidMemory DroidMemory::operator+(std::size_t value)
{
    DroidMemory newObject;
    newObject.setExp(this->_exp + value);
    newObject.setFingerprint(value ^ this->_fingerPrint);
    return newObject;
}

bool DroidMemory::operator==(DroidMemory& otherDroidMemory) const
{
    return _exp == otherDroidMemory.getExp() &&
        _fingerPrint == otherDroidMemory.getFingerprint();
}

bool DroidMemory::operator!=(DroidMemory& otherDroidMemory) const
{
    return _exp != otherDroidMemory.getExp() ||
        _fingerPrint != otherDroidMemory.getFingerprint();
}

bool DroidMemory::operator<(DroidMemory& otherDroidMemory)
{
    return _exp < otherDroidMemory.getExp();
}

bool DroidMemory::operator<(std::size_t value)
{
    return _exp < value;
}

bool DroidMemory::operator>(DroidMemory& otherDroidMemory)
{
    return _exp > otherDroidMemory.getExp();
}

bool DroidMemory::operator>(std::size_t value)
{
    return _exp > value;
}

bool DroidMemory::operator<=(DroidMemory& otherDroidMemory)
{
    return _exp <= otherDroidMemory.getExp();
}

bool DroidMemory::operator<=(std::size_t value)
{
    return _exp <= value;
}

bool DroidMemory::operator>=(DroidMemory& otherDroidMemory)
{
    return _exp >= otherDroidMemory.getExp();
}

bool DroidMemory::operator>=(std::size_t value)
{
    return _exp >= value;
}

DroidMemory& DroidMemory::operator=(const DroidMemory& otherDroidMemory)
{
    this->_exp = otherDroidMemory.getExp();
    this->_fingerPrint = otherDroidMemory.getFingerprint();
    return *this;
}
