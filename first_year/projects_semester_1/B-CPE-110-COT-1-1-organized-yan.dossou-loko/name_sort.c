/*
** EPITECH PROJECT, 2024
** name_sort.c
** File description:
** an intermediare function
*/

#include "shell.h"
#include <stdlib.h>

s_list_t *merge_3(s_list_t *first, s_list_t *second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;
    if (my_strcmp(first->NAME, second->NAME) < 0) {
        first->next = merge_3(first->next, second);
        return first;
    } else {
        second->next = merge_3(first, second->next);
        return second;
    }
}

s_list_t *mergesort_name(s_list_t *head)
{
    int a;
    char **args;
    s_list_t *second;
    s_list_t *retour;

    if (head == NULL || head->next == NULL) {
        return head;
    }
    second = split(head);
    head = mergesort_name(head);
    second = mergesort_name(second);
    return merge_3(head, second);
}
