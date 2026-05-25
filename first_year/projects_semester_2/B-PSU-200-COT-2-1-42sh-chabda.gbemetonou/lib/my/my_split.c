/*
** EPITECH PROJECT, 2025
** my_split_aide.c
** File description:
** just a file
*/

#include "../../include/shell.h"

int size_lis(tab_t **list)
{
    int size = 0;
    tab_t *tmp = NULL;

    for (tmp = *list; tmp != NULL; tmp = tmp->next) {
        size++;
    }
    return size;
}

char **my_split(char *str, const char *delim)
{
    tab_t *list = str_to_list(str, delim);
    tab_t *tmp = NULL;
    int a = 0;
    int size = size_lis(&list);
    char **tab = malloc(sizeof(char *) * (size + 1));

    for (tmp = list; tmp != NULL; tmp = tmp->next) {
        tab[a] = my_strdup(tmp->string, 0);
        if (tmp->is_sep == 0) {
            tab[a] = my_strdup(cleanstr(tmp->string, 0), 0);
        }
        a++;
    }
    tab[a] = NULL;
    free_litb(list);
    return tab;
}
