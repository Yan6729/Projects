/*
** EPITECH PROJECT, 2025
** graph.h
** File description:
** just a file
*/

#ifndef GRAPH_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #define GRAPH_H

typedef struct link {
    int data;
    struct link *next;
} link_t;

link_t *create_link(int data);
void print_link(link_t *link);
link_t *connect_links(link_t *link1, link_t *link2);
void print_data_of_connected_links(link_t *link);
link_t *build_my_graph(void);
void print_my_graph_data(link_t *graph);
#endif
