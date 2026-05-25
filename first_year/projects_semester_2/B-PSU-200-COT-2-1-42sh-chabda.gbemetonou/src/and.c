/*
** EPITECH PROJECT, 2025
** decoup.c
** File description:
** just a function
*/

#include "../include/shell.h"

int advenced_error_2(char *line, char c)
{
    char stc[] = {c, c, '\0'};
    char *str = cleanstr(line, 0);
    char **red = strtowordarray(str, stc);

    if (str[0] == c && str[1] == c && str[2] != '\0') {
        print("stderr", "Invalid null command.\n");
        return 1;
    }
    if (red[0] == NULL && red[1] == NULL || red[1] == NULL) {
        print("stderr", "Invalid null command.\n");
        return 1;
    }
    return 0;
}

int and_function(shell_t *tmp, char *line, char **env)
{
    int status = 0;
    char **tab = strtowordarray(line, "&&");
    char **cmd1 = NULL;
    char **cmd2 = NULL;

    if (advenced_error_2(line, '&') == 1)
        return 1;
    cmd1 = verify_alias(tmp, my_split(tab[0], " \t"));
    cmd2 = verify_alias(tmp, my_split(tab[1], " \t"));
    recup_func(tmp, env, tab[0]);
    if (tmp->status == 0) {
        recup_func(tmp, env, tab[1]);
    } else {
        return 1;
    }
    return 0;
}

int or_function(shell_t *tmp, char *line, char **env)
{
    int status = 0;
    char **tab = strtowordarray(line, "||");
    char **cmd1 = NULL;
    char **cmd2 = NULL;

    if (advenced_error_2(line, '|') == 1)
        return 1;
    cmd1 = verify_alias(tmp, my_split(tab[0], " \t"));
    cmd2 = verify_alias(tmp, my_split(tab[1], " \t"));
    recup_func(tmp, env, tab[0]);
    if (tmp->status != 0) {
        recup_func(tmp, env, tab[1]);
        return 0;
    }
    return 1;
}
