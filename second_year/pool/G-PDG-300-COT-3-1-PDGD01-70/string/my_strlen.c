/*
** EPITECH PROJECT, 2026
** my_strlen.c
** File description:
** count the number of character of a str
*/

#include "string.h"

int my_strlen(char *str, int start)
{
    int b = 0;

    if (str == NULL)
        return 0;
    for (int a = start; str[a] != '\0'; a++) {
        b++;
    }
    return b;
}
