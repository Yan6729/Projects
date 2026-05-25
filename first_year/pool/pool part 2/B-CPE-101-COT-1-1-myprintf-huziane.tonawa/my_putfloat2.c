/*
** EPITECH PROJECT, 2024
** My_putfloat2
** File description:
** My_putfloat2
*/

#include <unistd.h>
#include "my.h"
double my_putfloat2(float nb, int s)
{
    int a = nb;
    double b = nb - a;
    int stock = 10;
    int x;

    if (s > 0) {
        my_put_nbr(nb);
        my_putchar('.');
        while (x < s) {
            b = b * stock;
            x++;
        }
        my_put_nbr(b);
    }
}
