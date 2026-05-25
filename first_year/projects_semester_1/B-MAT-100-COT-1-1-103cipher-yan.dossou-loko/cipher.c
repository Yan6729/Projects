/*
** EPITECH PROJECT, 2024
** cipher
** File description:
** cipher
*/

#include "my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int usage(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
	printf("USAGE\n");
	printf("    ./103cipher message key flag");
	printf("\n\n\nDESCRIPTION\n");
	printf("    message     a message, made of ASCII characters\n");
	printf("    key         the encryption key, made of ASCII characters\n ");
	printf("   flag        0 for the message to be encrypted,");
	printf(" 1 to be decrypted\n");
    }
}

int **encrypt(int ac, char **av)
{
    int a, b, c, i, j, k = 0;
    int n = count(ac, av);
    int r = strlen(av[1]);
    int m = (r / n) + 1;
    int **mul;
    int **crypt = mat_encrypt(ac, av);
    int **matrix = encryp(ac, av);
    
    mul = malloc(sizeof(int *) * (m + 1));
    for (b = 0; b < m; b++)
	mul[b] = malloc(sizeof(int) * (n + 1));
    for(i = 0; i < m; i++) {
	for(j = 0; j < n; j++) {
	    mul[i][j] = 0;
	    for(k = 0; k < n; k++) {
		mul[i][j] += matrix[i][k] * crypt[k][j];
	    }
	}
    }
    for(i = 0; i < m - 1; i++) {
        for(j = 0; j < n; j++) {
	    printf("%d ",mul[i][j]);
	}
    }
    for (;i == m - 1; i++) {
	for (j = 0; j < n - 1; j++)
	    printf("%d ", mul[i][j]);
	printf("%d", mul[i][j]);
    }
    printf("\n");
    for (c = 0; crypt[c] != NULL; c++)
	free(crypt[c]);
    free(crypt);

    for (a = 0; matrix[a] != NULL; a++)
	free(matrix[a]);
    free(matrix);
    return mul;
}

int main(int ac, char **av)
{
    int c;
    
    if (ac == 1)
        return 84;
    else if (ac == 2)
	usage (ac, av);
    else if (ac == 4) {
	if (av[3][0] == '0' && av[3][1] == '\0') {
	    int **mul = encrypt(ac, av);
	    for (c = 0; mul[c] != NULL; c++)
		free(mul[c]);
	    free(mul);
	} else {
	    return 84;
	}
    } else
	return 84;
}
