/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Carrier
*/

#ifndef CARRIER_HPP_
    #include "Droid.hpp"
    #define CARRIER_HPP_

class Carrier {
    public:
        Carrier(std::string carrierId);
        std::string getId(void) const;
        std::size_t getEnergy(void) const;
        std::size_t getAttack(void) const;
        std::size_t getToughness(void) const;
        std::size_t getSpeed(void) const;
        void setId(std::string& newId);
        void setEnergy(std::size_t newEnergy);
        void setSpeed(std::size_t newSpeed);
        void updateSpeed();
        void consumeEnergy();
        int findDroid(Droid *droid, int size);
        bool addDroid(Droid *&droid);
        bool removeDroid(Droid *&droid);
        Carrier& operator<<(Droid *&droid);
        Carrier& operator>>(Droid *&droid);
        Droid *&operator[](std::size_t index);
        Droid * const & operator[](std::size_t index) const;
        Carrier& operator<<(std::size_t& newEenergy);
        Carrier &operator~(void);
        bool operator()(int x, int y);

        ~Carrier();

    private:
        std::string _carrierId = "";
        std::size_t _carrierEnergy;
        const std::size_t _carrierAttack = 100;
        const std::size_t _carrierToughness = 90;
        std::size_t _carrierSpeed;
        Droid* _carrierDroids[5];
        int numberOfDroid = 0;
};

std::ostream &operator<<(std::ostream& redirect, Carrier& carrier);
#endif /* !CARRIER_HPP_ */
