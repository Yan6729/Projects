/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** seminar
*/

#ifndef SEMINAR_HPP_
    #include "Dean.hpp"
    #define SEMINAR_HPP_

class Seminar
{
    public:
        Seminar ();
        ~Seminar();
        void run(void);
        void student_learn(std::string learn, int option);
        void addDean(Dean *dean);
        void addAssistant(Assistant *assistant);
        void addStudent(Student *student);
        Student *getStudentAt(int index);
        Assistant *getAssistantAt(int index);
        Dean *getDeanAt(int index);
        bool checkIfStudentIsThere(Student *student);
        void ifStudentEnergyIsOkay(Student *student, std::string learn, Assistant *ass, Dean *dean);
    
    private:
        std::list<Student *> student_list;
        std::list<Assistant *> assistant_list;
        std::list<Dean *> dean_list;
};

#endif /* !SEMINAR_HPP_ */
