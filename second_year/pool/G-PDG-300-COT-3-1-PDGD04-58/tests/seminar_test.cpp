/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** seminar_test
*/

#include "../seminar/Seminar.hpp"
#include <criterion/criterion.h>

void createStudent(void)
{
    Student Jennifer("Jennifer");
}

Test(test_create_student, student_create)
{
    std::stringstream buff;
    std::streambuf *out = std::cout.rdbuf();
    std::cout.rdbuf(buff.rdbuf());
    
    createStudent();

    std::cout.rdbuf(out);

    std::string str = "Student Jennifer: I'm ready to learn C++.\nStudent Jennifer: Wow, much learning today, very smart, such C++.\n";
    cr_assert_eq(buff.str(), str);
}

void createAssistant(void)
{
    Assistant ass_24(24);
}

Test(test_create_assistant, assistant_create)
{
    std::stringstream buff2;
    std::streambuf *out2 = std::cout.rdbuf();
    std::cout.rdbuf(buff2.rdbuf());

    createAssistant();

    std::cout.rdbuf(out2);

    std::string str = "Assistant 24: 'morning everyone *sip coffee*\nAssistant 24: see you tomorrow at 9.00 *sip coffee*\n";
    cr_assert_eq(buff2.str(), str);
}

void createDean(void)
{
    Dean dean("Devoile");
}

Test(test_create_dean, dean_create)
{
    std::stringstream buff3;
    std::streambuf *out3 = std::cout.rdbuf();
    std::cout.rdbuf(buff3.rdbuf());

    createDean();

    std::cout.rdbuf(out3);
    
    std::string str = "Dean Devoile: I'm Dean Devoile! How do you do, fellow kids?\nDean Devoile: Time to go home.\n";
    cr_assert_eq(buff3.str(), str);
}

void learnToStudent(void)
{
    Student Jennifer("Jennifer");
    Jennifer.learn("I'm learning C++"); 
}

void tiredStudent(void)
{
    Student Jennifer("Jennifer");
    Jennifer.learn("I'm learning C++");
    Jennifer.learn("I'm learning C++");
    Jennifer.learn("I'm learning C++"); 
}

Test(test_learn_to_student, student_create)
{
    std::stringstream buff4;
    std::streambuf *out4 = std::cout.rdbuf();
    std::cout.rdbuf(buff4.rdbuf());
    
    learnToStudent();

    std::cout.rdbuf(out4);

    std::string str = "Student Jennifer: I'm ready to learn C++.\nStudent Jennifer: I'm learning C++\nStudent Jennifer: Wow, much learning today, very smart, such C++.\n";
    cr_assert_eq(buff4.str(), str);
}

Test(test_tired_student, student_create)
{
    std::stringstream buff4;
    std::streambuf *out4 = std::cout.rdbuf();
    std::cout.rdbuf(buff4.rdbuf());
    
    tiredStudent();

    std::cout.rdbuf(out4);

    std::string str = "Student Jennifer: I'm ready to learn C++.\nStudent Jennifer: I'm learning C++\nStudent Jennifer: I'm learning C++\nStudent Jennifer: I'm learning shit\nStudent Jennifer: Wow, much learning today, very smart, such C++.\n";
    cr_assert_eq(buff4.str(), str);
}

void deanWithTiredStudent(void)
{
    Dean devoile("Devoile");
    Student Jennifer("Jennifer");

    devoile.teachStudent(&Jennifer, "I'm learning C++");
    devoile.teachStudent(&Jennifer, "I'm learning C++");
    devoile.teachStudent(&Jennifer, "I'm learning C++");
}

void giveDrink(void)
{
    Dean devoile("Devoile");
    Student Jennifer("Jennifer");
    Assistant ass_24(24);
    
    devoile.teachStudent(&Jennifer, "I'm learning C++");
    devoile.teachStudent(&Jennifer, "I'm learning C++");
    devoile.teachStudent(&Jennifer, "I'm learning C++");
    createFile(Jennifer.getName() + ".drink", "Red Bull");
    ass_24.helpStudent(&Jennifer);
    std::filesystem::remove(Jennifer.getName() + ".drink");
}

Test(dean_with_tired_student, student_create)
{
    std::stringstream buff4;
    std::streambuf *out4 = std::cout.rdbuf();
    std::cout.rdbuf(buff4.rdbuf());
    
    deanWithTiredStudent();

    std::cout.rdbuf(out4);

    std::string s1 = "Dean Devoile: I'm Dean Devoile! How do you do, fellow kids?\n";
    std::string s2 = "Student Jennifer: I'm ready to learn C++.\n";
    std::string s3 = "Student Jennifer: I'm learning C++\n";
    std::string s5 = "Student Jennifer: I'm learning shit\n";
    std::string s6 = "Dean Devoile: All work and no play makes Jennifer a dull student.\n";
    std::string s7 = "Student Jennifer: Wow, much learning today, very smart, such C++.\n";
    std::string s8 = "Dean Devoile: Time to go home.\n";
    std::string str = s1 + s2 + s3 + s3 + s5 + s6 + s7 + s8;
    cr_assert_eq(buff4.str(), str);
}

