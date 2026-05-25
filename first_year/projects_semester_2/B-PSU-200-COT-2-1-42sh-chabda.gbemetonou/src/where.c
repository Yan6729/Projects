/*
** EPITECH PROJECT, 2025
** scripting.c
** File description:
** just a function
*/

#include "../include/shell.h"

void where(shell_t *tmp, char *lines)
{
    char **tab = my_split(lines, " \t");
    char *path1 = my_getenv("PATH", tmp->env);
    char **dir = NULL;
    char path[256];
    struct stat buffer;

    if (!path) {
        return;
    }
    dir = my_split(path1, ":");
    for (int i = 0; dir[i] != NULL; i++) {
        strcpy(path, dir[i]);
        strcat(path, "/");
        strcat(path, tab[0]);
        if (stat(path, &buffer) == 0 && (buffer.st_mode & S_IXUSR)) {
            continue;
        }
    }
}
