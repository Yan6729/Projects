/*
** EPITECH PROJECT, 2025
** v_command_2.c
** File description:
** just a file
*/

#include "../include/shell.h"

void recup_func_3(char *lines, shell_t *tmp, char **env)
{
    if (strstr(lines, "&&")) {
        and_function(tmp, lines, env);
        return;
    }
    if (strstr(lines, "||")) {
        or_function(tmp, lines, env);
        return;
    }
    if (strstr(lines, ">") && !strstr(lines, ">>")) {
        right_simple_redirection(tmp, lines, env);
        return;
    }
    if (strstr(lines, ">>")) {
        right_double_redirection(tmp, lines, env);
        return;
    }
    if (strstr(lines, "<") && !strstr(lines, "<<")) {
        left_simple_redirection(tmp, lines, env);
        return;
    }
}
