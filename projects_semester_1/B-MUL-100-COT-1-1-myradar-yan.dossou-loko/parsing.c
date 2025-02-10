/*
** EPITECH PROJECT, 2024
** parsing.c
** File description:
** an intermediar function
*/

#include "struct.h"

char *read_file(int ac, char **av)
{
    struct stat size;
    char *buffer;
    int lire;
    int fd;
    int b;

    fd = open(av[1], O_RDONLY);
    if (fd == -1) {
        write(1, "This file doesn't exist\n", 25);
    } else if (fd > 0) {
        stat(av[1], &size);
        b = size.st_size;
        buffer = malloc(sizeof(char) * (b));
        lire = read(fd, buffer, b);
        close(fd);
    }
    return buffer;
}

char **map_stocked(char **map, int c, int ac, char **av)
{
    char *s = read_file(ac, av);
    int a = 0;
    int b = 0;
    int d = 0;

    map = my_malloc(ac, av);
    for (c = 0; s[c] != '\0'; c++) {
        map[a][b] = s[c];
        b++;
        d = c + 1;
        if ((s[d] == ' ' || s[d] == '\n' || s[d] == '\r') && s[d] != '\0') {
            map[a][b] = '\0';
            c++;
            b = 0;
            a++;
        }
    }
    map[a + 1] = NULL;
    free(s);
    return map;
}
