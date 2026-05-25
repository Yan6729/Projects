/*
** EPITECH PROJECT, 2025
** redirection.c
** File description:
** just a function
*/

#include "../include/shell.h"

void close_fd(int *fd, int b)
{
    for (int a = 0; a < b; a++) {
        close(fd[a]);
    }
}

int left_simple_redirection(shell_t *tmp, char *line, char **env)
{
    int fd[2] = {0, dup(0)};
    char **red = NULL;
    int nb = 0;
    char *name = NULL;

    if (simple_error(line, '<') == 1)
        return 1;
    red = strtowordarray(line, "<");
    nb = count_arg(red, 1);
    name = my_split(red[nb], " ")[0];
    fd[0] = open(name, O_CREAT | O_RDWR, 0775);
    if (simple_l_error(line, '<', fd[0]) == 1)
        return 1;
    dup2(fd[0], STDIN_FILENO);
    recup_func(tmp, env, red[0]);
    dup2(fd[1], 0);
    return 0;
}

int left_double_redirection(shell_t *tmp, char *line, char **env)
{
    char *buffer[2] = {NULL, NULL};
    size_t nb = 0;
    char **red[2];
    left_t *list = NULL;

    if (advenced_error(line, '<') == 1)
        return 1;
    red[0] = strtowordarray(line, "<<");
    while (1) {
        print("stdout", "> ");
        if (getline(&buffer[0], &nb, stdin) == -1)
            break;
        buffer[1] = my_strndup(buffer[0], 0, (strlen(buffer[0]) - 1));
        if (strcmp(buffer[1], my_split(red[0][1], " ")[0]) == 0)
            break;
        add_2(&list, buffer[1]);
    }
    decoup(tmp, list, env, red);
    return 0;
}

int right_simple_redirection(shell_t *tmp, char *line, char **env)
{
    int fd[2] = {0, dup(1)};
    char **red = NULL;
    int nb = 0;
    char *name = NULL;

    if (simple_error(line, '>') == 1)
        return 1;
    red = strtowordarray(line, ">");
    nb = count_arg(red, 1);
    create_file(red, 1, nb);
    name = my_split(red[nb], " ")[0];
    fd[0] = open(name, O_CREAT | O_RDWR | O_TRUNC, 0775);
    dup2(fd[0], STDOUT_FILENO);
    recup_func(tmp, env, red[0]);
    dup2(fd[1], 1);
    close_fd(fd, 2);
    return 0;
}

int right_double_redirection(shell_t *tmp, char *line, char **env)
{
    int fd[2] = {0, dup(1)};
    char **red[2];
    int nb;
    char *name = NULL;

    if (advenced_error(line, '>') == 1)
        return 1;
    red[0] = strtowordarray(line, ">>");
    nb = count_arg(red[0], 1);
    create_file(red[0], 1, nb);
    name = my_split(red[0][nb], " ")[0];
    fd[0] = open(name, O_CREAT | O_RDWR | O_APPEND, 0775);
    dup2(fd[0], STDOUT_FILENO);
    recup_func(tmp, env, cleanstr(red[0][0], 0));
    dup2(fd[1], 1);
    close_fd(fd, 2);
    return 0;
}
