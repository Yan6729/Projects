/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** tests
*/

#include "Paladin.hpp"
#include <criterion/criterion.h>

void ex00_1(void)
{
    Peasant peasant("Gildas", 42);

    peasant.damage(50);
    peasant.damage(100);
    peasant.damage(200);
    peasant.rest();
}

void ex00_2(void)
{
    Peasant peasant("Gildas", 42);

    peasant.damage(50);
    peasant.rest();
    peasant.damage(100);
    peasant.damage(200);
}

void ex00_3(void)
{
    Peasant peasant("Gildas", 42);

    peasant.damage(50);
    peasant.rest();
    peasant.attack();
    peasant.damage(100);
    peasant.damage(200);
}

void ex00_4(void)
{
    Peasant peasant("Gildas", 42);

    peasant.damage(50);
    peasant.rest();
    peasant.special();
    peasant.attack();
    peasant.damage(100);
    peasant.damage(200);
}

void ex00_5(void)
{
    Peasant peasant("Gildas", 42);

    peasant.damage(50);
    peasant.rest();
    peasant.rest();
    peasant.attack();
    peasant.damage(20);
    peasant.special();
    peasant.damage(99);
}

Test(test_ex00_1, test1)
{
    std::stringstream buf;
    std::streambuf *out = std::cout.rdbuf();
    std::cout.rdbuf(buf.rdbuf());

    ex00_1();

    std::cout.rdbuf(out);

    std::string s1 = "Gildas goes for an adventure.\n";
    std::string s2 = "Gildas takes 50 damage.\n";
    std::string s3 = "Gildas is out of combat.\n";
    std::string s4 = "Gildas is out of combat.\n";
    std::string s5 = "Gildas is out of combat.\n";
    std::string s6 = "Gildas is back to his crops.\n";
    std::string s = s1 + s2 + s3 + s4 + s5 + s6;
    cr_assert_eq(buf.str(), s);
}

Test(test_ex00_2, test2)
{
    std::stringstream buf;
    std::streambuf *out = std::cout.rdbuf();
    std::cout.rdbuf(buf.rdbuf());

    ex00_2();

    std::cout.rdbuf(out);

    std::string s1 = "Gildas goes for an adventure.\n";
    std::string s2 = "Gildas takes 50 damage.\n";
    std::string s3 = "Gildas takes a nap.\n";
    std::string s4 = "Gildas is out of combat.\n";
    std::string s5 = "Gildas is out of combat.\n";
    std::string s6 = "Gildas is back to his crops.\n";
    std::string s = s1 + s2 + s3 + s4 + s5 + s6;
    cr_assert_eq(buf.str(), s);
}

Test(test_ex00_3, test3)
{
    std::stringstream buf;
    std::streambuf *out = std::cout.rdbuf();
    std::cout.rdbuf(buf.rdbuf());

    ex00_3();

    std::cout.rdbuf(out);

    std::string s1 = "Gildas goes for an adventure.\n";
    std::string s2 = "Gildas takes 50 damage.\n";
    std::string s3 = "Gildas takes a nap.\n";
    std::string s4 = "Gildas tosses a stone.\n";
    std::string s5 = "Gildas is out of combat.\n";
    std::string s6 = "Gildas is out of combat.\n";
    std::string s7 = "Gildas is back to his crops.\n";
    std::string s = s1 + s2 + s3 + s4 + s5 + s6 + s7;
    cr_assert_eq(buf.str(), s);
}

Test(test_ex00_4, test4)
{
    std::stringstream buf;
    std::streambuf *out = std::cout.rdbuf();
    std::cout.rdbuf(buf.rdbuf());

    ex00_4();

    std::cout.rdbuf(out);

    std::string s1 = "Gildas goes for an adventure.\n";
    std::string s2 = "Gildas takes 50 damage.\n";
    std::string s3 = "Gildas takes a nap.\n";
    std::string s4 = "Gildas doesn't know any special move.\n";
    std::string s5 = "Gildas tosses a stone.\n";
    std::string s6 = "Gildas is out of combat.\n";
    std::string s7 = "Gildas is out of combat.\n";
    std::string s8 = "Gildas is back to his crops.\n";
    std::string s = s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8;
    cr_assert_eq(buf.str(), s);
}

Test(test_ex00_5, test5)
{
    std::stringstream buf;
    std::streambuf *out = std::cout.rdbuf();
    std::cout.rdbuf(buf.rdbuf());

    ex00_5();

    std::cout.rdbuf(out);

    std::string s1 = "Gildas goes for an adventure.\n";
    std::string s2 = "Gildas takes 50 damage.\n";
    std::string s3 = "Gildas takes a nap.\n";
    std::string s4 = "Gildas tosses a stone.\n";
    std::string s5 = "Gildas takes 20 damage.\n";
    std::string s6 = "Gildas doesn't know any special move.\n";
    std::string s7 = "Gildas is out of combat.\n";
    std::string s8 = "Gildas is back to his crops.\n";
    std::string s = s1 + s2 + s3 + s3 + s4 + s5 + s6 + s7 + s8;
    cr_assert_eq(buf.str(), s);
}