Test(give_drink, student_create)
{
    std::stringstream buff4;
    std::streambuf *out4 = std::cout.rdbuf();
    std::cout.rdbuf(buff4.rdbuf());
    
    giveDrink();

    std::cout.rdbuf(out4);

    std::string s1 = "Dean Devoile: I'm Dean Devoile! How do you do, fellow kids?\n";
    std::string s2 = "Student Jennifer: I'm ready to learn C++.\n";
    std::string s3 = "Assistant 24: 'morning everyone *sip coffee*\n";
    std::string s4 = "Student Jennifer: I'm learning C++\n";
    std::string s5 = "Student Jennifer: I'm learning shit\n";
    std::string s6 = "Dean Devoile: All work and no play makes Jennifer a dull student.\n";
    std::string s7 = "Assistant 24: Jennifer needs a Red Bull *sip coffee*\n";
    std::string s8 = "Assistant 24: drink this, Jennifer *sip coffee*\n";
    std::string s9 = "Student Jennifer: Red Bull gives you wings!\n";
    std::string s10 = "Assistant 24: see you tomorrow at 9.00 *sip coffee*\n";
    std::string s11 = "Student Jennifer: Wow, much learning today, very smart, such C++.\n";
    std::string s12 = "Dean Devoile: Time to go home.\n";
    std::string str = s1 + s2 + s3 + s4 + s4 + s5 + s6 + s7 + s8 + s9 + s10 + s11 + s12;
    cr_assert_eq(buff4.str(), str);
}

void checkTimeAssistant()
{
    Assistant ass_24(24);
    ass_24.timeCheck();
}

std::string addToSeminar()
{
    Seminar sem;
    Student Jennifer("Jennifer");

    sem.addStudent(&Jennifer);
    std::string name = sem.getStudentAt(0)->getName();
    return name;
}

Test(add_student, add_a_student)
{
    std::stringstream bu;
    std::streambuf *out = std::cout.rdbuf();
    std::cout.rdbuf(bu.rdbuf());
    
    std::string name = addToSeminar();

    std::cout.rdbuf(out);

    cr_assert_eq(name, "Jennifer");
}

Test(run_seminar, try_)
{
    std::stringstream output;
    std::streambuf *out = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    Seminar sem;
    sem.run();

    std::cout.rdbuf(out);
    cr_assert_eq(output.str(), "Seminar: A C++ seminar needs at least one Dean of Studies, one Assistant and one Student.\n");
}

Test(test_time_assistant, work_status)
{
    std::stringstream buff2;
    std::streambuf *out2 = std::cout.rdbuf();
    std::cout.rdbuf(buff2.rdbuf());

    checkTimeAssistant();

    std::cout.rdbuf(out2);

    std::string str = "Assistant 24: 'morning everyone *sip coffee*\nAssistant 24: Time to teach some serious business *sip coffee*\nAssistant 24: see you tomorrow at 9.00 *sip coffee*\n";
    cr_assert_eq(buff2.str(), str);
}

void checkTimeDean()
{
    Dean devoile("Devoile");
    devoile.timeCheck();
}

Test(test_time_dean, work_status)
{
    std::stringstream output1;
    std::streambuf *out2 = std::cout.rdbuf();
    std::cout.rdbuf(output1.rdbuf());

    checkTimeDean();

    std::cout.rdbuf(out2);

    std::string str = "Dean Devoile: I'm Dean Devoile! How do you do, fellow kids?\nDean Devoile: Where is everyone?\nDean Devoile: Time to go home.\n";
    cr_assert_eq(output1.str(), str);
}

int addAssistantToSeminar()
{
    Seminar sem;
    Assistant ass_24(24);

    sem.addAssistant(&ass_24);
    int id = sem.getAssistantAt(0)->getId();
    return id;
}

Test(add_assistant, add_an_assistant)
{
    std::stringstream bu;
    std::streambuf *out = std::cout.rdbuf();
    std::cout.rdbuf(bu.rdbuf());
    
    int id = addAssistantToSeminar();

    std::cout.rdbuf(out);

    cr_assert_eq(id, 24);
}

std::string addDeanToSeminar()
{
    Seminar sem;
    Dean Devoile("Devoile");

    sem.addDean(&Devoile);
    std::string name = sem.getDeanAt(0)->getName();
    return name;
}

Test(add_dean, add_a_dean)
{
    std::stringstream output2;
    std::streambuf *out = std::cout.rdbuf();
    std::cout.rdbuf(output2.rdbuf());
    
    std::string name = addDeanToSeminar();

    std::cout.rdbuf(out);

    cr_assert_eq(name, "Devoile");
}
