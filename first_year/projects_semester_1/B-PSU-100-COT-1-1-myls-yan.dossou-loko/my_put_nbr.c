/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/
#include "my.h"

int my_put_nbr(int nbr)
{
    if (nbr < -2147483647) {
        my_putstr("-2147483648");
        return 0;
    }
    if (nbr > 2147483647) {
        return 0;
    }
    if (nbr >= 0 && nbr < 10) {
        my_putchar(nbr + '0');
    }
    if (nbr < 0) {
        my_putchar('-');
        my_put_nbr(nbr * (-1));
    }
    if (nbr >= 10) {
        my_put_nbr(nbr / 10);
        my_put_nbr(nbr % 10);
    }
}
