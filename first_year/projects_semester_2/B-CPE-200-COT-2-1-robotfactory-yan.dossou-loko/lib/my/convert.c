/*
** EPITECH PROJECT, 2024
** convert.c
** File description:
** just an optional fonction
*/

#include "../../include/robot.h"

int convert(char const *str)
{
    int a;
    int b = 0;
    int mark = 1;

    for (a = 0; str[a] == '-' || str[a] == '+'; a++) {
        if (str[a] == '-') {
            mark *= -1;
        }
    }
    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] >= 48 && str[a] <= 57) {
            b = b * 10 + (str[a] - 48);
        }
        if (str[a] == '-' || str[a] == '+') {
            continue;
        }
    }
    return (b * mark);
}
