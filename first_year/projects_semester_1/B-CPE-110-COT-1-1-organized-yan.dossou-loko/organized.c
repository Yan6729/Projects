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

int my_list(s_list_t **list, char *TYPE, int ID, char *NAME)
{
    s_list_t *data = NULL;

    if (NAME == NULL)
        return 0;
    data = malloc(sizeof(*data));
    data->TYPE = my_strdup(TYPE);
    data->ID = ID;
    data->NAME = my_strdup(NAME);
    data->next = *list;
    *list = data;
    return 1;
}

int error_three(char *str)
{
    if (str != NULL || str[0] != '\0' || str[0] != ' ')
        return 0;
    else
        return 1;
}

int add(void *data, char **args)
{
    s_list_t **list = (s_list_t **)data;
    int a = 0;
    static int count = 0;
    type_t type;

    if (args[0] == NULL || args[1] == NULL) {
        return 84;
    }
    for (a = 0; args[a] && args[a + 1] != NULL; a += 2) {
        if (error(args[a], args[a + 1]) == 1) {
            my_list(list, args[a], count, args[a + 1]);
            count++;
            mini_printf("%s n°%d - ", (*list)->TYPE, (*list)->ID);
            mini_printf("\"%s\" added.\n", (*list)->NAME);
        } else
            return 84;
    }
}

int main(int ac, char **av)
{
    int a = 0;
    s_list_t *list = NULL;

    a = workshop_shell(&list);
    return a;
}
