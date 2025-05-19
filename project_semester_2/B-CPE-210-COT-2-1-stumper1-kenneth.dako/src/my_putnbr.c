/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** To print numbers
*/

#include "../include/tail.h"

int my_putnbr(int nb)
{
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return 0;
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + '0');
    }
    if (nb > 9) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
        my_putnbr(nb);
    }
    return 0;
}
