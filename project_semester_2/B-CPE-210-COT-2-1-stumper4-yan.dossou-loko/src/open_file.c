/*
** EPITECH PROJECT, 2024
** Elementary
** File description:
** Map from file.
*/

#include "../include/my.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char *open_file(char *file)
{
    int fd = open(file, O_RDONLY);
    struct stat sb;
    char *buf;
    int rd;

    if (fd == -1) {
        return NULL;
    }
    stat(file, &sb);
    buf = malloc(sizeof(char) * (sb.st_size + 1));
    rd = read(fd, buf, sb.st_size + 1);
    buf[rd - 1] = '\0';
    close(fd);
    return buf;
}
