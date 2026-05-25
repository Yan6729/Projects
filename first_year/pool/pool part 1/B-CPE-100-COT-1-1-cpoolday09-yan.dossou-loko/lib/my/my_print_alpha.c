/*
** EPITECH PROJECT, 2024
** my_print_alpha.c
** File description:
** my_print_alpha.c
*/
#include "my_putchar.c"
#include <stdio.h>

int my_print_alpha(void)
{
    char alpha = 'a';

    for (alpha = 'a'; alpha <= 'z'; alpha++) {
        my_putchar(alpha);
    }
    return 0;
}
int main(void)
{
    my_print_alpha;
}
