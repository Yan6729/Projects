/*
** EPITECH PROJECT, 2024
** my_convert_min2.c
** File description:
** this fonction can help the p flags to work.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "my.h"
int my_convert_min2(unsigned long nb, int base)
{
    int res;

    if (nb != 0) {
        my_convert_min2(nb / base, base);
        res = nb % base;
        if ((res >= 0) && (res <= 9)) {
            my_put_nbr(res);
        } else {
            res = res + 87;
            my_putchar(res);
        }
    }
}
