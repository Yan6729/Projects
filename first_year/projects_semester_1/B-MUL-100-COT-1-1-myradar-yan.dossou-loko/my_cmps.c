/*
** EPITECH PROJECT, 2024
** my_cmps.c
** File description:
** an intermediar function
*/

#include "struct.h"

int my_cmpworld(char *str)
{
    int a = 0;
    int b = 1;

    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] == '\n' || str[a] == ' ' || str[a] == '\r')
            b++;
        else
            continue;
    }
    return b;
}
