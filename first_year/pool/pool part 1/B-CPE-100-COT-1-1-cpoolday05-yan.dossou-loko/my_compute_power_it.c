/*
** EPITECH PROJECT, 2024
** my_compute_power_it.c
** File description:
** my_compute_power_it.c
*/

#include <stdio.h>
#include <unistd.h>

int my_compute_power_it(int nb, int p)
{
    int carré = 1;
    
    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    while (p > 0) {
        carré = carré * nb;
        p--;
    }
    return (carré);
}
