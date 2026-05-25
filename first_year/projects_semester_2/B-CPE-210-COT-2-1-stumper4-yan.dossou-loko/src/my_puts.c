/*
** EPITECH PROJECT, 2025
** double ffuntion
** File description:
** intermediar file
*/

//#include "../../include/my.h"
#include <unistd.h>

void my_putchar(char c, int fd)
{
    write(fd, &c, 1);
}

void my_puts(char *str, int fd)
{
    for (int a = 0; str[a] != '\0'; a++)
        my_putchar(str[a], fd);
}
