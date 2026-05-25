/*
** EPITECH PROJECT, 2024
** my_cat.c
** File description:
** my_cat.c
*/

#include "my.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

char *my_read(int ac, char **av)
{
    struct stat size;
    int lire;
    int b;
    int file;
    int fd;
    char *c;
    char d[45] = "Sorry, this file doesn't exist\n";

    file = open(av[1], O_RDONLY);
    stat(av[1], &size);
    b = size.st_size;
    c = malloc(sizeof(char) * (b + 1));
    lire = read(file, c, b);
    close(file);
    return c;
}
