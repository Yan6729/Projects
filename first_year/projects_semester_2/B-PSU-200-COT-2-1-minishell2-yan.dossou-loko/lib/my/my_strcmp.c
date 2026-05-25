/*
** EPITECH PROJECT, 2025
** my_strcmp2.c
** File description:
** other strcmp
*/

#include "../../include/mysh.h"

int my_strcmp(char *str1, char *str2)
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

int my_strncmp(char *str1, char *str2, size_t lim)
{
    int i = 0;

    while (i < lim && str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    if (i < lim) {
        return str1[i] - str2[i];
    }
    return 0;
}
