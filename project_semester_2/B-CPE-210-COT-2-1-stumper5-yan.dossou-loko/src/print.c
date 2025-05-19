/*
** EPITECH PROJECT, 2024
** mini_putsf.c
** File description:
** mini_putsf.c
*/

#include "../include/stumper.h"

void my_putchar(char c, int fd)
{
    write(fd, &c, 1);
}

void my_puts(char *str, int fd)
{
    for (int a = 0; str[a] != '\0'; a++)
        my_putchar(str[a], fd);
}

int my_put_nbr(int nbr, int fd)
{
    if (nbr >= 0 && nbr < 10) {
        my_putchar(nbr + '0', fd);
    } else if (nbr < 0) {
        my_putchar('-', fd);
        my_put_nbr(nbr * (-1), fd);
    } else {
        my_put_nbr(nbr / 10, fd);
        my_put_nbr(nbr % 10, fd);
    }
}

int condition(va_list n, const char *format, int a, int fd)
{
    if (format[a + 1] == 'c')
        my_putchar(va_arg(n, int), fd);
    if (format[a + 1] == 's')
        my_puts(va_arg(n, char *), fd);
    if (format[a + 1] == '%')
        my_putchar('%', fd);
    else if (format[a + 1] == 'i' || format[a + 1] == 'd')
        my_put_nbr(va_arg(n, int), fd);
}

int print(char *std, const char *format, ...)
{
    va_list n;
    int a = 0;
    int fd = 0;

    if (strcmp(std, "stderr") == 0)
        fd = 2;
    else if (strcmp(std, "stdout") == 0)
        fd = 1;
    else
        return 1;
    va_start(n, format);
    for (a = 0; format[a] != '\0'; a++) {
        if (format[a] == '%') {
            condition(n, format, a, fd);
            a++;
        } else {
            my_putchar(format[a], fd);
        }
    }
    va_end(n);
}
