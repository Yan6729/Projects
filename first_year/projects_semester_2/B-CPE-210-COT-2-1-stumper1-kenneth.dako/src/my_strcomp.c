/*
** EPITECH PROJECT, 2025
** A function
** File description:
** A function
*/

#include "../include/tail.h"

int my_strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return (unsigned char)(*str1) - (unsigned char)(*str2);
}
