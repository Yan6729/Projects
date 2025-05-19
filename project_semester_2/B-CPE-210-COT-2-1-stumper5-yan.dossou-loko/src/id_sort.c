/*
** EPITECH PROJECT, 2024
** id_sort.c
** File description:
** an intermediar function
*/

#include "../include/stumper.h"

occur_t *merge_2(occur_t *first, occur_t *second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;
    if (first->occ > second->occ) {
        first->next = merge_2(first->next, second);
        return first;
    } else {
        second->next = merge_2(first, second->next);
        return second;
    }
}

occur_t *mergesort_id(occur_t **head)
{
    int a;
    char **args;
    occur_t *second;
    occur_t *retour;

    if (head == NULL || (*head)->next == NULL) {
        return *head;
    }
    second = split(*head);
    *head = mergesort_id(head);
    second = mergesort_id(&second);
    return merge_2(*head, second);
}
