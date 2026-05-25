/*
** EPITECH PROJECT, 2024
** my_is_prime.c
** File description:
** my_is_prime.c
*/
#include <stdio.h>
#include <unistd.h>

int my_is_prime(int nb)
{
    int a;

    if (nb < 2)
        return 0;
    for (a = 2; a * a <= nb; a++) {
        if (nb % a == 0)
            return (0);
    }
    return (1);
}
