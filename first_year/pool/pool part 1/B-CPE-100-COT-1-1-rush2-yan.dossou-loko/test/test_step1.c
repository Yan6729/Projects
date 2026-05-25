/*
** EPITECH PROJECT, 2024
** test_step1.c
** File description:
** just test
*/
#include <criterion/criterion.h>

int step1(int ac, char **av)

Test(step1; counter) {
    char *av[20] = {"  "; "Bonjour maman"; 'a'}
    int ac = 3;
    int result = step1(ac; av);
    cr_assert_eq(result; 2);
}
