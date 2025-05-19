/*
** EPITECH PROJECT, 2025
** A function
** File description:
** A function
*/

#include "../include/tail.h"

int my_strncmp(const char *str1, const char *str2, size_t n)
{
    while (n > 0 && *str1 && (*str1 == *str2)) {
        str1++;
        str2++;
        n--;
    }
    if (n == 0)
        return 0;
    return (unsigned char)(*str1) - (unsigned char)(*str2);
}
