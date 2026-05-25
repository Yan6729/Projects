/*
** EPITECH PROJECT, 2025
** step3.c
** File description:
** une simple fonction
*/

#include "my.h"

int my_strlen(char *str)
{
    int a = 0;
    int b = 0;

    for (a = 0; str[a] != '\0'; a++) {
        b++;
    }
    return b;
}

int my_cmpworld(char *str)
{
    int a = 0;
    int b = 1;

    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] == ' ')
            b++;
        else
            continue;
    }
    return b;
}

char **my_strwrldarray(char *str)
{
    int variable[2] = {my_strlen(str), my_cmpworld(str)};
    int a[2] = {0, 0};
    char **tableau = NULL;

    tableau = malloc(sizeof(char *) * (variable[0] + 1));
    for (int i = 0; i < (variable[0] + 1); i++)
        tableau[i] = malloc(sizeof(char) * (variable[1] +1));
    for (int c = 0; str[c] != '\0'; c++) {
        tableau[a[0]][a[1]] = str[c];
        a[1]++;
        if (str[c + 1] == ' ') {
            c++;
            tableau[a[0]][a[1]] = '\0';
            a[1] = 0;
            a[0]++;
        }
    }
    tableau[a[0] + 1] = NULL;
    return tableau;
}

void print_arg(char **arg)
{
    while (*arg) {
        my_puts(*arg);
        my_putchar('\n');
        arg++;
    }
}
