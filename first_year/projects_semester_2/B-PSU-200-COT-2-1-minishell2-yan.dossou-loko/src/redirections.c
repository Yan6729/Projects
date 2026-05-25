/*
** EPITECH PROJECT, 2025
** redirection.c
** File description:
** just a function
*/

#include "../include/mysh.h"

void close_fd(int *fd, int b)
{
    for (int a = 0; a < b; a++) {
        close(fd[a]);
    }
}

int left_simple_redirection(char *line, char **env)
{
    int fd[2] = {0, dup(0)};
    char **red;
    char **line1;
    int nb;

    if (simple_error(line, '<') == 1)
        return 1;
    red = strtowordarray(line, "<");
    line1 = strtowordarray(cleanstr(red[0]), " \t");
    nb = count_arg(red, 1);
    fd[0] = open(cleanstr(red[nb]), O_RDONLY);
    if (simple_l_error(line, '<', fd[0]) == 1)
        return 1;
    dup2(fd[0], STDIN_FILENO);
    get_pid(line1, env);
    dup2(fd[1], 0);
    return 0;
}

int left_double_redirection(char *line, char **env)
{
    int fd[2] = {0, dup(1)};
    char *buffer[2] = {NULL, NULL};
    size_t nb = 0;
    char **red[2];
    left_t *list = NULL;

    if (advenced_error(line, '<') == 1)
        return 1;
    red[0] = strtowordarray(line, "<<");
    while (1) {
        my_puts("> ", 1);
        if (getline(&buffer[0], &nb, stdin) == -1)
            break;
        buffer[1] = my_strndup(buffer[0], 0, (strlen(buffer[0]) - 1));
        if (my_strcmp(buffer[1], cleanstr(red[0][1])) == 0)
            break;
        add_2(&list, buffer[1]);
    }
    decoup(fd, list, env, red);
    return 0;
}

int right_simple_redirection(char *line, char **env)
{
    int fd[2] = {0, dup(1)};
    char **red;
    char **line1;
    int nb;

    if (simple_error(line, '>') == 1)
        return 1;
    red = strtowordarray(line, ">");
    nb = count_arg(red, 1);
    create_file(red, 1, nb);
    line1 = strtowordarray(cleanstr(red[0]), " \t");
    fd[0] = open(cleanstr(red[nb]), O_CREAT | O_RDWR, 0775);
    dup2(fd[0], STDOUT_FILENO);
    get_pid(line1, env);
    dup2(fd[1], 1);
    close_fd(fd, 2);
    return 0;
}

int right_double_redirection(char *line, char **env)
{
    int fd[2] = {0, dup(1)};
    char **red[2];
    int nb;

    if (advenced_error(line, '>') == 1)
        return 1;
    red[0] = strtowordarray(cleanstr(line), ">>");
    nb = count_arg(red[0], 1);
    create_file(red[0], 1, nb);
    red[1] = strtowordarray(cleanstr(red[0][0]), " \t");
    fd[0] = open(cleanstr(red[0][1]), O_WRONLY | O_APPEND);
    if (fd[0] <= 0) {
        right_simple_redirection(line, env);
        return 0;
    }
    dup2(fd[0], STDOUT_FILENO);
    get_pid(red[1], env);
    dup2(fd[1], 1);
    close_fd(fd, 2);
    return 0;
}
