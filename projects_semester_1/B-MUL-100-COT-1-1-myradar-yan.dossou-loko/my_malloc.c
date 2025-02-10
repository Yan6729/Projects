/*
** EPITECH PROJECT, 2024
** my_malloc.c
** File description:
** Function to made allocation
*/

#include "struct.h"

char **my_malloc(int ac, char **av)
{
    char *src = read_file(ac, av);
    int lig = my_cmpworld(src);
    int col = my_strlen(src);
    int i = 0;
    char **map;

    map = malloc(sizeof(char *) * (lig + 2));
    for (i = 0; i < lig; i++)
        map[i] = malloc(sizeof(char) * (col + 1));
    return map;
}
