/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** just a file
*/

#include "crocus.h"

void disp(char **tab)
{
    for (int a = 0; tab[a] != NULL; a++) {
        printf("%s\n", tab[a]);
    }
}

int main(int ac, char **av)
{
    char **tab = NULL;

    if (ac == 1 || ac % 2 == 0)
        exit(84);
    if (strcmp(av[1], "-n") == 0) {
        for (int a = 0; av[2][a] != '\0'; a++) {
            tab = create_tab(av[2][a], '0');
            disp(tab);
        }
    }
}
