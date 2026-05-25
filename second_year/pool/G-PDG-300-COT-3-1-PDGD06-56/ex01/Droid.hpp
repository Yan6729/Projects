/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Droid
*/

#ifndef DROID_HPP_
    #include "DroidMemory.hpp"
    #define DROID_HPP_

class Droid {
    public:
        Droid(std::string serial_number);
        Droid(const Droid& existingDroid);
        std::size_t getEnergy(void) const;
        std::string getId(void) const;
        std::string *getStatus() const;
        std::size_t getAttack(void) const;
        std::size_t getToughness(void) const;
        void setId(std::string newId);
        void setEnergy(std::size_t newEnergy);
        void setStatus(std::string *newStatus);
        DroidMemory *getBattleData(void) const;
        void setBattleData(DroidMemory *newBattleData);
        bool operator==(const Droid& otherDroid) const;
        bool operator!=(const Droid& otherDroid) const;
        Droid& operator=(const Droid& otherDroid);
        Droid& operator<<(std::size_t& newEnergy);
        ~Droid();

    private:
        std::string _droidId = "";
        std::size_t _energy = 50;
        const std::size_t _attack = 25;
        const std::size_t _toughness = 15;
        std::string *_status = new std::string("Standing by");
        DroidMemory *BattleData = new DroidMemory();
};
std::ostream& operator<<(std::ostream& redirect, const Droid& droid);

#endif /* !DROID_HPP_ */
