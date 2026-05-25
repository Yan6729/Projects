/*
** EPITECH PROJECT, 2025
** free_dictionary.c
** File description:
** just a file
*/

#include "../include/stumper.h"

void free_dictionary(dict_t *dict)
{
    for (int i = 0; i < dict->count; i++)
        free(dict->word[i]);
    free(dict->word);
    dict->word = NULL;
    dict->count = 0;
}
