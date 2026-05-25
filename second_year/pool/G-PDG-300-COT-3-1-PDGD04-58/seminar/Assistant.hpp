/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Student
*/

#ifndef ASSISTANT_HPP_
    #include "Student.hpp"
    #define ASSISTANT_HPP_

class Assistant
{
    public:
        Assistant(int assistant_id);
        ~Assistant();
        void giveDrink(Student *student, std::string drink_name);
        std::string readDrink(std::string student_name);
        void helpStudent(Student *student);
        void timeCheck(void);
        std::string getStatus(void);
        void setStatus(std::string current_status);
        int getId(void);
    
        private:
            int id;
            std::string status = "not working";
};

void replaceAllOccurences(const std::string& change, std::string& origin, const std::string& to);
#endif /* !ASSISTANT_HPP_ */
