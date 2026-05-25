/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
    #include <iostream>
    #include <string>
    #include <fstream>
    #define DROIDMEMORY_HPP_

class DroidMemory {
    public:
        DroidMemory();
        DroidMemory(const DroidMemory& existingDroidDroidMemory);
        std::size_t getFingerprint() const;
        std::size_t getExp() const;
        void setFingerprint(std::size_t newFringerprint);
        void setExp(std::size_t newExp);
        DroidMemory& operator<<(DroidMemory& otherDroidMemory);
        DroidMemory& operator>>(DroidMemory& otherDroidMemory);
        DroidMemory& operator+=(DroidMemory& otherDroidMemory);
        DroidMemory& operator+=(std::size_t value);
        DroidMemory operator+(DroidMemory& otherDroidMemory);
        DroidMemory operator+(std::size_t value);
        DroidMemory& operator=(const DroidMemory& otherDroidMemory);
        bool operator<(DroidMemory& otherDroidMemory);
        bool operator<(std::size_t value);
        bool operator<=(DroidMemory& otherDroidMemory);
        bool operator<=(std::size_t value);
        bool operator>(DroidMemory& otherDroidMemory);
        bool operator>(std::size_t value);
        bool operator>=(DroidMemory& otherDroidMemory);
        bool operator>=(std::size_t value);
        bool operator==(DroidMemory& otherDroidMemory) const;
        bool operator!=(DroidMemory& otherDroidMemory) const;
        ~DroidMemory();

    private:
        std::size_t _fingerPrint;
        std::size_t _exp = 0;
};

std::ostream& operator<<(std::ostream& redirect, const DroidMemory& droidMemory);

#endif /* !DROIDMEMORY_HPP_ */
