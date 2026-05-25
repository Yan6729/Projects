/*
** EPITECH PROJECT, 2025
** Shell prog
** File description:
** Minishell 2.
*/

#include "../include/my.h"

int is_char(char e)
{
    if (e == ' ' || e == '\n' || e == '\t' || e == '\r' || e == '\v')
        return 1;
    return 0;
}

char mini_f(char n)
{
    if (n == '\t')
        n = ' ';
    return n;
}

char *format_cmd(char *cmd)
{
    int len = strlen(cmd);
    char *new_cmd = malloc(sizeof(char) * (len + 1));
    int i = 0;

    for (int a = 0; cmd[a] != '\0'; a++) {
        if (is_char(cmd[a]) == 1)
            continue;
            new_cmd[i] = cmd[a];
            i++;
        if (is_char(cmd[a + 1]) == 1) {
            new_cmd[i] = cmd[a + 1];
            new_cmd[i] = mini_f(new_cmd[i]);
            i++;
        }
    }
    if (is_char(new_cmd[i - 1]) == 1) {
        i = i - 1;
    }
    new_cmd[i] = '\0';
    return new_cmd;
}
