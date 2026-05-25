/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/

#include "mytop.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nbr)
{
    if (nbr > 2147483647) {
        return 0;
    }
    if (nbr >= 0 && nbr < 10) {
        my_putchar(nbr + '0');
    }
    if (nbr >= 10) {
        my_put_nbr(nbr / 10);
        my_put_nbr(nbr % 10);
    }
}
