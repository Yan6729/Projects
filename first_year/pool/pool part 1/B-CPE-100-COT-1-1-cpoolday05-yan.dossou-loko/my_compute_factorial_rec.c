/*
** EPITECH PROJECT, 2024
** my_compute_factorial_rec.c
** File description:
** my_compute_factorial_rec.c
*/

#include <stdio.h>
#include <unistd.h>

int my_compute_factorial_rec(int nb)
{
    int facto;

    if (nb < 0 || nb > 12) {
        return (0);
    } else if (nb == 0 || nb == 1) {
        return (1);
    }
    if (nb > 0) {
        facto = nb * my_compute_factorial_rec(nb - 1);
        return (facto);
    }
}
