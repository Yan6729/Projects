/*
** EPITECH PROJECT, 2024
** my_putchar.c
** File description:
** function that write characters.
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
