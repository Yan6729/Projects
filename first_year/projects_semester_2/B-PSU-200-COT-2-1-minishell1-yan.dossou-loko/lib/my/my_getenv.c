/*
** EPITECH PROJECT, 2025
** my_getenv.c
** File description:
** just a file
*/

#include "../../include/mysh.h"

char *my_getenv_list(env_t *list, char *name)
{
    if (!list || !name)
        return NULL;
    while (list) {
        if (my_strcmp(list->name, name) == 0)
            return list->value;
        list = list->next;
    }
    return NULL;
}

char *my_getenv(char *name, char **env)
{
    size_t len = my_strlen(name);

    if (!name || !env)
        return NULL;
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], name, len) == 0 && env[i][len] == '=') {
            return &env[i][len + 1];
        }
    }
    return NULL;
}
