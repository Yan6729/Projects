/*
** EPITECH PROJECT, 2025
** my_strlen.c
** File description:
** my_strlen.c
*/

#include "../../include/mysh.h"

int my_strlen(char const *str)
{
    int a = 0;
    int b = 0;

    for (a = 0; str[a] != '\0'; a++) {
        b++;
    }
    return b;
}
