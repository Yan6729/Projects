/*
** EPITECH PROJECT, 2025
** step.c
** File description:
** test function
*/

#include "../include/mysh.h"

void step2(int ac, char **av, char **env)
{
    char *str[] = {av[1], NULL};

    if (ac == 1)
        return;
    else if (ac == 2) {
        execve(av[1], str, env);
    } else {
        execve(av[1], av, env);
    }
}
