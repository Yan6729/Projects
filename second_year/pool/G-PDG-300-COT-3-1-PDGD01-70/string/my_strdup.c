/*
** EPITECH PROJECT, 2026
** my_stdup.c
** File description:
** contain my_strdup and my_strndup
*/

#include "string.h"

char *my_strdup(char const *src, int lim)
{
    int b;
    int a;
    int d = 0;
    char *str;

    if (!src)
        return NULL;
    a = my_strlen((char *)src, 0) - lim;
    str = malloc(sizeof(char) * (a + 1));
    for (b = lim; src[b] != '\0'; b++) {
        str[d] = src[b];
        d++;
    }
    str[d] = '\0';
    return (str);
}

char *my_strndup(char const *src, int lim, int size)
{
    int b;
    int a;
    int d = 0;
    char *str;

    a = my_strlen((char *)src, 0) - lim;
    str = (char *)malloc(a);
    for (b = lim; b < size; b++) {
        str[d] = src[b];
        d++;
    }
    str[d] = '\0';
    return (str);
}
