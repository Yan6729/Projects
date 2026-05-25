/*
** EPITECH PROJECT, 2024
** sum_string_length.c
** File description:
** The sum_strings_length() function returns the sum of the lengths of every string passed as parameter after n.
*/

#include <stdio.h>
#include <stdarg.h>

int my_strlen(char *str)
{
    int b;
    for (b = 0; str[b] != 0; b++);
    return b;
}
int sum_string_length(int n, ...)
{
    int a;
    char *str;
    int c = 0;
    va_list nb;

    va_start(nb, n);
    for (a = 1; a <= n; a++) {
	c = c + my_strlen(va_arg(nb, char *));
    }
    va_end(nb);
    return c;
}

int main()
{
    int a = sum_string_length(2, "Bonjour", "la Maman de Modeste");
    printf("%d", a);
}
