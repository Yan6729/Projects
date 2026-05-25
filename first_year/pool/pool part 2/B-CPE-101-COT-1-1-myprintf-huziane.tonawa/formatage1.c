/*
** EPITECH PROJECT, 2024
** formatage#.c
** File description:
** formatage with #
*/
#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
int part1(const char *format, va_list list, int x)
{
    if (format[x + 2] == 'x') {
        my_putstr("0x");
        my_convert_min(va_arg(list, unsigned int), 16);
    }
    if (format[x + 2] == 'X') {
        my_putstr("0X");
        my_convert_maj(va_arg(list, unsigned int), 16);
    }
    if (format[x + 2] == 'o') {
        my_putstr("0");
        my_convert_maj(va_arg(list, unsigned int), 8);
    }
    if (format[x + 2] == 'u') {
        my_convert_maj(va_arg(list, unsigned int), 10);
    }
    if (format[x + 2] == 'b') {
        my_putstr("0b");
        my_convert_maj(va_arg(list, unsigned int), 2);
    }
}

int formatage1(const char *format, va_list list, int x)
{
    if (format[x] == '%' && format[x + 1] == '#') {
        part1(format, list, x);
        x++;
    }
    return x;
}
