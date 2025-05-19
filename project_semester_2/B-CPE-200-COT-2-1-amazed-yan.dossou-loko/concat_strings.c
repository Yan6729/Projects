/*
** EPITECH PROJECT, 2024
** concat_strings.c
** File description:
** concat_strings.c
*/

#include <stdio.h>
#include "my.h"

char *concat_strings(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i++;
    for (; src[j] != '\0'; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
