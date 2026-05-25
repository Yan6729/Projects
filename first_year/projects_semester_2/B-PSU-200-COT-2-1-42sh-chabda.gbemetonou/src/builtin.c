/*
** EPITECH PROJECT, 2025
** intermediate.c
** File description:
** just a file
*/

#include "../include/shell.h"

void free_line(char *line, char *buffer, char **content, char **tab)
{
    if (!line || !buffer || !content || !tab)
        return;
    free(line);
    free(buffer);
    if (content) {
        for (int i = 0; content[i]; i++)
            free(content[i]);
        free(content);
    }
    if (tab) {
        for (int i = 0; tab[i]; i++)
            free(tab[i]);
        free(tab);
    }
}

void is_setenv(char **tab, env_t **list)
{
    if (count_arg(tab, 0) < 2)
        return;
    if (tab[2] && tab[3] == NULL) {
        *list = my_setenv(*list, tab[1], tab[2]);
        return;
    }
    if (tab[1] && !tab[2]) {
        *list = my_setenv(*list, tab[1], NULL);
        return;
    }
    print("stderr", "setenv: Too many arguments.\n");
    return;
}

void is_unsetenv(char **tab, env_t **list)
{
    for (int a = 1; tab[a]; a++)
        my_unsetenv(list, tab[a]);
}

void is_cd(char **tab, shell_t *tmp, char **env)
{
    if (!tab || !tab[0])
        return;
    if (!tab[1]) {
        tmp->list = change_directory(tmp, NULL, env);
        return;
    }
    if (tab[2] != NULL) {
        print("stderr", "cd: Too many arguments.\n");
        return;
    }
    tmp->list = change_directory(tmp, tab[1], env);
}

void is_builtins_cmd(shell_t *tmp, char **tab, char **tab_2, char **env)
{
    if (strcmp(tab[0], "exit") == 0 && tab[1] == NULL) {
        free_list(tmp->list);
        free_al(tmp->al);
        free_hl(tmp->cmp->hist);
        print("stdout", "exit\n");
        exit(EXIT_SUCCESS);
    }
    if (strcmp(tab[0], "unsetenv") == 0 && tab[1])
        is_unsetenv(tab, &tmp->list);
    if (strcmp(tab[0], "env") == 0 ||
        (strcmp(tab[0], "setenv") == 0 && !tab[1]))
        display(tmp->list);
    if ((strcmp(tab[0], "setenv") == 0) &&
        verify_setenv(tab[1]) == 0)
            is_setenv(tab, &tmp->list);
    if (strcmp(tab[0], "cd") == 0)
        is_cd(tab, tmp, env);
    is_history(tab, tab_2, tmp, env);
}
