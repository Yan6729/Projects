/*
** EPITECH PROJECT, 2025
** emacs
** File description:
** emacs
*/

#include "../include/my.h"

char **tab_list(char *buf, int size, char *sep)
{
    char **tab = malloc(sizeof(char *) * size);
    char *temp = NULL;
    int a = 0;
    char *new = NULL;

    temp = strtok(buf, sep);
    while (temp != NULL) {
        new = strdup(temp);
        tab[a] = format_cmd(new);
        a++;
        free(new);
        temp = strtok(NULL, sep);
    }
    tab[a] = NULL;
    free(buf);
    return tab;
}

void free_tab(char **tab)
{
    for (int a = 0; tab[a] != NULL; a++)
        free(tab[a]);
    free(tab);
}
