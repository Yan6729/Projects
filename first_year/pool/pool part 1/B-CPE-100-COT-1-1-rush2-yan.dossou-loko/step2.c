/*
** EPITECH PROJECT, 2024
** step2.c
** File description:
** step2.c
*/

#include <unistd.h>
#include <stdio.h>
#include "include/my.h"
int step2(int ac, char **av)
{
    int d;
    int b;
    int a;

    b = 0;
    for (d = 2; av[d] != NULL; d++) {
        for (a = 0; av[1][a] != '\0'; a++) {
            if (av[1][a] == av[d][0]) {
		b++;
	    }
            if (av[1][a] == av[d][0] + 32) {
                b++;
	    }
            if (av[1][a] == av[d][0] - 32) {
		b++;
	    }
	}
    }
    return b;
}
//int main(int ac, char **av)
//{
//  printf("%d", step2(ac, av));
//  return 0;
//}
