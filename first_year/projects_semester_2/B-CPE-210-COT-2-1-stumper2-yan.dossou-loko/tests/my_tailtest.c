/*
** EPITECH PROJECT, 2024
** test_my_isneg.c
** File description:
** A unit test who
** test mini_printf
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <criterion/redirect.h>
#include <stdio.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

char *data = "100000";

int tail(int a, char *filepath);

Test(tail, firs_test, .init = redirect_all_stdout)
{
    tail(1, data);
    cr_assert_stdout_eq_str("100000", "Expected annother thing");
}
