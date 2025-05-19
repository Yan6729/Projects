/*
** EPITECH PROJECT, 2025
** double ffuntion
** File description:
** intermediar file
*/

#include "../../include/robot.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_puts(char *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        my_putchar(str[a]);
}

void my_putchar_2(char c)
{
    write(2, &c, 1);
}

void my_puts_2(char *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        my_putchar(str[a]);
}
