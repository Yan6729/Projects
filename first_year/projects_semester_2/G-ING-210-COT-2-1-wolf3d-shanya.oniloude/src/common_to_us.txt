/*
** EPITECH PROJECT, 2025
** load
** File description:
** map
*/

#include "../include/wolf3d.h"

char *open_file(char const *filepath)
{
    int fd;
    struct stat info;
    char *buffer = NULL;

    if (stat(filepath, &info) == -1) {
        return NULL;
    }
    buffer = malloc((info.st_size + 1) * sizeof(char));
    if (!buffer)
        return NULL;
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        printf("FAILURE\n");
        free(buffer);
        return NULL;
    }
    read(fd, buffer, info.st_size);
    buffer[info.st_size] = '\0';
    close(fd);
    return buffer;
}

char **parsing(char *line, const char *sep)
{
    int max = 1000;
    char **args = malloc(sizeof(char *) * (max + 1));
    int count = 0;
    char *tab;

    if (!args)
        return NULL;
    tab = strtok(line, sep);
    while (tab) {
        args[count] = tab;
        count++;
        if (count >= max)
            break;
        tab = strtok(NULL, sep);
    }
    args[count] = NULL;
    return args;
}

player_t init_player(float x, float y, float angle)
{
    player_t player;

    player.x = x;
    player.y = y;
    player.angle = angle;
    return player;
}
