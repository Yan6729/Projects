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

int main(int ac, char **av)
{
    printf("%s", my_revstr(av[1]));
    printf("%d", my_strcmp(my_revstr(av[1])));
}
