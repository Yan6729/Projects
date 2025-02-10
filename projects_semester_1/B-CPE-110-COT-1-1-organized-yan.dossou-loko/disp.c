/*
** EPITECH PROJECT, 2024
** dsip.c
** File description:
** disp.c
*/

#include <stdlib.h>
#include "shell.h"

int disp2(void *data, char **args)
{
    s_list_t **list = (s_list_t **)data;
    s_list_t *tmp = *list;

    *list = mergesort_type(*list);
    for (tmp; tmp != NULL; tmp = tmp->next) {
        mini_printf("%s n°%d - ", tmp->TYPE, tmp->ID);
        mini_printf("\"%s\"\n", tmp->NAME);
    }
    return 0;
}

int disp1(void *data, char **args)
{
    s_list_t **list = (s_list_t **)data;
    s_list_t *tmp = *list;

    for (tmp; tmp != NULL; tmp = tmp->next) {
        mini_printf("%s n°%d - ", tmp->TYPE, tmp->ID);
        mini_printf("\"%s\"\n", tmp->NAME);
    }
    return 0;
}

int disp(void *data, char **args)
{
    if (args[0] == NULL)
        disp1(data, args);
    else if (my_strcmp(args[0], "-r") == 0)
        disp2(data, args);
    else
        return 84;
}
