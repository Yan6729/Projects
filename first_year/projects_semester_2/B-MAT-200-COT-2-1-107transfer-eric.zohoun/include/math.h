/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#ifndef MATH_H
    #include <math.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdio.h>
    #define MATH_H

typedef struct index_s {
    int k;
    int i;
    int j;
    int lig;
}index_t;

char **my_split(char *str, const char *delim);
void my_puts(char *str);
void my_putchar(char c);
int point(char *str);
void usage(int ac, char **av);
int check_digit(int ac, char **av);
#endif
