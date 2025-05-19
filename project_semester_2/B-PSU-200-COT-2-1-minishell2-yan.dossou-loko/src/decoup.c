/*
** EPITECH PROJECT, 2025
** decoup.c
** File description:
** just a function
*/

#include "../include/mysh.h"

int left_redirection(char *cmd, char **env, char *filename)
{
    int fd[2] = {0, dup(0)};
    char **line1;
    int nb;

    line1 = strtowordarray(cleanstr(cmd), " \t");
    fd[0] = open(filename, O_RDWR);
    dup2(fd[0], STDIN_FILENO);
    get_pid(line1, env);
    dup2(fd[1], 0);
    close_fd(fd, 2);
    return 0;
}

void decoup(int fd[2], left_t *list, char **env, char **red[2])
{
    fd[0] = open(".double_left", O_CREAT | O_RDWR, 0640);
    dup2(fd[0], STDOUT_FILENO);
    display_2(list);
    dup2(fd[1], 1);
    left_redirection(red[0][0], env, ".double_left");
    close_fd(fd, 2);
}
