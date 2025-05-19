/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** my_strdup.c
*/

#include "../include/tail.h"

char *my_strdup(char const *src, int lim)
{
    int b;
    int a;
    int d = 0;
    char *str;

    a = my_strlen(src) - lim;
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

    a = my_strlen(src) - lim;
    str = (char *)malloc(a);
    for (b = lim; b < size; b++) {
        str[d] = src[b];
        d++;
    }
    str[d] = '\0';
    return (str);
}
