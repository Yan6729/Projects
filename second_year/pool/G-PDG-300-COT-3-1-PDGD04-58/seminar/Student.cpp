/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Student
*/

#include "Student.hpp"

void Student::addSupply(int supply)
{
    if ((energy_point + supply) > 100) {
        energy_point = 100;
    } else {
        energy_point += supply;
    }
}

bool Student::takeEnergy(int remove)
{
    if ((energy_point - remove)  > 0) {
        energy_point -= remove;
        return true;
    } else {
        return false;
    }
}

int Student::randomIndex(int size)
{
    int index;

    index = std::rand() % size;
    return index;
}

bool Student::learn(std::string text)
{
    if (takeEnergy(42) == true) {
        std::cout << "Student " << name << ": " << text << std::endl;
        return true;
    } else {
        replaceAllOccurences("C++", text, "shit");
        std::cout << "Student " << name << ": " << text << std::endl;
        return false;
    }
}

void Student::drink(std::string drink_name)
{
    if (drink_name.compare("Red Bull") == 0) {
        addSupply(32);
        std::cout << "Student " << name << ": Red Bull gives you wings!" << std::endl;
    } else if (drink_name.compare("Monster") == 0) {
        addSupply(64);
        std::cout << "Student " << name << ": Unleash The Beast!" << std::endl;
    } else {
        addSupply(1);
        std::cout << "Student " << name << ": ah, yes... enslaved moisture." << std::endl;   
    }
}

std::string Student::getName(void)
{
    return name;
}

int Student::getEnergy(void)
{
    return energy_point;
}

Student::Student(std::string student_name) : name(student_name) {
    std::cout << "Student " << name << ": I'm ready to learn C++." << std::endl;
}

Student::~Student() {
    std::cout << "Student " << name << ": Wow, much learning today, very smart, such C++." << std::endl;
}

void replaceAllOccurences(const std::string& change, std::string& origin, const std::string& to)
{
    size_t start = 0;
    
    if (change.empty() || origin.empty() || to.empty()) {
        return;
    }
    while (((start = origin.find(change, start)) != std::string::npos)) {
        origin.replace(start, change.length(), to);
        start += to.length();
    }
}
