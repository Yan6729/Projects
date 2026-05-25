/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string serial_number) : _droidId(serial_number)
{
    std::cout << "Droid '" << _droidId << "' Activated" << std::endl;
}

Droid::Droid(const Droid& existingDroid)
{
    _droidId = existingDroid.getId();
    _status = existingDroid.getStatus();
    _BattleData = existingDroid.getBattleData();
    std::cout << "Droid '" << _droidId << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << _droidId << "' Destroyed" << std::endl;
}

std::size_t Droid::getEnergy(void) const
{
    return _energy;
}

std::string Droid::getId(void) const
{
    return _droidId;
}

std::string *Droid::getStatus() const
{
    return _status;
}

std::size_t Droid::getAttack(void) const
{
    return _attack;
}

std::size_t Droid::getToughness(void) const
{
    return _toughness;
}

Droid& Droid::operator<<(std::size_t& newEenergy)
{
    std::size_t a = this->_energy;
    int b = 0;

    if ((newEenergy + this->_energy) <= 100) {
        this->_energy += newEenergy;
        newEenergy = 0;
        return *this;
    }
    for (; a < 100; a++) {
        b += 1;
    }
    newEenergy -= b;
    this->_energy = a;
    return *this;
}

bool Droid::operator==(const Droid& otherDroid) const
{
    return *(this->_status) == *(otherDroid._status);
}

bool Droid::operator!=(const Droid& otherDroid) const
{
    return *(this->_status) != *(otherDroid._status);
}

Droid& Droid::operator=(const Droid& otherDroid)
{
    if (*this != otherDroid) {
        this->_droidId = otherDroid.getId();
        this->_energy = otherDroid.getEnergy();
        if (this->_status) {
            delete(this->_status);
        }
        this->_status = new std::string(*otherDroid.getStatus());
        if (this->_BattleData) {
            delete(this->_BattleData);
        }
        this->_BattleData = new DroidMemory(*otherDroid.getBattleData());
    }
    return *this;
}

bool Droid::operator()(const std::string *task, std::size_t expRequired)
{
    if (this->_energy <= 10)
    {
        setStatus(new std::string("Battery Low"));
        this->_energy = 0;
        return false;
    } else {
        this->_energy -= 10;
        if ((this->_BattleData->getExp() >= expRequired)) {
            setStatus(new std::string(*task + " - Completed!"));
            _BattleData->setExp(this->_BattleData->getExp() + (expRequired / 2));
            return true;
        } else {
            setStatus(new std::string(*task + " - Failed!"));
            this->_BattleData->setExp(this->_BattleData->getExp() + expRequired);
            return false;
        }
    }
}

void Droid::setId(std::string newId)
{
    _droidId = newId;
}

void Droid::setStatus(std::string *newStatus)
{
    if (_status != nullptr)
        delete (_status);
    _status = newStatus;
}

void Droid::setEnergy(std::size_t newEnergy)
{
    _energy = newEnergy;
}


DroidMemory *Droid::getBattleData(void) const
{
    return _BattleData;
}

void Droid::setBattleData(DroidMemory *newBattleData)
{
    if (_BattleData !=nullptr)
        delete(_BattleData);
    _BattleData = newBattleData;
}


std::ostream& operator<<(std::ostream& redirect, const Droid& droid)
{
    redirect << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
    return redirect;
}
