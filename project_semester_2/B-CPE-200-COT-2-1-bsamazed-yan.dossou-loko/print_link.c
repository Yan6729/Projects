/*
** EPITECH PROJECT, 2025
** print_link.c
** File description:
** just a file
*/

#include "graph.h"

void print_link(link_t *link)
{
    link_t *tmp = NULL;

    for (tmp = link; tmp != NULL; tmp = tmp->next) {
        printf("%d\n", tmp->data);
    }
}
