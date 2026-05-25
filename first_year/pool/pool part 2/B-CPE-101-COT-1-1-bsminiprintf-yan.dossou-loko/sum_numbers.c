/*
** EPITECH PROJECT, 2024
** sum_numbers.c
** File description:
** The sum_numbers() function returns the sum of the numbers passed as parameters after n.
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
int my_putchar(char c)
{
    write(1, &c, 1);
}

int sum_numbers(int numb, ...)
{
    va_list n;
    int a;
    int b = 0;

    va_start(n, numb);
    for (a = 1; a <= numb; a++) {
	b = b + va_arg(n, int);
    }
    va_end(n);
    return b;
}

int main()
{
    int c = 5;
    int d = 8;
    int de = 10;
    int be = 22;
    int b =  sum_numbers(4, c, d, de, be);
    printf("%d\n", b);(
}
    
