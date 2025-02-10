/*
** EPITECH PROJECT, 2024
** my_malloc.c
** File description:
** Function to made allocation
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char **my_malloc(char *src, int ac, char **av)
{
    int lig = my_cmpworld(src);
    int col = my_strlen(src);
    int i = 0;
    char **map;

    map = malloc(sizeof(char *) * (lig + 1));
    for (i = 0; i < lig; i++)
        map[i] = malloc(sizeof(char) * (col + 1));
    return map;
}
