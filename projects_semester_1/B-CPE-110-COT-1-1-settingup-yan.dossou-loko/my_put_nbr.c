/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/
#include "my.h"
#include <unistd.h>
#include <stdio.h>

int my_put_nbr(int nbr)
{
    if (nbr >= 0 && nbr < 10) {
        my_putchar(nbr + '0');
    } else if (nbr < 0) {
        my_putchar('-');
        my_put_nbr(nbr * (-1));
    } else {
        my_put_nbr(nbr / 10);
        my_put_nbr(nbr % 10);
    }
}
