/*
** EPITECH PROJECT, 2024
** Unix sys prog
** File description:
** My top.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int my_wordlen(char const *str, char sep)
{
    int b = 0;
    int a = 0;

    while (str[a] != '\0') {
        if (str[a] == sep)
            b++;
        a++;
    }
    return b + 1;
}

char **alloc(char const *str, char sep, char **r)
{
    r = malloc(sizeof(char *) * (my_wordlen(str, sep) + 1));
    for (int h = 0; h < my_wordlen(str, sep); h++)
        r[h] = (char *) malloc(sizeof(char) * 2000);
    return r;
}

char **str_array(char const *str, char sep)
{
    char **r = NULL;
    int c = 0;
    int b = 0;

    r = alloc(str, sep, r);
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == sep) {
            a = a + 1;
            r[b][c] = '\0';
            c = 0;
            b++;
        }
        r[b][c] = str[a];
        c++;
    }
    r[b][c] = '\0';
    r[b + 1] = NULL;
    return r;
}
