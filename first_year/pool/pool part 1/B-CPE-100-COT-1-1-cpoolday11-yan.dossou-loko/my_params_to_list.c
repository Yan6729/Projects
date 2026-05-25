/*
** EPITECH PROJECT, 2024
** my_params_to_list.c
** File description:
** my_params_to_list.c
*/
#include "include/mylist.h"
#include "intlude/my.h"
#include <stdio.h>
#include <stdlib.h>

int my_put_in_list(linked_list_t **list, char *data)
{
    linked_list_t *element;
    
    element = malloc(sizeof(*element));
    element->data = data;
    element->next = *list;
    *list = element;
    return 0;
}
linked_list_t *my_params_to_list(int ac, char *const *av)
{
    int a;
    linked_list_t *list;

    for(a = 0; a != NULL; a++) {
	my_put_in_list(
