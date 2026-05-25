/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** function heart
*/

#include "../include/tail.h"

int function(char *filepath)
{
    int b;
    int a;
    int file;
    struct stat size;

    stat(filepath, &size);
    b = size.st_size;
    if (b == 0)
        return 84;
    file = open(filepath, O_RDONLY);
    if (file <= 0) {
        my_putstr("Sorry, this file doesn't exist\n");
        return 84;
    }
}

void tail_c(char *filename, int nb)
{
    char *buf = read_file(filename);
    int len = my_strlen(buf);

    for (int a = len - (nb - 1); buf[a] != '\0'; a++) {
        my_putchar(buf[a]);
    }
    my_putchar('\n');
}

int flags(int b, char **av)
{
    if (my_strcmp(av[1], "-v") == 0) {
        my_putstr("==> ");
        my_putstr(av[2]);
        my_putstr(" <==\n");
        tail(10, av[2]);
        return 1;
    }
    if (my_strcmp(av[1], "-q") == 0) {
        tail(10, av[2]);
        return 1;
    }
    tail(b, av[2]);
    return 0;
}

int flags_2(int b, char **av)
{
    if (my_strcmp(av[1], "-n") == 0) {
        tail(b, av[3]);
        return 1;
    }
    if (my_strcmp(av[1], "-c") == 0) {
        tail_c(av[3], b);
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    int a = 0;
    int b = 0;

    if (ac == 1 || ac > 4) {
        return 84;
    }
    if (ac == 2) {
        tail(10, av[1]);
        a = function(av[1]);
    } else if (ac == 3) {
	b = my_getnbr(av[1]);
	flags(b, av);
        a = function(av[2]);
    } else {
	b = my_getnbr(av[2]);
        flags_2(b, av);
        a = function(av[3]);
        return a;
    }
}
