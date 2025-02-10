/*
** EPITECH PROJECT, 2024
** encryp.c
** File description:
** an intermediar function
*/
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "my.h"

int **encryp(int ac, char **av)
{
    int tall = strlen(av[1]);
    int col = count(ac, av);
    int lig = (tall / col) + 1;
    int **crypt;
    int b = 0;
    int count = 0;
    int count_1 = 0;
    int d = 0;

    crypt = malloc(sizeof(int *) * (lig + 1));
    for (b = 0; b < lig; b++)
        crypt[b] = malloc(sizeof(int) * (col + 1));

    for (count = 0; count < lig; count++) {
        for (count_1 = 0; count_1 < col; count_1++) {
            if (d >= tall)
		crypt[count][count_1] = 0;
	    else
		crypt[count][count_1] = av[1][d];
	    d++;
        }
    }
    return crypt;
}
