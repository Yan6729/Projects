/*
** EPITECH PROJECT, 2025
** my_strcpy.c
** File description:
** just a file
*/

#include "../../include/robot.h"

char *my_strcpy(char *dest, char const *src)
{
    int a;

    for (a = 0; src[a] != '\0'; a++) {
        dest[a] = src[a];
    }
    dest[a] = '\0';
    return (dest);
}

char *my_strncpy(char *dest, char const *src, int size)
{
    int a;

    for (a = 0; a < size; a++) {
        dest[a] = src[a];
    }
    dest[a] = '\0';
    return (dest);
}
