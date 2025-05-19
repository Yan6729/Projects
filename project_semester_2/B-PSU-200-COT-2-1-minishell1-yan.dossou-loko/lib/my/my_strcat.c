/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** my_strcat.c
*/

#include "../../include/mysh.h"

char *my_strcat(char *dest, char const *src)
{
    int x = 0;
    int y = 0;

    x = my_strlen(dest);
    while (src[y] != '\0') {
        dest[x + y] = src[y];
        y++;
    }
    dest[x + y] = '\0';
    return dest;
}
