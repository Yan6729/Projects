/*
** EPITECH PROJECT, 2024
** my_print_digits.c
** File description:
** my_print_digits.c
*/

#include <stdio.h>

int my_print_digits(void)
{
    char digits;

    for (digits = '0'; digits <= '9'; digits++) {
        my_putchar(digits);
    }
    return 0;
}
