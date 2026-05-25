/*
** EPITECH PROJECT, 2025
** intermediate.c
** File description:
** just a file
*/

#include "../include/mysh.h"

void free_line(char *line, char *buffer, char **content)
{
    free(line);
    free(buffer);
    if (content) {
        for (int i = 0; content[i]; i++)
            free(content[i]);
        free(content);
    }
}

void is_setenv(char **tab, env_t **list)
{
    if (tab[2] && tab[3] == NULL) {
        *list = my_setenv(*list, tab[1], tab[2]);
        return;
    }
    if (tab[1] && !tab[2]) {
        *list = my_setenv(*list, tab[1], NULL);
        return;
    }
    my_puts_2("setenv: Too many arguments.\n");
    return;
}

void is_unsetenv(char **tab, env_t **list)
{
    for (int a = 1; tab[a]; a++)
        *list = my_unsetenv(*list, tab[a]);
}

void is_cd(char **tab, env_t **list, char **env)
{
    if (tab[2] != NULL) {
        my_puts_2("cd: Too many arguments.\n");
        return;
    }
    *list = change_directory(*list, tab[1], env);
}

void is_builtins_cmd(char **tab, env_t **list, char **env)
{
    if (my_strcmp(tab[0], "exit") == 0) {
        free_list(*list);
        my_puts("exit\n");
        exit(EXIT_SUCCESS);
    }
    if ((my_strcmp(tab[0], "setenv") == 0) && verify_setenv(tab[1]) == 0)
        is_setenv(tab, list);
    if (my_strcmp(tab[0], "unsetenv") == 0 && tab[1])
        is_unsetenv(tab, list);
    if (my_strcmp(tab[0], "env") == 0 ||
        (my_strcmp(tab[0], "setenv") == 0 && !tab[1]))
        display(*list);
    if (my_strcmp(tab[0], "cd") == 0)
        is_cd(tab, list, env);
}
