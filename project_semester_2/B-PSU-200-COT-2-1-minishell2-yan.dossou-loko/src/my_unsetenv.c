/*
** EPITECH PROJECT, 2025
** my_setenv.c
** File description:
** setenv, env...
*/

#include "../include/mysh.h"

int check_build_command(char **content)
{
    if (my_strcmp(content[0], "cd") != 0
        && my_strcmp(content[0], "setenv") != 0
        && my_strcmp(content[0], "env") != 0
        && my_strcmp(content[0], "unsetenv") != 0) {
        return 1;
    } else {
        return 0;
    }
}

void del(env_t *current, env_t *list, env_t *prev)
{
    if (prev) {
        prev->next = current->next;
    } else {
        list = current->next;
    }
    free(current->name);
    free(current->value);
    free(current);
}

env_t *my_unsetenv(env_t *list, char *name)
{
    env_t *current = list;
    env_t *prev = NULL;

    while (current) {
        if (my_strcmp(current->name, name) == 0) {
            del(current, list, prev);
            break;
        }
        prev = current;
        current = current->next;
    }
    return list;
}

int error_exec(char *path)
{
    if (errno == EACCES) {
        my_puts(path, 2);
        my_puts(": Permission denied.\n", 2);
        return errno;
    }
    if (errno == ENOEXEC) {
        my_puts(path, 2);
        my_puts(": Exec format error. Binary file not executable.\n", 2);
        return errno;
    }
}
