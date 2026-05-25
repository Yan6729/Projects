/*
** EPITECH PROJECT, 2024
** my_malloc.c
** File description:
** Function to made allocation
*/

#include "my.h"

char **my_malloc(char *src)
{
    int lig = my_cmpword(src);
    int col = my_strlen(src);
    int i = 0;
    char **map;

    map = malloc(sizeof(char *) * (lig + 2));
    for (i = 0; i < lig; i++)
        map[i] = malloc(sizeof(char) * (col + 1));
    return map;
}
