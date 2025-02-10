/*
** EPITECH PROJECT, 2024
** my_strupcase.c
** File description:
** my_strupcase.c
*/

#include "stumper.h"

char my_strupcase(char c)
{
    int a;

    if (c >= 97 && c <= 122)
        c = c - 32;
    my_putchar(c);
}
