/*
** EPITECH PROJECT, 2024
** exo6.c
** File description:
** just an exercice
*/
#include "my.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *part1(int ac, char **av)
{
    int a = my_atoi(av[1]);
    int b = strlen(av[2]);
    int c = 0;
    int e = (a * a) + a + 1;
    char *str;
    int d = 0;

    my_put_nbr(a);
    my_putchar('\n');
    str = malloc(sizeof(char) * (e + 1));
    for (d = 0; d < (e - 1); d++) {
        if (d % (a + 1) == a) {
            str[d] = '\n';
        } else {
            str[d] = av[2][c];
            c = (c + 1) % b;
        }
    }
    str[e - 1] = '\0';
    return str;
}

char **generator(int ac, char **av)
{
    int i;
    int c;
    char *src;
    int a = 0;
    int b = 0;
    char **map;

    src = part1(ac, av);
    map = my_malloc(src, ac, av);
    for (c = 0; src[c] != '\0'; c++) {
        map[a][b] = src[c];
        b++;
        if (src[c] == '\n') {
            map[a][b] = '\0';
            b = 0;
            a++;
        }
    }
    map[a][b] = '\0';
    return map;
}
