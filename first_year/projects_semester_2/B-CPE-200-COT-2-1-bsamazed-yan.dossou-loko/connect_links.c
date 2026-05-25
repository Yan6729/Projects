/*
** EPITECH PROJECT, 2025
** connect_links.c
** File description:
** just a file
*/

#include "graph.h"

link_t *connect_links(link_t *link1, link_t *link2)
{
    if (!(link1) || !(link2))
        return NULL;
    if (link1->next == NULL)
        link1->next = link2;
    if (link1->next->next == NULL)
        link1->next->next = link2;
    if (link1->next->next->next == NULL)
        link1->next->next->next = link2;
    if (link1->next->next->next->next == NULL)
        link1->next->next->next->next = link2;
    if (link1->next->next->next->next->next == NULL)
        link1->next->next->next->next->next = link2;
    if (link1->next->next->next->next->next->next == NULL)
        link1->next->next->next->next->next->next = link2;
    link1->next->next->next->next->next->next->next = link2;
    return link1;
}

int main(int ac, char **av)
{
    
}
