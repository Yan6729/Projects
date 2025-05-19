/*
** EPITECH PROJECT, 2025
** create_link.c
** File description:
** just a file
*/

#include "graph.h"

link_t *create_link(int data)
{
    link_t *list = NULL;
    link_t *num = malloc(sizeof(link_t));

    num->data = data;
    num->next = list;
    list = num;
    return num;
}
