/*
** EPITECH PROJECT, 2024
** my_print_alpha.c
** File description:
** my_print_alpha.c
*/

#include <stdio.h>

int my_print_alpha(void)
{
    char alpha;

    for (alpha = 'a'; alpha <= 'z'; alpha++) {
        my_putchar(alpha);
    }
    return 0;
}
