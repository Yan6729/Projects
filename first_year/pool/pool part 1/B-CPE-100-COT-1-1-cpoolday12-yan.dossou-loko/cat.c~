/*
** EPITECH PROJECT, 2024
** my_cat.c
** File description:
** my_cat.c
*/

#include <errno.h>
#include "my.h"
#include <unistd.h>
#include <fcntl.h>

#define FILE 30000

int my_cat(int ac, char **av)
{
    extern int errno;
    int a;
    int lire;
    int file;
    char c[FILE];
    char d[45] = "Sorry, this file doesn't exist";

    for (a = 1; ac > 1; a++) {
        file = open(av[a], O_RDONLY);
        if (file == -1) {
            write(1, d, 45);
            my_putchar('\n');
            my_put_nbr(errno);
        }
        lire = read(file, c, FILE);
        my_putstr(c);
        close(file);
        ac--;
    }
}

void main(int ac, char **av)
{
    int tall;
    char c[FILE];

    while (ac < 2) {
        tall = read(0, c, FILE);
        write(1, c, tall);
    }
    my_cat(ac, av);
}
