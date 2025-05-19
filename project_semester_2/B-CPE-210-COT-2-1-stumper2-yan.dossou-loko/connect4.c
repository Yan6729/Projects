/*
** EPITECH PROJECT, 2025
** connect4.h
** File description:
** fucntion for the duo stumper
*/

#include "connect4.h"

void part1(int tan[2], int lag, char **tab, int lon)
{
    if (tan[0] == 0 || tan[0] == lon + 1) {
        tab[tan[0]][tan[1]] = '+';
    }
    if (tan[0] != 0 && (tan[0] != lon + 1) && (tan[1] == 0 || ((tan[1] + 1)
        % (lag + 2)) == 0)) {
        tab[tan[0]][tan[1]] = '|';
    }
}

char **tab_create(int lag, int lon)
{
    int tan[2] = {0, 0};
    char **tab = malloc(sizeof(char *) * (lon + 3));

    if (lag > 80 || lon > 16 || lag <= 0 || lon <= 0 || (lon * lag) < 20)
        exit(84);
    for (int a = 0; a < lon + 2; a++)
        tab[a] = malloc(sizeof(char) * (lag + 3));
    for (tan[0] = 0; tan[0] < lon + 2; tan[0]++) {
        for (tan[1] = 0; tan[1] < lag + 2; tan[1]++) {
            tab[tan[0]][tan[1]] = '.';
            part1(tan, lag, tab, lon);
        }
        tab[tan[0]][lag + 2] = '\0';
    }
    tab[lon + 2] = NULL;
    return tab;
}

int affiche(int lag, int log, char **tab)
{
    if (lag > 80 || log > 16 || lag <= 0 || log <= 0 || (log * lag) < 20)
        exit(84);
    for (int a = 0; tab[a] != NULL; a++) {
        printf("%s\n", tab[a]);
    }
}

void exited(int ac, char **av)
{
    if (ac % 2 == 0)
        exit(84);
}

int main(int ac, char **av)
{
    char **tab = NULL;
    data_t cmp = {LAG, LON, 'X', 'O', '#'};

    exited(ac, av);
    for (int a = 0; av[a] != NULL; a++) {
        if (strcmp(av[a], "-w") == 0)
            cmp.wight = atoi(av[a + 1]);
        if (strcmp(av[a], "-h") == 0)
            cmp.height = atoi(av[a + 1]);
        if (strcmp(av[a], "-p1") == 0)
            cmp.p1 = av[a + 1][0];
        if (strcmp(av[a], "-p2") == 0)
            cmp.p2 = av[a + 1][0];
        if (strcmp(av[a], "-a") == 0)
            cmp.ref = av[a + 1][0];
    }
    tab = tab_create(cmp.wight, cmp.height);
    game(tab, cmp);
}
