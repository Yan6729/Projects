/*
** EPITECH PROJECT, 2025
** double ffuntion
** File description:
** intermediar file
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_puts(char *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        my_putchar(str[a]);
}
