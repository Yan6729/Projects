/*
** EPITECH PROJECT, 2024
** key_matrix.c
** File description:
** an intermediate function
*/

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isfloat(double num)
{
    int ent;
    double dec;

    ent = num;
    dec = num - ent;
    if (dec > 0.0)
        return 1;
    else
        return 0;
}

int count(int ac, char **av)
{
    int b = strlen(av[2]);
    int a = 0;
    double num = sqrt(b);
    int c = isfloat(num);
    int e = 0;

    if (c == 1)
        e = num + 1;
    else
        e = num;
    return e;
}

void display(int a, int **matrix)
{
    int	b = 0;
    int	c = 0;
    printf("Key matrix:\n");
    for (c = 0; c < a; c++) {
        for (b = 0; b < (a - 1); b++) {
           printf("%-7d", matrix[c][b]);
	}
        printf("%d\n", matrix[c][b]);
    }
    printf("\nEncrypted message:\n");
}

int **mat_encrypt(int ac, char **av)
{
    int tall = strlen(av[2]);
    int a = count(ac, av);
    int **crypt;
    int b = 0;
    int count = 0;
    int count_1 = 0;
    int d = 0;

    crypt = malloc(sizeof(int *) * (a + 1));
    for (b = 0; b < a; b++)
	crypt[b] = malloc(sizeof(int) * (a + 1));

    for (count = 0; count < a; count++) {
        for (count_1 = 0; count_1 < a; count_1++) {
	    if (d >= tall) {
		crypt[count][count_1] = 0;
	    } else {
		crypt[count][count_1] = av[2][d];
	    }
            d++;
	}
    }
    display(a, crypt);
    return crypt;
}
