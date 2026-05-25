/*
** EPITECH PROJECT, 2024
** my_convert_maj.c
** File description:
** the goal of this fonction is to do convert a number in a base.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "my.h"
int my_convert_maj(unsigned int nb, int base)
{
    int res;

    if (nb != 0) {
        my_convert_maj(nb / base, base);
        res = nb % base;
        if ((res >= 0) && (res <= 9)) {
            my_put_nbr(res);
        } else {
            res = res + 55;
            my_putchar(res);
        }
    }
}
