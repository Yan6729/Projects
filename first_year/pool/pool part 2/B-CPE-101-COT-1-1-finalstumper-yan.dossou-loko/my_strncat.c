/*
** EPITECH PROJECT, 2024
** my_strncat.c
** File description:
** my_strncat.c
*/

#include <unistd.h>
#include <stdio.h>

int my_strlen(char const *str)
{
    int x = 0;

    while (str[x] != '\0') {
        x++;
    }
    return x;
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int x;
    int y = 0;

    x = my_strlen(dest);
    for (y = 0; src[y] != '\0' && x < nb; y++) {
        dest[x + y] = src[y];
    }
    if (y < nb) {
        dest[x + y] = '\0';
    }
    return dest;
}
