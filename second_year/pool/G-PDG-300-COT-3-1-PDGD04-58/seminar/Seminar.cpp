/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** seminar
*/

#include "Seminar.hpp"

Seminar::Seminar() {};

Seminar::~Seminar() {};

void Seminar::student_learn(std::string learn, int option)
{
    Dean *dean = getDeanAt(0);
    Assistant *ass1 = getAssistantAt(0);
    Assistant *ass2 = getAssistantAt(1);
    Student *one = getStudentAt(0);
    Student *two = getStudentAt(1);
    Student *three = getStudentAt(2);
    Student *four = getStudentAt(3);
    Student *five = getStudentAt(4);

    if (option == 1) {
        dean->teachStudent(one, learn);
        ass1->helpStudent(one);
        dean->teachStudent(two, learn);
        ass2->helpStudent(two);
        dean->teachStudent(three, learn);
        ass1->helpStudent(three);
        dean->teachStudent(four, learn);
        ass2->helpStudent(four);
        dean->teachStudent(five, learn);
        ass1->helpStudent(five);
    } else if (option == 2) {
        dean->teachStudent(one, learn);
        ass2->helpStudent(one);
        dean->teachStudent(two, learn);
        ass1->helpStudent(two);
        dean->teachStudent(three, learn);
        ass2->helpStudent(three);
        dean->teachStudent(four, learn);
        ass1->helpStudent(four);
        dean->teachStudent(five, learn);
        ass2->helpStudent(five);
    }
}

void Seminar::ifStudentEnergyIsOkay(Student *student, std::string learn, Assistant *ass, Dean *dean)
{
    if (student->getEnergy() >= 42) {
        ass->helpStudent(student);
    } else {
        dean->teachStudent(student, learn);
    }
}

void Seminar::run(void)
{
    if (student_list.size() == 0 || assistant_list.size() == 0 || dean_list.size() == 0) {
        std::cout << "Seminar: A C++ seminar needs at least one Dean of Studies, one Assistant and one Student." << std::endl;
    } else {
        Dean *dean = getDeanAt(0);
        Assistant *ass1 = getAssistantAt(0);
        Assistant *ass2 = getAssistantAt(1);
        Student *one = getStudentAt(0);
        Student *two = getStudentAt(1);
        Student *three = getStudentAt(2);
        Student *four = getStudentAt(3);
        Student *five = getStudentAt(4);
        std::cout << "Seminar: Begining 6th day of seminar." << std::endl;
        std::cout << "Dean of Studies: " << dean->getName()
                << std::endl
                << "Teaching assistants: " << ass1->getId() << ", " << ass2->getId()
                << std::endl
                << "Students: " << one->getName() << ", "
                << two->getName() << ", "
                << three->getName() << ", "
                << four->getName() << ", "
                << five->getName()
                << std::endl;
        
        dean->timeCheck();
        ass1->timeCheck();
        ass2->timeCheck();
        student_learn("I'm learning C++!", 1);
        student_learn("I'm learning C++!", 2);
        student_learn("I'm learning C++!", 1);
        student_learn("I'm learning C++!", 2);
        student_learn("I'm learning C++!", 1);
        dean->timeCheck();
        ass1->timeCheck();
        ass2->timeCheck();
    }
}

Student *Seminar::getStudentAt(int index)
{
    std::list<Student *>::iterator stud = student_list.begin();
    std::advance(stud, index);
    return *stud;
}

Assistant *Seminar::getAssistantAt(int index)
{
    std::list<Assistant *>::iterator ass = assistant_list.begin();
    std::advance(ass, index);
    return *ass;
}

Dean *Seminar::getDeanAt(int index)
{
    std::list<Dean *>::iterator d_n = dean_list.begin();
    std::advance(d_n, index);
    return *d_n;
}

bool Seminar::checkIfStudentIsThere(Student *student)
{
    for (std::size_t a = 0; a < student_list.size(); a++) {
        if (getStudentAt(a)->getName() == student->getName()) {
            return true;
        }
    }
    return false;
}

void Seminar::addStudent(Student *student)
{
    if (checkIfStudentIsThere(student) == true) {
        std::cout << "Seminar: Student "<< student->getName() << " is already registered." << std::endl;
        return;
    }
    if (student_list.size() < 5) {
        student_list.push_back(student);
        std::cout << "Seminar: Student " << student->getName() << " joined the seminar." << std::endl;
    } else {
        std::cout << "Seminar: There is only room for five Students." << std::endl;
    }
}

void Seminar::addAssistant(Assistant *assistant)
{
    if (assistant_list.size() == 1) {
        if (getAssistantAt(0)->getId() == assistant->getId()) {
            std::cout << "Seminar: Assistant " << assistant->getId() <<  " is already registered." << std::endl;
            return;
        }
    } else if (assistant_list.size() == 2) {
        if (getAssistantAt(0)->getId() == assistant->getId() || getAssistantAt(1)->getId() == assistant->getId()) {
            std::cout << "Seminar: Assistant " << assistant->getId() <<  " is already registered." << std::endl;
            return;
        }
    }
    if (assistant_list.size() < 2) {
        assistant_list.push_back(assistant);
        std::cout << "Seminar: Assistant " << assistant->getId() << " joined the pedagogical team." << std::endl;
    } else {
        std::cout << "Seminar: There is only room for two Teaching Assistants." << std::endl;
    }
}

void Seminar::addDean(Dean *dean)
{
    if (dean_list.size() == 1) {
        if (getDeanAt(0)->getName() == dean->getName()) {
            std::cout << "Seminar: Dean " << dean->getName() << " is already registered." << std::endl;
            return;
        }
    }
    if (dean_list.size() == 0) {
        dean_list.push_back(dean);
        std::cout <<  "Seminar: Dean " << dean->getName() << " is here." << std::endl;
    } else {
        std::cout << "Seminar: There can only be one Dean of Studies." << std::endl;
    }
}
