/*
** EPITECH PROJECT, 2025
** my_getenv.c
** File description:
** just a file
*/

#include "../../include/shell.h"

left_t *add_2(left_t **head, char *line)
{
    left_t *last = *head;
    left_t *newNode = malloc(sizeof(left_t));

    if (!line)
        return NULL;
    newNode->line = my_strdup(line, 0);
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
    return newNode;
}

void display_2(left_t *head)
{
    left_t *tmp = head;

    for (tmp; tmp != NULL; tmp = tmp->next) {
        print("stdout", "%s\n", tmp->line);
    }
}
