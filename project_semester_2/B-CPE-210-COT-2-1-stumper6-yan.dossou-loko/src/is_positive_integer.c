/*
** EPITECH PROJECT, 2025
** is_positive_integer.c
** File description:
** just a file
*/

#include "../include/stumper.h"

int is_positive_integer(const char *str)
{
    if (str == NULL || *str == '\0')
        return 84;
    while (*str) {
        if (!my_is_digit(*str))
            return 84;
        str++;
    }
    return 0;
}
