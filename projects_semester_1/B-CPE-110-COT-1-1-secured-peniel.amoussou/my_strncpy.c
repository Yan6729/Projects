/*
** EPITECH PROJECT, 2024
** my_strncpy
** File description:
** my_strncpy
*/

#include "hashtable.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    dest[n + 1] = '\0';
    return dest;
}
