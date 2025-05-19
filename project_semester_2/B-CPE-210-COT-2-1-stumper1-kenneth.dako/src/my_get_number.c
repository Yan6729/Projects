/*
** EPITECH PROJECT, 2024
** Organise
** File description:
** A function to get numbers into a char caracters
*/

#include "../include/tail.h"

int my_getnbr(char const *str)
{
    int result;
    int sign;
    int i;

    result = 0;
    sign = 1;
    i = 0;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            sign *= 1;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}
