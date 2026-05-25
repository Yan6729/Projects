/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Carrier
*/

#include "Carrier.hpp"

Carrier::Carrier(std::string CarrierId) : _carrierId(CarrierId) {
    for (int i = 0; i < 5; i++)
        _carrierDroids[i] = nullptr;

    _carrierEnergy = 300;
    _carrierSpeed = 0;
}

Carrier::~Carrier() {
    for (auto &d : _carrierDroids)
        delete d;
}

void Carrier::updateSpeed()
{
    //int count = 0;
    // for (int i = 0; i < 5; i++)
    //     if (_carrierDroids[i] != nullptr)
    //         count++;

    _carrierSpeed = 100 - (numberOfDroid * 10);
    if ((100 - (numberOfDroid * 10)) < 0)
        _carrierSpeed = 0;
}

std::string Carrier::getId(void) const
{
    return _carrierId;
}

std::size_t Carrier::getEnergy(void) const
{
    return _carrierEnergy;
}

std::size_t Carrier::getAttack(void) const
{
    return _carrierAttack;
}

std::size_t Carrier::getToughness(void) const
{
    return _carrierToughness;
}

std::size_t Carrier::getSpeed(void) const
{
    return _carrierSpeed;
}

void Carrier::setId(std::string& newId)
{
    _carrierId = newId;
}

void Carrier::setEnergy(std::size_t newEnergy)
{
    _carrierEnergy = newEnergy;
}

void Carrier::setSpeed(std::size_t newSpeed)
{
    _carrierSpeed = newSpeed;
}

int Carrier::findDroid(Droid *droid, int size)
{
    for (int a = 0; a < size; a++) {
        if (_carrierDroids[a] != nullptr && _carrierDroids[a] == droid) {
            return a;
        }
    }
    return -1;
}

void Carrier::consumeEnergy()
{
    // int count = 0;
    // for (int i = 0; i < 5; i++)
    //     if (_carrierDroids[i] != nullptr)
    //         count++;

    _carrierEnergy -= numberOfDroid * 10;
    if ((numberOfDroid * 10) < 0)
        _carrierEnergy = 0;
}


bool Carrier::addDroid(Droid *&droid)
{
    for (int a = 0; a < 5; a++) {
        if (_carrierDroids[a] == nullptr) {
            _carrierDroids[a] = droid;
            droid = nullptr;
            numberOfDroid += 1;
            updateSpeed();
            return true;
        }
    }
    return true;
}

bool Carrier::removeDroid(Droid *&droid)
{
    int index = findDroid(droid, 5);
    
    if (index != -1) {
        _carrierDroids[index] = nullptr;
        numberOfDroid -= 1;
        updateSpeed();
        consumeEnergy();
        return true;
    } else {
        return false;
    }
}

Carrier& Carrier::operator<<(Droid *&droid)
{
if (!droid)
        return *this;

    for (auto &slot : _carrierDroids) {
        if (!slot) {
            slot = droid;
            droid = nullptr;
            updateSpeed();
            break;
        }
    }
    return *this;
}

Carrier& Carrier::operator>>(Droid *&droid)
{
    for (int i = 4; i >= 0; --i) {
        if (_carrierDroids[i]) {
            droid = _carrierDroids[i];
            _carrierDroids[i] = nullptr;
            updateSpeed();
            break;
        }
    }
    return *this;
}

Droid *&Carrier::operator[](std::size_t index)
{
    static Droid *nullDroid = nullptr;

    if (index >= 5)
        return nullDroid;
    return _carrierDroids[index];
}

Droid * const & Carrier::operator[](std::size_t index) const
{
    static Droid *nullDroid = nullptr;

    if (index >= 5)
        return nullDroid;
    return _carrierDroids[index];
}

bool Carrier::operator()(int x, int y)
{
    if (_carrierSpeed == 0)
        return false;

    std::size_t used = (abs(x) + abs(y)) * (10 + (numberOfDroid));
    if (_carrierEnergy < used)
        return false;
    _carrierEnergy -= used;
    return true;
}

Carrier& Carrier::operator<<(std::size_t& newEenergy)
{
    std::size_t a = this->_carrierEnergy;
    int b = 0;

    if ((newEenergy + this->_carrierEnergy) <= 600) {
        this->_carrierEnergy += newEenergy;
        newEenergy = 0;
        return *this;
    }
    for (; a < 600; a++) {
        b += 1;
    }
    newEenergy -= b;
    this->_carrierEnergy = a;
    return *this;
}

Carrier &Carrier::operator~(void)
{
    updateSpeed();
    return *this;
}

std::string isRoom(Droid *droid)
{
    if (droid == nullptr) {
        return "Free";
    } else {
        return "Droid '" + droid->getId() + "', " + *droid->getStatus() + ", " + std::to_string(droid->getEnergy());
    }
}

std::ostream &operator<<(std::ostream& redirect, Carrier& carrier)
{
    redirect << "Carrier '" << carrier.getId() << "' Droid(s) on-board:\n"
        << "[0] : " << isRoom(carrier[0]) << "\n"
        << "[1] : " << isRoom(carrier[1]) << "\n"
        << "[2] : " << isRoom(carrier[2]) << "\n"
        << "[3] : " << isRoom(carrier[3]) << "\n"
        << "[4] : " << isRoom(carrier[4]) << "\n"
        << "Speed : " << carrier.getSpeed() << ", Energy " << carrier.getEnergy();
    return redirect;
}
