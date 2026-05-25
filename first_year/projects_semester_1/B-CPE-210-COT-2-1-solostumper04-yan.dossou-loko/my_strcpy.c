/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** my_strcpy.c
*/

#include <stdio.h>
#include "stumper.h"

char *my_strcpy(char *dest, char const *src)
{
    int a;

    a = 0;
    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}
