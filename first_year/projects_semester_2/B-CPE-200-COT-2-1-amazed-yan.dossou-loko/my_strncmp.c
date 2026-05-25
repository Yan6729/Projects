/*
** EPITECH PROJECT, 2024
** my_strncmp.c
** File description:
** strncmp
*/

#include <string.h>
#include "my.h"
#include <stdio.h>

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    for (; i < n; i++) {
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            return (s1[i] - s2[i]);
    }
    return 0;
}
