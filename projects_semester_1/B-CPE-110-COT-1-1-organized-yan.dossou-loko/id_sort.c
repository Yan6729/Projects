/*
** EPITECH PROJECT, 2024
** id_sort.c
** File description:
** an intermediar function
*/
#include <stdlib.h>
#include "shell.h"

s_list_t *merge_2(s_list_t *first, s_list_t *second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;
    if (first->ID < second->ID) {
        first->next = merge_2(first->next, second);
        return first;
    } else {
        second->next = merge_2(first, second->next);
        return second;
    }
}

s_list_t *mergesort_id(s_list_t *head)
{
    int a;
    char **args;
    s_list_t *second;
    s_list_t *retour;

    if (head == NULL || head->next == NULL) {
        return head;
    }
    second = split(head);
    head = mergesort_id(head);
    second = mergesort_id(second);
    return merge_2(head, second);
}
