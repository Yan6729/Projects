/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** tests
*/

#include "../Algorithm.hpp"
#include "../Array.hpp"
#include "../Stack.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(algorithm_, test1)
{
    int a = 42;
    int b = 21;
    ::swap(a, b);
    cr_assert_eq(a, 21);
    cr_assert_eq(b, 42);
    int max_ = ::max(a, b);
    cr_assert_eq(max_, 42);
    int min_ = ::min(a, b);
    cr_assert_eq(min_, 21);
    int value_ = ::clamp(0, a, b);
    cr_assert_eq(value_, 21);
    std::string c = "ghi";
    std::string d = "abc";
    ::swap(c, d);
    cr_assert_eq(c, "abc");
    cr_assert_eq(d, "ghi");
    std::string _max = ::min(c, d);
    cr_assert_eq(_max, "abc");
    std::string _min = ::max(c, d);
    cr_assert_eq(_min, "ghi");
    std::string _value = ::clamp(std::string("def"), c, d);
    cr_assert_eq(_value, "def");
}

void function(void)
{
    Array<int, 3> array;
    try {
        array [0] = 21;
        array [1] = 42;
        array [2] = 84;
        array [3] = 84;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << array << std::endl;
    array
        .convert <float >([]( const int & v) { return static_cast<float>(v) / 10.f; })
        .forEach ([]( const float &v) { std::cout << v << std::endl; });
}

Test(test_array, test2)
{
    cr_redirect_stdout();
    cr_redirect_stderr();

    function();

    cr_assert_stderr_eq_str("Out of range\n");
    std::string s = "[21, 42, 84]\n2.1\n4.2\n8.4\n";
    cr_assert_stdout_eq_str(s.c_str());
}

void stack_func(void)
{
    Stack stack;
    stack.push(42.21);
    stack.push(84.42);
    stack.push(21.12);
    stack.add();
    stack.div();
    try {
        stack.mul();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << stack.top() << std::endl;
}

Test(test_stack, test3)
{
    cr_redirect_stdout();
    cr_redirect_stderr();

    stack_func();

    cr_assert_stderr_eq_str("Not enough operands\n");
    cr_assert_stdout_eq_str("2.50036\n");
}

void stack_func2(void)
{
    Stack stack;
    stack.push(0);
    stack.push(12.5);
    stack.push(45.2);
    stack.mul();
    try {
        stack.div();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << stack.top() << std::endl;
}

Test(test_stack2, test4)
{
    cr_redirect_stdout();
    cr_redirect_stderr();

    stack_func2();

    cr_assert_stderr_eq_str("Division by 0 not possible\n");
    cr_assert_stdout_eq_str("565\n");
}

void stack_func3(void)
{
    Stack stack;
    stack.push(14.5);
    stack.push(12.5);
    stack.push(45.2);
    stack.mul();
    stack.div();
    stack.pop();
    try {
        stack.top();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

Test(test_stack3, test5)
{
    cr_redirect_stdout();
    cr_redirect_stderr();

    stack_func3();

    cr_assert_stderr_eq_str("Empty stack\n");
}

void stack_func4(void)
{
    Stack stack;
    stack.push(14.5);
    stack.push(12.5);
    stack.push(45.2);
    stack.add();
    stack.sub();
    try {
        std::cout << stack.top() << std::endl;
        stack.mul();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

Test(test_stack4, test6)
{
   cr_redirect_stdout();
   cr_redirect_stderr();

    stack_func4();

    cr_assert_stderr_eq_str("Not enough operands\n");
    cr_assert_stdout_eq_str("43.2\n");
}
