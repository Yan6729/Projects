/*
** EPITECH PROJECT, 2025
** my_getenv.c
** File description:
** just a file
*/

#include "../../include/shell.h"

char *my_getenv_list(env_t *list, char *name)
{
    if (!list || !name)
        return NULL;
    while (list) {
        if (strcmp(list->name, name) == 0)
            return list->value;
        list = list->next;
    }
    return NULL;
}

char *my_getenv(char *name, char **env)
{
    size_t len = strlen(name);

    if (!name || !env)
        return NULL;
    for (int i = 0; env[i] != NULL; i++) {
        if (strncmp(env[i], name, len) == 0 && env[i][len] == '=') {
            return &env[i][len + 1];
        }
    }
    return NULL;
}

char *get_home_directory(void)
{
    struct passwd *pw = getpwuid(getuid());

    if (pw == NULL)
        return NULL;
    return pw->pw_dir;
}
