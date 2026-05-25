/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** this is a project file
*/

#include "hashtable.h"

int my_strlen(char const *str)
{
    int i;
    int count = 0;

    for (i = 0; str[i] != '\0'; i++) {
        count++;
    }
    return count;
}
