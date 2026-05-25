/*
** EPITECH PROJECT, 2025
** my_setenv.c
** File description:
** setenv, env...
*/

#include "../include/shell.h"

int check_build_command(char **content, history_t **hist)
{
    if (strcmp(content[0], "cd") != 0
        && strcmp(content[0], "setenv") != 0
        && strcmp(content[0], "env") != 0
        && strcmp(content[0], "alias") != 0
        && strcmp(content[0], "unalias") != 0
        && strcmp(content[0], "history") != 0
        && strcmp(content[0], "unsetenv") != 0
        && strcmp(content[0], "repeat") != 0) {
        return 1;
    } else {
        return 0;
    }
}

void del(env_t *current, env_t **list, env_t *prev)
{
    if (prev) {
        prev->next = current->next;
    } else {
        *list = current->next;
    }
    free(current->name);
    free(current->value);
    free(current);
}

env_t *my_unsetenv(env_t **list, char *name)
{
    env_t *current = *list;
    env_t *prev = NULL;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            del(current, list, prev);
            break;
        }
        prev = current;
        current = current->next;
    }
    return *list;
}

int error_exec(char *path)
{
    struct stat buffer;

    if (path == NULL)
        return 84;
    if (errno == EACCES) {
        print("stderr", "%s: Permission denied.\n", path);
        return errno;
    }
    if (errno == ENOEXEC) {
        print("stderr", "%s", path);
        print("stderr", ": Exec format error. Binary file not executable.\n");
        return errno;
    }
}
