/*
** EPITECH PROJECT, 2024
** my_compute_factorial_it.c
** File description:
** my_compute_factorial_it.c
*/

#include <stdio.h>
#include <unistd.h>
int my_compute_factorial_it(int nb)
{
    int facto = 1;
    int a = 1;

    if (nb < 0 || nb > 12) {
        return (0);
    }
    if (nb == 0 || nb == 1) {
        return (1);
    }
    while (a <= nb) {
        facto = facto * a;
        a++;
    }
    return (facto);
}
