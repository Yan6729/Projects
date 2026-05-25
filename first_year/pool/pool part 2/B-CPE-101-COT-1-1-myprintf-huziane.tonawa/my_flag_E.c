/*
** EPITECH PROJECT, 2024
** my_flag_E.c
** File description:
** the flag E
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

double mynew_putfloat(float nb)
{
    int a = 0;
    double b = 0;

    a = nb;
    if (nb >= 0) {
        my_put_nbr(nb);
        my_putchar('.');
        b = (nb - a) * 1000000 + 0.5;
        my_put_nbr(b);
    }
    if (nb < 0) {
        my_putchar('-');
        mynew_putfloat(nb * (-1));
    }
}

void my_flag_firstcondition(float nb)
{
    if (nb <= 1 && nb >= 9) {
        mynew_putfloat(nb);
        my_putstr("E+");
        my_put_nbr(0);
        my_put_nbr(0);
    }
}

void my_flag_secondcondition(int a, int b, float nb, double stock)
{
    for (a = 0; nb >= 10; a++) {
        nb = nb / 10;
        stock = nb;
    }
    mynew_putfloat(stock);
    my_putstr("E+");
    my_put_nbr(0);
    my_put_nbr(a);
}

void my_flag_thirdcondition(int a, int b, float nb, double stock)
{
    for (a = 0; nb > 0 && nb <= 1; a++) {
        nb = nb * 10;
        stock = nb;
        for (b = 0; b < a; b++) {
            stock = stock * 10;
        }
        mynew_putfloat(stock);
        my_putstr("E-");
        my_put_nbr(0);
        my_put_nbr(a);
    }
}

float my_flag_emaj(float nb)
{
    int a = 0;
    int b = 0;
    double stock = 0;

    if (nb > 0) {
        my_flag_firstcondition(nb);
        if (nb > 10) {
            my_flag_secondcondition(a, b, nb, stock);
        }
        if (nb > 0 && nb <= 1) {
            my_flag_thirdcondition(a, b, nb, stock);
        }
        if (nb < 0) {
            my_putchar('-');
            my_flag_emaj(nb * (-1));
        }
    }
}
