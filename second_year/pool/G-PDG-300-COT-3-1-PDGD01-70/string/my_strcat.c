/*
** EPITECH PROJECT, 2026
** my_strcat.c
** File description:
** just a function to concatenate two str
*/

#include "string.h"

char *my_strcat(char *dest, char const *src)
{
    int x = 0;
    int y = 0;

    x = strlen(dest);
    while (src[y] != '\0') {
        dest[x + y] = src[y];
        y++;
    }
    dest[x + y] = '\0';
    return dest;
}
