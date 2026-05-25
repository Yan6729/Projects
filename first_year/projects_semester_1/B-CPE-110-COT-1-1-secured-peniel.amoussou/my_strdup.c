/*
** EPITECH PROJECT, 2024
** strdup
** File description:
** this is a project file
*/

#include "hashtable.h"

char *my_strdup(char const *src)
{
    char *b = malloc(sizeof(char) * my_strlen(src));

    my_strncpy(b, src, my_strlen(src));
    return b;
}
