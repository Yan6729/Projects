/*
** EPITECH PROJECT, 2025
** delete
** File description:
** del.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

void delete(s_list_t **begin, s_list_t *prev,
    s_list_t *curr, char *args)
{
    s_list_t *del = NULL;

    if (my_getnbr(args) == (*begin)->ID) {
        del = (*begin);
        *begin = (*begin)->next;
        mini_printf("%s n°%d - \"%s\" deleted.\n",
            del->TYPE, del->ID, del->NAME);
        free(del);
    } else if (my_getnbr(args) == curr->ID) {
        del = curr;
        prev->next = curr->next;
        curr = prev;
        mini_printf("%s n°%d - \"%s\" deleted.\n",
            del->TYPE, del->ID, del->NAME);
        free(del);
    }
}

int del(void *data, char **args)
{
    s_list_t **dis = (s_list_t **)data;
    s_list_t *prev = NULL;
    s_list_t *di = *dis;
    int n = 0;
    int id;

    if (args[0] == NULL)
        return 84;
    for (; args[n] != NULL; n++) {
        for (di = *dis; di != NULL;) {
            delete(dis, prev, di, args[n]);
            prev = di;
            di = di->next;
        }
    }
}
