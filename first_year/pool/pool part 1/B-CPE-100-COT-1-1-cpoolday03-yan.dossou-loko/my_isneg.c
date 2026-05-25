/*
** EPITECH PROJECT, 2024
** my_isneg.c
** File description:
** my_isneg.c
*/

#include <stdio.h>
int my_isneg(int vawulence)
{
    if (vawulence < '0') {
        my_putchar('N');
    }
    return 0;
    if (vawulence >= '0') {
        my_putchar('P');
    }
    return 0;
}
