/*
** EPITECH PROJECT, 2024
** my_print_comb.c
** File description:
** my_print_comb.c
*/

#include <stdio.h>
#include <unistd.h>

int my_print_comb(int a, int b, int c)
{
    for (a = '0'; a <= '7'; a++, && b = '1'; b <= '8'; b++, && c = '2'; c <= '9'; c++) {
                if (b > a, c > b) {
                        my_putchar(a);
                        my_putchar(b);
                        my_putchar(c);
                        my_putchar(',');
                }
    }
    return 0;
}
