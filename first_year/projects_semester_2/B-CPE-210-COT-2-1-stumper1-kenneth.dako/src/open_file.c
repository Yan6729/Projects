/*
** EPITECH PROJECT, 2024
** parsing.c
** File description:
** an intermediar function
*/

#include "../include/tail.h"

char *read_file(char *filepath)
{
    char *str;
    struct stat size;
    char *buffer;
    int lire;
    int fd;
    int b;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        write(1, "This file doesn't exist\n", 25);
    } else if (fd > 0) {
        stat(filepath, &size);
        b = size.st_size;
        buffer = malloc(sizeof(char) * (b + 1));
        lire = read(fd, buffer, b);
        buffer[b] = '\0';
        close(fd);
    }
    str = my_strndup(buffer, 0, my_strlen(buffer) - 1);
    return str;
}

int count_line(char *src)
{
    int line = 0;
    char **str = my_split(src, "\n");

    for (int a = 0; str[a] != NULL; a++) {
        line++;
    }
    return line;
}

int tail(int a, char *filepath)
{
    char *src = read_file(filepath);
    char **str = my_split(src, "\n");
    int size = count_line(src);
    int num = a;

    if (a > size)
        num = size;
    for (int b = size - num; str[b] != NULL; b++) {
        my_putstr(str[b]);
        my_putchar('\n');
    }
    return 0;
}
