/*
** EPITECH PROJECT, 2025
** decoup.c
** File description:
** just a function
*/

#include "../include/shell.h"

int left_redirection(shell_t *tmp, char *cmd, char **env, char *filename)
{
    int fd[2] = {0, dup(0)};
    char **line1;
    int nb;

    fd[0] = open(filename, O_RDWR);
    dup2(fd[0], STDIN_FILENO);
    recup_func(tmp, env, cmd);
    dup2(fd[1], 0);
    close_fd(fd, 2);
    return 0;
}

void decoup(shell_t *tmp, left_t *list, char **env, char **red[2])
{
    int fd[2] = {0, dup(1)};

    fd[0] = open(".double_left", O_CREAT | O_RDWR, 0640);
    dup2(fd[0], STDOUT_FILENO);
    display_2(list);
    dup2(fd[1], 1);
    left_redirection(tmp, red[0][0], env, ".double_left");
    close_fd(fd, 2);
}
