/*
** EPITECH PROJECT, 2024
** my_open_file.c
** File description:
** just a part of my function
*/

#include "my.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

char **my_open_file(int ac, char **av)
{
    int i;
    int c;
    char *src;
    int a = 0;
    int b = 0;
    char **map;

    src = my_read(ac, av);
    map = my_malloc(src, ac, av);
    for (c = 0; src[c] != '\0'; c++) {
        map[a][b] = src[c];
        b++;
        if (src[c] == '\n') {
            map[a][b] = '\0';
            b = 0;
            a++;
        }
    }
    map[a + 1] = NULL;
    return map;
}
