/*
** EPITECH PROJECT, 2024
** organized
** File description:
** storing and sorting
*/

#include <stdlib.h>
#include "my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}
