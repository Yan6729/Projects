/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** Implementing my_printf function
*/

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "my.h"

int condition1p(const char *format, va_list list, int x)
{
    if (format[x] == '%' && format[x + 1] == 'i'
        || format[x + 1] == 'd') {
        my_put_nbr(va_arg(list, int));
    }
    if (format[x] == '%' && format[x + 1] == 'c') {
        my_putchar(va_arg(list, int));
    }
    if (format[x] == '%' && format[x + 1] == 's') {
        my_putstr(va_arg(list, char *));
    }
    if (format[x] == '%' && format[x + 1] == '%') {
        my_putchar('%');
    }
    if (format[x] == '%' && format[x + 1] == '.'
        && (format[x + 2] >= '0' && format[x + 2] <= '6')
        && format[x + 3] == 'f') {
        my_putfloat2(va_arg(list, double), (format[x + 2] - 48));
        x = x + 3;
    }
    return x;
}

int condition2p(const char *format, va_list list, int x)
{
    if (format[x] == '%' && format[x + 1] == 'b') {
        my_convert_min(va_arg(list, unsigned int), 2);
    }
    if (format[x] == '%' && format[x + 1] == 'o') {
        my_convert_min(va_arg(list, unsigned int), 8);
    }
    if (format[x] == '%' && format[x + 1] == 'u') {
        my_put_nbr(va_arg(list, unsigned int));
    }
    if (format[x] == '%' && format[x + 1] == 'x') {
        my_convert_min(va_arg(list, unsigned int), 16);
    }
    if (format[x] == '%' && format[x + 1] == 'X') {
        my_convert_maj(va_arg(list, unsigned int), 16);
    }
    if (format[x] == '%' && format[x + 1] == 'S') {
        my_putstr(va_arg(list, char *));
    }
    return x;
}

int condition3p(const char *format, va_list list, int x)
{
    if (format[x] == '%' && format[x + 1] == 'g') {
        my_putfloat(va_arg(list, double));
    }
    if (format[x] == '%' && format[x + 1] == 'G') {
        my_putfloat(va_arg(list, double));
    }
    if (format[x] == '%' && format[x + 1] == 'f') {
        my_putfloat(va_arg(list, double));
    }
    if (format[x] == '%' && format[x + 1] == 'F') {
        my_putfloat(va_arg(list, double));
    }
    if (format[x] == '%' && format[x + 1] == 'p') {
        my_putstr("0x");
        my_convert_min2(((unsigned long)(va_arg(list, unsigned long *))), 16);
    }
    if (format[x] == '%' && format[x + 1] == 'k') {
        my_putstr("%k");
    }
    return x;
}

int my_printf(const char *format, ...)
{
    int x = 0;
    va_list list;

    va_start(list, format);
    for (x = 0; format[x] != '\0'; x++) {
        if (format[x] != '%') {
            my_putchar(format[x]);
        }
        if (format[x] == '%') {
            condition1p(format, list, x);
            condition2p(format, list, x);
            condition3p(format, list, x);
            x = formatage1(format, list, x);
            x = formatage2(format, list, x);
            x++;
        }
    }
    va_end(list);
}
