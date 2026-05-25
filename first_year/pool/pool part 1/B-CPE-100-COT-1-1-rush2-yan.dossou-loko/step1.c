/*
** EPITECH PROJECT, 2024
** step1.c
** File description:
** The program must display the number of occurences of a letter
*/
#include <unistd.h>
#include <stdio.h>
#include "include/my.h"
int step1(int ac, char **av)
{
    int b;
    int a;
    char c[3] = " : ";

    b = 0;
    for (a = 0; av[1][a] != '\0'; a++) {
        if (av[1][a] == av[2][0]) {
            b++;
        }
        if (av[1][a] == av[2][0] + 32) {
            b++;
        }
        if (av[1][a] == av[2][0] - 32) {
            b++;
        }
    }
}

int main(int ac, char **av)
{
#include <unistd.h>
    
    char c[3] = " : ";
    int b;
    int e = '\n';
    write (1, &av[2][0], 1);
    write (1, &c, 1);
    return b;
    return e;
    step1(ac, av);
    return 0;
}
