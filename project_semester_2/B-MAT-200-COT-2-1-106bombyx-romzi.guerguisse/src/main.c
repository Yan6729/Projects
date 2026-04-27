/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** just a file
*/

#include "../include/math.h"

void usage(int ac, char **av)
{
    printf("USAGE\n");
    printf("    ./106bombyx n [k | i0 i1]\n");
    printf("DESCRIPTION\n");
    printf("    n\tnumber of first generation individuals\n");
    printf("    k\tgrowth rate from 1 to 4\n");
    printf("    i0\tinitial generation (included)\n");
    printf("    i1\tfinal generation (included)\n");
}

double bombyx2(int ac, char **av)
{
    double n = atof(av[1]);
    double i0 = atof(av[2]);
    double i1 = atof(av[3]);
    double xi = 0;
//    double x = 0;
    double k = 1.0;
    int i = 1;
    int j = 0;

    if (check_digit(av[1]) != 1 || point(av[1]) != 0)
        exit(84);
    if (check_digit(av[2]) != 1 || point(av[2]) != 0)
        exit(84);
    if (check_digit(av[3]) != 1 || point(av[3]) != 0)
        exit(84);
    if (i0 < 0 || i1 < 0 || n < 0 || i1 < i0)
        exit(84);

    for (k = 1.00; k <= 4.0; k += 0.01) {
        xi = n;
        for (i = 1; i < i0; i++) {
            xi = (k * xi * (1000 - xi) / 1000);
        }
        for  (j = i0; j <= i1; j++) {
            printf("%.2f %.2f\n", k, xi);
	    if (n > 1000)
		xi = 0;
            xi = (k * xi * (1000 - xi) / 1000);
        }
    }
    return 0;
}

double bombyx1(int ac, char **av)
{
    int n = atoi(av[1]);
    double k = atof(av[2]);
    int i = 2;
    double xi = (double)n;
    double x = 0;
    double j = 1;

    if (check_digit(av[1]) != 1 || point(av[1]) != 0)
        exit(84);
    if (check_digit(av[2]) != 1 || point(av[2]) > 1)
        exit(84);
    if (k < 1 || k > 4 || n < 0)
        exit(84);

    printf("%d %.2f\n", 1, xi);
    for (i = 2; i <= 100; i++) {
	if (n > 1000)
            xi = 0.0;
        xi = (k * xi * (1000 -  xi) / 1000);
        printf("%d %.2f\n", i, xi);
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 1 || ac > 4)
        return 84;
    else if (ac == 2)
        if (strcmp(av[1], "-h") == 0)
            usage(ac, av);
        else
            return 84;
    else {
        if (ac == 3) {
            bombyx1(ac, av);
        } else {
            bombyx2(ac, av);
        }
    }
    return 0;
}
