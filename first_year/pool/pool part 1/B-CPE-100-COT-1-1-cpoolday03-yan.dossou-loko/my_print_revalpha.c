/*
** EPITECH PROJECT, 2024
** my_print_revalpha.c
** File description:
** my_print_revalpha.c
*/

#include <stdio.h>

int my_print_revalpha(void)
{
    int revalpha;

    for (revalpha = 'z'; revalpha >= 'a'; revalpha--) {
        my_putchar(revalpha);
    }
    return 0;
}
