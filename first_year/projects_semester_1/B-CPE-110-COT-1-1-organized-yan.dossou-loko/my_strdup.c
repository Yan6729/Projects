/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** my_strdup.c
*/
#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

char *my_strdup(char const *src)
{
    int b;
    int a;
    char *str;

    a = my_strlen(src) + 1;
    str = (char *)malloc(a);
    b = 0;
    while (src[b] != '\0') {
        str[b] = src[b];
        b++;
    }
    str[b] = '\0';
    return (str);
}
