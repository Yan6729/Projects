/*
** EPITECH PROJECT, 2024
** sort.c
** File description:
** sort.c
*/

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

s_list_t *split(s_list_t *head)
{
    s_list_t *tmp;
    s_list_t *fast = head;
    s_list_t *slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        if (fast != NULL) {
            slow = slow->next;
        }
    }
    tmp = slow->next;
    slow->next = NULL;
    return tmp;
}

int sort(void *data, char **args)
{
    s_list_t **list = (s_list_t **)data;
    int a = 0;

    if (args[0] == NULL)
        return 84;
    for (a = 0; args[a] != NULL; a++) {
        if (my_strcmp(args[a], "TYPE") == 0)
            *list = mergesort_type(*list);
        if (my_strcmp(args[a], "ID") == 0)
            *list = mergesort_id(*list);
        if (my_strcmp(args[a], "NAME") == 0)
            *list = mergesort_name(*list);
    }
    return 0;
}
