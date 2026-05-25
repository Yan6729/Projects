/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** my_strcat.c
*/
#include <stdio.h>
#include <unistd.h>

int my_strlen3(char *str)
{
    int n;

    n = 0;
    while (str[n] != '\0')
        n++;
    return (n);
}

char *my_strcat(char *dest, char *src)
{
    int b;
    int a;

    a = 0;
    b = my_strlen3(dest);
    while (src[a] != '\0') {
        dest[b] = src[a];
        a++;
        b++;
    }
    dest[b] = '\0';
    return (dest);
}
