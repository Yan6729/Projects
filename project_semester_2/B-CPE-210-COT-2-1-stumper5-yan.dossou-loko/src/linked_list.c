/*
** EPITECH PROJECT, 2025
** linked_list
** File description:
** create list
*/

#include "../include/stumper.h"

int add(occur_t **data, int occ, char car)
{
    occur_t *node = malloc(sizeof(node));
    occur_t *tmp = *data;

    if (node == NULL)
        return 84;
    node->occ = occ;
    node->car = car;
    node->next = NULL;
    if (*data == NULL)
        *data = node;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = node;
    }
}

int verif_car(occur_t *data, char car)
{
    occur_t *tmp = data;

    while (tmp != NULL) {
        if (tmp->car == car) {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int add_in(occur_t **data, int oc, char c)
{
    if (verif_car(*data, c) == 0)
        add(data, oc, c);
    return 0;
}

void print_list(occur_t **data)
{
    occur_t *tmp = *data;

    for (tmp; tmp != NULL; tmp = tmp->next) {
        print("stdout", "%c:%d\n", tmp->car, tmp->occ);
    }
}
