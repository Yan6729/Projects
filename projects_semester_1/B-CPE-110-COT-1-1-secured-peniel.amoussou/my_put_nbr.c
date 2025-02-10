/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "hashtable.h"

int my_put_nbr(int nb)
{
    if (nb > 2147483647)
    return 0;
    if (nb < -2147483647) {
    limit_breaker();
    return 0;
    }
    if (nb >= 0 && nb < 10) {
    my_putchar(nb + 48);
    } else if (nb < 0) {
    my_putchar('-');
    my_put_nbr(nb * -1);
    } else {
    my_put_nbr(nb / 10);
    my_put_nbr(nb % 10);
    }
}
