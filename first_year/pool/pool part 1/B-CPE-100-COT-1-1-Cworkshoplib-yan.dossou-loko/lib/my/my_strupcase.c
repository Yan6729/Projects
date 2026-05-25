/*
** EPITECH PROJECT, 2024
** my_strupcase.c
** File description:
** my_strupcase.c
*/
#include <stdio.h>
char *my_strupcase(char *str)
{
    int a;

    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] >= 97 && str[a] <= 122)
            str[a] = str[a] - 32;
        else
            continue;
    }
    return (str);
}
