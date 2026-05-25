/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Student
*/

#ifndef STUDENT_HPP_
    #include <iostream>
    #include <string>
    #include <fstream>
    #include <iomanip>
    #include <cstdio>
    #include <filesystem>
    #include <list>
    #include <iterator>
    #include <cstdlib>
    #include <ctime>
    #define STUDENT_HPP_

class Student
{
    public:
        Student(std::string Student_name);
        ~Student();
        void addSupply(int supply);
        bool takeEnergy(int remove);
        bool learn(std::string text);
        std::string getName(void);
        void drink(std::string drink_name);
        int randomIndex(int size);
        int getEnergy(void);

    private:
        std::string name;
        int energy_point = 100;
};

void replaceAllOccurences(const std::string& change, std::string& origin, const std::string& to);
#endif /* !STUDENT_HPP_ */
