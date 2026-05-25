/*
** EPITECH PROJECT, 2024
** my_isneg.c
** File description:
** my_isneg.c
*/
#include "../../include/my.h"
#include <stdio.h>
int my_isneg(int vawulence)
{
    if (vawulence < '0') {
        return ('N');
    }
    return 0;
    if (vawulence >= '0') {
        return ('P');
    }
    return 0;
}
