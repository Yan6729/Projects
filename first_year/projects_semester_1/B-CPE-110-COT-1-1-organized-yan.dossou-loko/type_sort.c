/*
** EPITECH PROJECT, 2024
** type_sort.h
** File description:
** an intermediair function
*/

#include <stdlib.h>
#include "shell.h"

s_list_t *merge_1(s_list_t *first, s_list_t *second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;
    if (first->TYPE[0] < second->TYPE[0]) {
        first->next = merge_1(first->next, second);
        return first;
    } else {
        second->next = merge_1(first, second->next);
        return second;
    }
}

s_list_t *mergesort_type(s_list_t *head)
{
    s_list_t *second;

    if (head == NULL || head->next == NULL) {
        return head;
    }
    second = split(head);
    head = mergesort_type(head);
    second = mergesort_type(second);
    return merge_1(head, second);
}
