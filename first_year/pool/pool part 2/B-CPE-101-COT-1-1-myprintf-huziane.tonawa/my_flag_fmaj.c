/*
** EPITECH PROJECT, 2024
** my flag F
** File description:
** my flag F
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

float my_flag_fmaj(float nb)
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
    my_flag_fmaj(nb * (-1));
    }
}/*
void not_a_number_condition()

{
    double my_int = 0;
    double my_nan = 0;

    if ()
}
*/
