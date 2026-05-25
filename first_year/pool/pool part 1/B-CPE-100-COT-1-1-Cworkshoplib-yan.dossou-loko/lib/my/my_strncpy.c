/*
** EPITECH PROJECT, 2024
** my_strncpy.c
** File description:
** my_strncpy.c
*/

#include <stdio.h>
int my_strlen(char const *str)
{
    int b;

    for (b = 0; str[b] != '\0'; b++);
    return (b);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int b = my_strlen(src);

    for (i = 0; src[i] != '\0' && i < n; i++) {
        dest[i] = src[i];
    }
    if (n > b) {
        dest[b] = '\0';
    }
    return (dest);
}
