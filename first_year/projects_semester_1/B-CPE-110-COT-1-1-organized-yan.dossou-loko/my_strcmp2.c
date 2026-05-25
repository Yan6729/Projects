/*
** EPITECH PROJECT, 2025
** my_strcmp2.c
** File description:
** other strcmp
*/

#include "shell.h"

int my_strcmp2(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2)) {
        if (my_strlen(str1) < my_strlen(str2)) {
            return (-1);
        }
        if (my_strlen(str1) > my_strlen(str2)) {
            return (1);
        }
    }
    for (int i = 0; i < my_strlen(str1); i++) {
        if (str1[i] < str2[i]) {
            return (-1);
        }
        if (str1[i] > str2[i]) {
            return (1);
        }
    }
    return (0);
}
