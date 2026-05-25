/*
** EPITECH PROJECT, 2024
** my_compute_power_it.c
** File description:
** my_compute_power_it.c
*/

#include <stdio.h>
#include <unistd.h>

int my_compute_power_rec(int nb, int p)
{
    int carré;

    if (p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    while (p > 0) {
        carré = nb * my_compute_power_rec(nb, p -1);
    }
    return (carré);
}
