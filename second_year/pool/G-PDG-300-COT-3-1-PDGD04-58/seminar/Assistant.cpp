/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Assistant
*/

#include "Assistant.hpp"

Assistant::Assistant(int assistant_id) : id(assistant_id) {
    std::cout << "Assistant " << id << ": 'morning everyone *sip coffee*" << std::endl;
};

Assistant::~Assistant () {
    std::cout << "Assistant " << id << ": see you tomorrow at 9.00 *sip coffee*" << std::endl;
}

void Assistant::giveDrink(Student *student, std::string drink_name) {
    std::cout << "Assistant " << id << ": drink this, " << student->getName() << " *sip coffee*" << std::endl;
    student->drink(drink_name);
}

std::string Assistant::readDrink(std::string student_name) {
    std::string filename = student_name + ".drink";
    std::ifstream reports(filename);
    std::string drink_name;
    if (!reports.is_open())
        return "";
    std::getline(reports, drink_name);
    if (drink_name.empty()) {
        std::filesystem::remove(filename);
        return "";
    } else {
        std::filesystem::remove(filename);
        std::cout << "Assistant " << id << ": " << student_name << " needs a " << drink_name  << " *sip coffee*" << std::endl;
        return drink_name;
    }
}

void Assistant::helpStudent(Student *student)
{
    std::string drink_name = readDrink(student->getName());
    
    if (drink_name.empty()) {
        std::cout << "Assistant " << id << ": " << student->getName() << " seems fine *sip coffee*" << std::endl;
        return;
    }
    giveDrink(student, drink_name);
}

std::string Assistant::getStatus(void)
{
    return status;
}

int Assistant::getId(void)
{
    return id;
}

void Assistant::setStatus(std::string current_status)
{
    status = current_status;
}

void Assistant::timeCheck(void)
{
    if (status == "not working") {
        std::cout << "Assistant " << id << ": Time to teach some serious business *sip coffee*" << std::endl;
        setStatus("working");
        return;
    } else {
        std::cout << "Assistant " << id << ": Enough teaching for today *sip coffee*" << std::endl;
        setStatus("not working");
        return;
    }
}
