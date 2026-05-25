/*
** EPITECH PROJECT, 2024
** my_convert_min.c
** File description:
** the goal of this fonction is to convert a number in a other base
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "my.h"
int my_convert_min(unsigned int nb, int base)
{
    int res;

    if (nb != 0) {
        my_convert_min(nb / base, base);
        res = nb % base;
        if ((res >= 0) && (res <= 9)) {
            my_put_nbr(res);
        } else {
            res = res + 87;
            my_putchar(res);
        }
    }
}
