/*
** EPITECH PROJECT, 2024
** convert.c
** File description:
** just an optional fonction
*/
#include <string.h>
#include <stdio.h>
#include "mytop.h"

int convert(char ch[])
{
    int i;
    int n = 0;

    for (i = 0; ch[i] != '\0'; ++i)
        if (ch[i] >= 48 && ch[i] <= 57)
            n = n * 10 + (ch[i] - 48);
    return n;
}
