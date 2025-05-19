/*
** EPITECH PROJECT, 2025
** my_strlen.c
** File description:
** just a fuction
*/

#include "../../include/struct.h"

int my_strlen(char const *str)
{
    int b = 0;

    for (int a = 0; str[a] != '\0'; a++) {
        b++;
    }
    return b;
}
