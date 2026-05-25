/*
** EPITECH PROJECT, 2024
** my_strlowcase.c
** File description:
** my_strlowcase.c
*/

#include "stumper.h"

char *my_strlowcase(char *str)
{
    int a;

    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] >= 65 && str[a] <= 90)
            str[a] = str[a] + 32;
        else
            continue;
    }
    return (str);
}
