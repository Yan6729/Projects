/*
** EPITECH PROJECT, 2025
** print_my_graph_data.c
** File description:
** just a file
*/

#include "graph.h"

void print_my_graph_data(link_t *graph)
{
    link_t *tmp = graph;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->next != NULL)
            printf("%d -> %d\n", tmp->data, tmp->next->data);
        else
            printf("%d -> NULL\n", tmp->data);
    }
    return;
}
