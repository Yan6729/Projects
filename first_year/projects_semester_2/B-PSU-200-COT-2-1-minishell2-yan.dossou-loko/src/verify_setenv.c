/*
** EPITECH PROJECT, 2025
** verify_setenv.c
** File description:
** just a file
*/

#include "../include/mysh.h"

void recup_func_2(char *lines, char **content, env_t *list, char **env)
{
    content = strtowordarray(lines, " \t");
    if (!content || !content[0]);
    is_builtins_cmd(content, &list, env, lines);
    if (check_build_command(content))
        get_pid(content, env);
}

void recup_func(char **tab, char **content, env_t *list, char **env)
{
    for (int a = 0; tab[a] != NULL; a++) {
        if (my_strstr(tab[a], ">>"))
            right_double_redirection(cleanstr(tab[a]), env);
        if (my_strstr(tab[a], ">") && !my_strstr(tab[a], ">>"))
            right_simple_redirection(cleanstr(tab[a]), env);
        if (my_strstr(tab[a], "<<"))
            left_double_redirection(cleanstr(tab[a]), env);
        if (my_strstr(tab[a], "<") && !my_strstr(tab[a], "<<"))
            left_simple_redirection(cleanstr(tab[a]), env);
        if (my_strstr(tab[a], "|"))
            e_w_pipe(tab[a], env);
        if (!my_strstr(tab[a], ">>") && !my_strstr(tab[a], ">")
        && !my_strstr(tab[a], "|") && !my_strstr(tab[a], "<<")
        && !my_strstr(tab[a], "<")) {
            recup_func_2(tab[a], content, list, env);
        }
    }
    free_line(NULL, NULL, content, tab);
}

int check_alpha(char *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if ((str[a] >= 65 && str[a] <= 90) ||
            (str[a] >= 97 && str[a] <= 122) ||
            str[a] == '_' || (str[a] >= 48
            && str[a] <= 57)) {
            continue;
        } else {
            return 1;
        }
    }
    return 0;
}

int verify_setenv(char *name)
{
    if (name == NULL)
        return 0;
    for (int a = 0; name[a] != '\0'; a++) {
        if (name[0] >= 48 && name[0] <= 57) {
            my_puts("setenv: Variable name must begin with a letter.\n", 2);
            return 1;
        }
        if (check_alpha(name) == 1) {
            my_puts("setenv: Variable name must contain", 2);
            my_puts(" alphanumeric characters.\n", 2);
            return 1;
        }
    }
    return 0;
}
