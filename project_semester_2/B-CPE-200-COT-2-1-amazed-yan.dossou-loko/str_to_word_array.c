/*
** EPITECH PROJECT, 2024
** str_to_word_array
** File description:
** str to word array
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"

int count_line(char *str, char c)
{
    int i = 0;
    int count = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == c)
            count++;
    }
    return count + 1;
}

int count_col(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return i;
}

int count_tab_line(char **tab)
{
    int i = 0;

    for (i = 0; tab[i] != NULL; i++);
    return i;
}

char **tab_alloc(char *str, char var)
{
    int l = count_line(str, var);
    int c = count_col(str);
    char **tab = malloc(sizeof(char *) * (l + 1));

    for (int i = 0; i < l; i++) {
        tab[i] = malloc(sizeof(char) * (c + 1));
        for (int j = 0; j < c + 1; j++)
        tab[i][j] = '\0';
    }
    return tab;
}

char **my_str_to_word_array(char *str, char c)
{
    int j = 0;
    int k = 0;
    int i;
    char **tab = tab_alloc(str, c);

    clean_str(str);
    for (i = 0; str[i] != '\0';) {
        if (str[i] == c) {
            i++;
            tab[j][k] = '\0';
            j++;
            k = 0;
        } else {
            tab[j][k] = str[i];
            k++;
            i++;
        }
    }
    tab[j + 1] = NULL;
    return tab;
}
