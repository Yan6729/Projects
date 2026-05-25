/*
** EPITECH PROJECT, 2024
** my_putfloat.c
** File description:
** my_putfloat.c
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

double my_putfloat(double nb)
{
    int a = 0;
    double b = 0;
    int x = 0;
    int stock = 0;
    int i = 0;

    a = nb;
    if (nb >= 0) {
    my_put_nbr(nb);
    my_putchar('.');
    b = (nb - a) * 1000000 + 0.5;
    if (b == 0) {
        my_putstr("000000");
    } else {
        stock = b;
        my_first_float_condition(x, i, stock);
        my_put_nbr(b);
    }
    }
    my_second_float_condition(nb);
}

double my_first_float_condition(int x, int i, int stock)
{
    for (x = 0; stock < 100000; x++) {
        stock = stock * 10;
        }
        for (int i = 0; i < x; i++) {
            my_putchar('0');
        }
}

double my_second_float_condition(double nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_putfloat(nb * (-1));
    }
}
