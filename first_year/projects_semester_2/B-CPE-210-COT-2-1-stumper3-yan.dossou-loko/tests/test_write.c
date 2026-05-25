/*
** EPITECH PROJECT, 2025
** EPITECH PROJECT, 2025
** File description:
** TES
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int function1(const char *str);
Test(function1, num)
{
    int a = function1("azerty");
    cr_assert_eq(a, 0);
}
