/*
** EPITECH PROJECT, 2025
** open hostname
** File description:
** just a function
*/

#include "../../include/mysh.h"

char *my_hostname(char *filepath)
{
    char *buffer;
    int lire;
    int fd;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        write(1, "This file doesn't exist\n", 25);
    } else if (fd > 0) {
        buffer = malloc(sizeof(char) * UCHAR_MAX);
        lire = read(fd, buffer, UCHAR_MAX);
        close(fd);
    }
    buffer[lire] = '\0';
    return buffer;
}

int count_arg(char **str, int e)
{
    int nb = 0;

    for (int a = e; str[a] != NULL; a++) {
        nb++;
    }
    return nb;
}
