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

DroidMemory& DroidMemory::operator=(const DroidMemory& otherDroidMemory)
{
    this->_exp = otherDroidMemory.getExp();
    this->_fingerPrint = otherDroidMemory.getFingerprint();
    return *this;
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
    std::size_t stock;
    this->_exp += otherDroidMemory.getExp();
    stock = otherDroidMemory.getFingerprint() ^ this->_fingerPrint;
    this->_fingerPrint = stock;
    return *this;
}

DroidMemory& DroidMemory::operator>>(DroidMemory& otherDroidMemory)
{
    std::size_t stock;
    otherDroidMemory.setExp(otherDroidMemory.getExp() + this->_exp);
    stock = this->_fingerPrint ^ otherDroidMemory.getFingerprint();
    otherDroidMemory.setFingerprint(stock);
    return *this;
}

DroidMemory& DroidMemory::operator+=(DroidMemory& otherDroidMemory)
{
    std::size_t stock;
    this->_exp += otherDroidMemory.getExp();
    stock = otherDroidMemory.getFingerprint() ^ this->_fingerPrint;
    this->_fingerPrint = stock;
    return *this;

}

DroidMemory& DroidMemory::operator+=(std::size_t value)
{
    std::size_t stock;
    this->_exp += value;
    stock = value ^ _fingerPrint;
    this->_fingerPrint = stock;
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
