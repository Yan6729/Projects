/*
** EPITECH PROJECT, 2024
** my_strlowcase.c
** File description:
** my_strlowcase.c
*/
#include "stumper.h"

char my_strlowcase(char c)
{
    int a;

    if (c >= 65 && c <= 90)
        c = c + 32;
    my_putchar(c);
}
