/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Dean
*/

#include "Dean.hpp"

Dean::Dean(std::string dean_name) : name(dean_name)
{
    std::cout << "Dean " << name << ": I'm Dean " << name << "! How do you do, fellow kids?" << std::endl;
}

Dean::~Dean()
{
    std::cout << "Dean " << name << ": Time to go home." << std::endl;
}

void Dean::teachStudent(Student *student, std::string lessons)
{
    bool stat = student->learn(lessons);

    if (stat == false) {
        std::cout << "Dean " << name << ": All work and no play makes " 
            << student->getName() << " a dull student." << std::endl;
        std::string drink_name = pickDrink(student);
        createFile(student->getName() + ".drink", drink_name);
    }
}

std::string Dean::getName(void)
{
    return name;
}

void createFile(std::string filename, std::string drink_name)
{
    std::ofstream file;

    file.open(filename);

    file << drink_name << std::endl;
    file.close();
}

std::string pickDrink(Student *student) {
    std::list<std::string> string_list =
    {
        "Cristaline",
        "Monster",
        "Evian",
        "Red Bull",
        "Sierra Springs"
    };
    int index = student->randomIndex(string_list.size());
    std::list<std::string>::iterator it = string_list.begin();
    std::advance(it, index);

    return *it;
}

std::string Dean::getStatus(void)
{
    return status;
}

void Dean::setStatus(std::string current_status)
{
    status = current_status;
}

void Dean::timeCheck(void)
{
    if (status == "not working") {
        std::cout << "Dean " << name << ": Where is everyone?" << std::endl;
        setStatus("working");
        return;
    } else {
        std::cout << "Dean " << name << ": Don't forget to close the windows when you leave." << std::endl;
        setStatus("not working");
        return;
    }
}
