/*
** EPITECH PROJECT, 2025
** check_digit
** File description:
** check if it's a number or not
*/

#include "math.h"

int check_digit(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 48 && str[i] <= 57)
            return 1;
    }
    return 0;
}
