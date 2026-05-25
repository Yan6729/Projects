/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** my_putstr
*/

#include "hashtable.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}
