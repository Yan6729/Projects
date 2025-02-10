/*
** EPITECH PROJECT, 2024
** organized.c
** File description:
** organized.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shell.h"

int my_list(s_list_t **list, char *string)
{
    s_list_t *data = NULL;

    data = malloc(sizeof(*data));
    data->string = my_strdup(string);
    data->next = *list;
    *list = data;
    return 0;
}

int add(int ac, char **av)
{
    s_list_t **list = (s_list_t **)data;
    int a = 0;
    char **tab = my_strwrdarray(av[1]);

    if (args[0] == NULL) {
        return 84;
    }
    for (a = 0; tab[a] != NULL; a++) {
        my_list(list, tab[a]);
    }
}

int main(int ac, char **av)
{
    int a = 0;
    s_list_t *list = NULL;

    a = workshop_shell(&list);
    return a;
}
