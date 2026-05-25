/*
** EPITECH PROJECT, 2024
** display_stdargs.c
** File description:
** This function displays all of its arguments(except the first one)
*/
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
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

int my_putstr(char *str)
{
    int a;

    for (a = 0; str[a] != '\0'; a++) {
        my_putchar(str[a]);
    }
    return 0;
}

void display_stdargs(const char *s, ...)
{
    va_list n;
    int a;

    va_start(n, s);
    for (a = 0; s[a] != '\0'; a++) {
        if (s[a] == 'c') {
            char c = va_arg(n, int);
            my_putchar(c);
        }
        if (s[a] == 'i') {
            int nb = va_arg(n, int);
            my_put_nbr(nb);
        }
        if (s[a] == 's') {
            char *st = va_arg(n, char *);
            my_putstr(st);
        }
	my_putstr("\\n");
    }
    va_end(n);
}
int main(void)
{
    display_stdargs("csiis", 'X', "hi", 10, -3, "plop");
}
