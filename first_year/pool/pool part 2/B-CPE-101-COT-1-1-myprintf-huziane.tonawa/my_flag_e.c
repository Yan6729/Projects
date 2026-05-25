/*
** EPITECH PROJECT, 2024
** my_flag_e
** File description:
** my_flag_e
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

void my_printf_condition1(float nb)
{
    if (nb <= 1 && nb >= 9) {
        my_putfloat(nb);
        my_putstr("e+");
        my_put_nbr(0);
        my_put_nbr(0);
    }
}

void my_printf_condition2(int a, int b, float nb, double stock)
{
    for (a = 0; nb >= 10; a++) {
        nb = nb / 10;
        stock = nb;
    }
    my_putfloat(stock);
    my_putstr("e+");
    my_put_nbr(0);
    my_put_nbr(a);
}

void my_printf_condition3(int a, int b, float nb, double stock)
{
    for (a = 0; nb > 0 && nb <= 1; a++) {
        nb = nb * 10;
        stock = nb;
        for (b = 0; b < a; b++) {
            stock = stock * 10;
        }
        my_putfloat(stock);
        my_putstr("e-");
        my_put_nbr(0);
        my_put_nbr(a);
    }
}

float my_flag_e(float nb)
{
    int a = 0;
    int b = 0;
    double stock = 0;

    if (nb > 0) {
        my_printf_condition1(nb);
        if (nb > 10) {
            my_printf_condition2(a, b, nb, stock);
        }
        if (nb > 0 && nb <= 1) {
            my_printf_condition3(a, b, nb, stock);
        }
        if (nb < 0) {
            my_putchar('-');
            my_flag_e(nb * (-1));
        }
    }
}
