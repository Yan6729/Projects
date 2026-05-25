/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** my_putstr.c
*/
#include "stumper.h"

int my_putstr(char const *str)
{
    int a;

    for (a = 0; str[a] != '\0'; a++) {
        my_putchar(str[a]);
    }
    return 0;
}
