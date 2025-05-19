/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** To print sentence
*/

#include "../include/tail.h"

int my_putstr(char const *str)
{
    int tbe = 0;

    for (tbe = 0; str[tbe] != '\0'; tbe++) {
        my_putchar(str[tbe]);
    }
    return 0;
}
