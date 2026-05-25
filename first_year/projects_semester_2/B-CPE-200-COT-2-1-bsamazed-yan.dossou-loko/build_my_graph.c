/*
** EPITECH PROJECT, 2025
** build_my_graph.c
** File description:
** just a file
*/

#include "graph.h"

link_t *build_my_graph(void)
{
    link_t *link1 = create_link(42);
    link_t *link2 = create_link(48);
    link_t *link3 = create_link(50012);
    link_t *link4 = create_link(3);
    link_t *link5 = create_link(98);
    link_t *link6 = create_link(8);
    link_t *link7 = create_link(60012);
    link_t *link8 = create_link(30012);

    connect_links(link7, link8);
    connect_links(link1, link7);
    connect_links(link1, link2);
    connect_links(link1, link3);
    connect_links(link1, link5);
    connect_links(link1, link4);
    connect_links(link1, link6);
    return link1;
}
