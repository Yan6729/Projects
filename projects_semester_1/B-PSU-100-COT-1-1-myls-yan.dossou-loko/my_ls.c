/*
** EPITECH PROJECT, 2024
** my_ls.c
** File description:
** fonction who display a file in a folder.
*/
#include "my.h"
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int part1(struct dirent *d, DIR *rep)
{
    d = readdir(rep);
    while (d != NULL) {
        if (d->d_name[0] != '.') {
            my_putstr(d->d_name);
            my_putstr("\t");
        }
        d = readdir(rep);
    }
}

int part2(struct dirent *d, DIR *rep, int ac, char **av)
{
    int a;

    for (a = 1; a < ac; a++) {
        rep = opendir(av[a]);
        if (rep != NULL) {
            part1(d, rep);
        } else {
            perror("Unable to read directory");
            exit(EXIT_FAILURE);
        }
    }
}

int part3(struct dirent *d, DIR *rep, int ac, char **av)
{
    int a;

    for (a = 1; a < ac; a++) {
        rep = opendir(av[a]);
        if (rep != NULL) {
            my_putstr(av[a]);
            my_putstr(" : ");
            my_putchar('\n');
            part1(d, rep);
        } else {
            perror("Unable to read directory");
            exit(EXIT_FAILURE);
        }
        if (a != ac - 1)
            my_putstr("\n\n");
    }
}

int my_ls(int ac, char **av)
{
    int a;
    struct dirent *d;
    DIR *rep;

    if (ac == 1) {
        rep = opendir(".");
        part1(d, rep);
    } else if (ac == 2) {
        part2(d, rep, ac, av);
    } else {
        part3(d, rep, ac, av);
    }
    my_putchar('\n');
    closedir(rep);
    return 0;
}

int main(int ac, char **av)
{
    my_ls(ac, av);
}
