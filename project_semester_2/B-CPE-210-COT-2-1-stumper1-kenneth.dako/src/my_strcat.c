/*
** EPITECH PROJECT, 2025
** A function
** File description:
** A fucntion
*/

#include "../include/tail.h"

char *my_strcat(char *dest, const char *src)
{
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest;
}
