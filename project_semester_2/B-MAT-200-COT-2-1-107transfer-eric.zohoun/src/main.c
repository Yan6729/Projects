/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** just a file
*/

#include "../include/math.h"

void usage(int ac, char **av)
{
    my_puts("USAGE\n");
    my_puts("    ./106bombyx n [k | i0 i1]\n");
    my_puts("DESCRIPTION\n");
    my_puts("    num\tpolynomial numerator defined by its coefficients\n");
    my_puts("    den\tpolynomial denominator defined by its coefficients\n");
}

double transfer2(int ac, char **av)
{
    return 0;
}

double transfer1(int ac, char **av)
{
    double n, y, a, u = 0;
    int i, p, x = 0;

    while (n < 1.001) {
        for (x = 2; x < strlen(av[1]); x += 2) {
            i = av[1][x] - 48;
	    u = pow(n, p);
            y = (i * u) + a;
            p++;
            a = y;
        }
        printf("%.3f -> %.5f\n", n, a);
	p = 1;
	a = 0;
	n += 0.001;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 1)
        return 84;
    else if (ac == 2)
        if (strcmp(av[1], "-h") == 0)
            usage(ac, av);
        else
            return 84;
    else {
        if (ac % 2 != 0) {
            check_digit(ac, av);
            transfer1(ac, av);
        } else {
	    exit(84);
	}
    }
    return 0;
}
