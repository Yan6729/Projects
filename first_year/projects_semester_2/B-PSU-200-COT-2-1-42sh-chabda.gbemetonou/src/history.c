/*
** EPITECH PROJECT, 2025
** history.c
** File description:
** just a file
*/

#include "../include/shell.h"

void add_h(history_t **list, char *line, int num)
{
    history_t *last = *list;
    history_t *newNode = malloc(sizeof(history_t));

    newNode->cmp = malloc(sizeof(val_t));
    if (!line)
        return;
    newNode->cmp->command = my_strdup(line, 0);
    newNode->cmp->num = num;
    newNode->next = NULL;
    if (*list == NULL) {
        *list = newNode;
    } else {
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

history_t *find_var_h(history_t *list, char *line)
{
    while (list) {
        if (strcmp(list->cmp->command, line) == 0)
            return list;
        list = list->next;
    }
    return NULL;
}

history_t *verify_h(history_t *list, char *line, int num)
{
    history_t *var = find_var_h(list, line);

    if (line == NULL)
        return NULL;
    if (line)
        add_h(&list, line, num);
}

void disp_h(history_t **hist)
{
    history_t *list;

    for (list = *hist; list != NULL; list = list->next) {
        print("stdout", "%d %s\n", list->cmp->num, list->cmp->command);
        if (list->next != NULL && list->next->next == NULL)
            break;
    }
}

void free_hl(history_t *cmp)
{
    history_t *current = cmp;
    history_t *next = NULL;

    if (cmp == NULL)
        return;
    for (current; current != NULL; current = next) {
        next = current->next;
        if (current->cmp->command != NULL) {
            free(current->cmp->command);
            current->cmp->command = NULL;
        }
        free(current->cmp);
        free(current);
    }
}
