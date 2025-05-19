/*
** EPITECH PROJECT, 2025
** copie.c
** File description:
** just a test
*/

#include "../include/math.h"

char **copie(int ac, char **av)
{
    int b = 0;
    char **tab =  malloc(sizeof(char *) * (ac));

    for (int a = 1; av[a] != NULL; a++) {
	tab[b] = strdup(av[a]);
	b++;
    }
    tab[ac] = NULL;
    return tab;
}
char ***test(int ac, char **av)
{
    int b = 0;
    char ***map = malloc(sizeof(char **) * ac);
    char **tab = copie(ac, av);

    for (int a = 0; tab[a] != NULL; a++) {
	map[b] = my_split(tab[a], "*");
	b++;
    }
}
