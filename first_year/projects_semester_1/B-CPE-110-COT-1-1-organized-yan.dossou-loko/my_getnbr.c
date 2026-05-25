/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** my_getnbr.c
*/
#include <stdio.h>

int my_getnbr(char const *str)
{
    int a;
    int b = 0;

    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] >= 48 && str[a] <= 57) {
            b = b * 10 + (str[a] - 48);
        }
    }
    return b;
}
