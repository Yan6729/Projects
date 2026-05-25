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

int tail(int a, char *filepath);
int my_putstr(char const *str);

Test(tail, one_line_tail, .init = redirect_all_stdout)
{
    const char *filename = "test_tail1.txt";
    FILE *file = fopen(filename, "w");
    fprintf(file, "line1\nline2\nline3\n");
    fclose(file);

    tail(1, (char *)filename);
    cr_assert_stdout_eq_str("line3\n");

    remove(filename);
}

Test(tail, three_lines_tail, .init = redirect_all_stdout)
{
    const char *filename = "test_tail2.txt";
    FILE *file = fopen(filename, "w");
    fprintf(file, "a\nb\nc\nd\ne\n");
    fclose(file);

    tail(3, (char *)filename);
    cr_assert_stdout_eq_str("c\nd\ne\n");

    remove(filename);
}

Test (my_putstr, lowercase_characters, .init = redirect_all_stdout)
{
    my_putstr("Hello world ");
    cr_assert_stdout_eq_str("Hello world ", "Expected other thing");
}

Test (my_putstr, upper_characters, .init = redirect_all_stdout)
{
    my_putstr("TATA");
    cr_assert_stdout_eq_str("TATA", "Expected other thing");
}

Test (my_putstr, special_characters, .init = redirect_all_stdout)
{
    my_putstr("*ù$");
    cr_assert_stdout_eq_str("*ù$", "Expected other thing");
}
