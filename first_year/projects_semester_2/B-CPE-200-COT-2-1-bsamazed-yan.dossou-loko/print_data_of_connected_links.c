/*
** EPITECH PROJECT, 2025
** print_data_of_connected_links.c
** File description:
** just a file
*/

#include "graph.h"

void print_data_of_connected_links(link_t *link)
{
    link_t *tmp = link;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->next != NULL)
            printf("%d -> %d\n", tmp->data, tmp->next->data);
        else
            printf("%d -> NULL\n", tmp->data);
    }
    return;
}
