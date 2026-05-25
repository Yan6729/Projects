/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Dean
*/

#ifndef DEAN_HPP_
    #include "Assistant.hpp"
    #define DEAN_HPP_

class Dean {
    public:
        Dean(std::string dean_name);
        ~Dean();
        void teachStudent(Student *student, std::string lessons);
        void timeCheck(void);
        std::string getStatus(void);
        void setStatus(std::string current_status);
        std::string getName(void);

    private:
        std::string name;
        std::string status = "not working";
};

std::string pickDrink(Student *student);
void createFile(std::string filename, std::string message);
#endif /* !DEAN_HPP_ */
