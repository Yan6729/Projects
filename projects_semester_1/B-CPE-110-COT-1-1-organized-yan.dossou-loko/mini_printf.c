/*
** EPITECH PROJECT, 2024
** mini_printf.c
** File description:
** mini_printf.c
*/
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nbr)
{
    if (nbr >= 0 && nbr < 10) {
        my_putchar(nbr + '0');
    } else if (nbr < 0) {
        my_putchar('-');
        my_put_nbr(nbr * (-1));
    } else {
        my_put_nbr(nbr / 10);
        my_put_nbr(nbr % 10);
    }
}

int my_putstr(char const *str)
{
    int a;

    for (a = 0; str[a] != '\0'; a++) {
        my_putchar(str[a]);
    }
    return 0;
}

int condition(va_list n, const char *format, int a)
{
    if (format[a + 1] == 'c')
        my_putchar(va_arg(n, int));
    if (format[a + 1] == 's')
        my_putstr(va_arg(n, char *));
    if (format[a + 1] == '%')
        my_putchar('%');
    else if (format[a + 1] == 'i' || format[a + 1] == 'd')
        my_put_nbr(va_arg(n, int));
}

int mini_printf(const char *format, ...)
{
    va_list n;
    int a = 0;

    va_start(n, format);
    for (a = 0; format[a] != '\0'; a++) {
        if (format[a] == '%') {
            condition(n, format, a);
            a++;
        } else {
            my_putchar(format[a]);
        }
    }
    va_end(n);
}
