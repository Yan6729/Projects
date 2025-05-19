/*
** EPITECH PROJECT, 2025
** step.c
** File description:
** test function
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void step1(int ac, char **av, char **env)
{
    for (int a = 0; env[a] != NULL; a++)
        my_puts(env[a]);
}

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
