/*
** EPITECH PROJECT, 2024
** my_atoi.c
** File description:
** just a usual function
*/

#include <stdio.h>

int my_atoi(char const *str)
{
    int b = 0;
    int a;
    int nombre = 0;
    int signe = 1;

    for (a = 0; str[a] == '-' || str[a] == '+'; a++) {
        if (str[a] == '-') {
            signe = signe * (-1);
        }
    }
    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] >= '0' && str[a] <= '9') {
            b = b * 10 + (str[a] - '0');
        }
        if (str[a] == '-' || str[a] == '+') {
            continue;
        }
    }
    return (b * signe);
}
