/*
** EPITECH PROJECT, 2025
** no sens arguments file tester handle
** File description:
** just a file
*/

#include "../include/math.h"

int point(char *str)
{
    int b = 0;

    for (int a = 0; str[a] != '\0'; a++)
        if (str[a] == '.' || str[a] == ',') {
            b++;
        }
    return b;
}
