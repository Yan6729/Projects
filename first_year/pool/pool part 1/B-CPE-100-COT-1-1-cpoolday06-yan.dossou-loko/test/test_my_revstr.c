/*
** EPITECH PROJECT, 2024
** test_my_revstr
** File description:
** test_my_revstr
*/

#include <criterion/criterion.h>

Test(my_revstr, testing_the_function)
{
    char dest[6] = {0};

    my_strncpy(dest, "Hello", 5);
    cr_assert_str_ep(dest, "olleH");
}
