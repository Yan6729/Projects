/*
** EPITECH PROJECT, 2025
** pipe_func.c
** File description:
** just a file
*/

#include "../include/mysh.h"

void close_all(int pipes[MAX_CMD - 1][2], int *v)
{
    int nb_args = *v;

    for (int a = 0; a < nb_args - 1; a++) {
        close(pipes[a][0]);
        close(pipes[a][1]);
    }
}

int pipe_func(char **env, char **commands, int *tab[2],
    int pipes[MAX_CMD - 1][2])
{
    int i = *tab[0];
    int nb_args = *tab[1];
    pid_t pid = fork();
    char **map = NULL;

    if (pid == -1)
        exit(1);
    if (pid == 0) {
        if (i > 0) {
            dup2(pipes[i - 1][0], STDIN_FILENO);
        }
        if (i < nb_args - 1) {
            dup2(pipes[i][1], STDOUT_FILENO);
        }
        close_all(pipes, &nb_args);
        map = strtowordarray(commands[i], " \t");
        get_pid(map, env);
        exit(1);
    }
}

int e_w_pipe(char *line, char **env)
{
    char **pipe_tab;
    int nb_args;
    int pipes[MAX_CMD - 1][2];

    pipe_tab = strtowordarray(cleanstr(line), "|");
    nb_args = count_arg(pipe_tab, 0);
    if (pipe_error(line, '|') == 1)
        return 1;
    for (int e = 0; e < nb_args - 1; e++) {
        if (pipe(pipes[e]) == -1)
            exit(1);
    }
    for (int a = 0; a < nb_args; a++) {
        pipe_func(env, pipe_tab, (int *[2]){&a, &nb_args}, pipes);
    }
    close_all(pipes, &nb_args);
    for (int b = 0; b < nb_args; b++) {
        wait(NULL);
    }
}
