/*
** EPITECH PROJECT, 2024
** my_compute_square_root.c
** File description:
** my_compute_square_root.c
*/
#include <stdio.h>
int my_compute_square_root(int nb)
{
    int compt;
    int r;

    if (nb <= 0) {
        return 0;
    }
    for (compt = 1; compt <= nb; compt++) {
        if (compt * compt == nb)
            return compt;
        if (compt == nb)
            return 0;
    }
}
