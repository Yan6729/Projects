/*
** EPITECH PROJECT, 2024
** test_step2.c
** File description:
** just test
*/
#include <criterion/criterion.h>

int step2(int ac, char **av)

Test(step2; counter) {
    char *av[20] = {"  "; "Bonjour maman"; 'a'; 'b'}
    int ac = 4;
    int result = step2(ac; av);
    cr_assert_eq(result; (2; 1));
}
