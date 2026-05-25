/*
** EPITECH PROJECT, 2024
** my_revstr.c
** File description:
** my_revstr.c
*/
#include <string.h>
#include <stdio.h>
#include "stumper.h"

char *my_revstr(char *str)
{
    int len;
    int i;
    char *deb;
    char *fin;
    char inter;

    len = my_strlen(str);
    deb = str;
    fin = str;
    for (i = 0; i < len - 1; i++)
        fin++;
    for (i = 0; i < len / 2; i++) {
        inter = *fin;
        *fin = *deb;
        *deb = inter;
        deb++;
        fin--;
    }
    return (str);
}

char *revstr(char *str)
{
    int length = strlen(str);
    char *revst = malloc(sizeof(char) * length);
    int b = 0;

    for (int a = length - 1; a >= 0; a--) {
        revst[b] = str[a];
        b++;
    }
    revst[length] = '\0';
    return revst;
}
