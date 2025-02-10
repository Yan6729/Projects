/*
** EPITECH PROJECT, 2025
** usnameformater.c
** File description:
** stumper function
*/

#include "stumper.h"
#include <stdio.h>

void intermediate(int ac, char **av)
{
    int a = 0;
    int b = 2;

    for (a = 0; av[1][a] != '\0'; a++) {
        my_strupcase(av[1][a]);
        if (av[1][a - 1] == ' ' && av[1][a + 1] == ' ')
            my_putchar('.');
    }
    my_putchar('\n');
}

int main(int ac, char **av)
{
    if (av[1][0] == '\0') {
	write(2, "USNameFormatter string", 22);
        return 84;
    }
    if (av[1][0] == ' ' && av[1][1] == '\0')
	return 84;
    intermediate(ac, av);
}
