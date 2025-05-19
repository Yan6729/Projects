/*
** EPITECH PROJECT, 2024
** sort.c
** File description:
** sort.c
*/

#include "../include/stumper.h"

occur_t *split(occur_t *head)
{
    occur_t *tmp;
    occur_t *fast = head;
    occur_t *slow = head;

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
