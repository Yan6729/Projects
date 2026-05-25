/*
** EPITECH PROJECT, 2025
** backtic.c
** File description:
** Just a file
*/

#include "../include/shell.h"

int just_a_function(shell_t *tmp, char *line, char *filename)
{
    int fd[2] = {0, dup(1)};
    int nb = 0;
    char *name = NULL;

    fd[0] = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0640);
    dup2(fd[0], STDOUT_FILENO);
    recup_func(tmp, tmp->env, line);
    dup2(fd[1], 1);
    close_fd(fd, 2);
    return 0;
}

char *backtick(char *filename, char *line, shell_t *tmp)
{
    char *buff = NULL;

    just_a_function(tmp, line, filename);
    buff = open_file(filename);
    printf("%s", buff);
    return buff;
}

/* int main(int ac, char **av, char **env) */
/* { */
/*     shell_t *tmp = rempli_struct(ac, av, env); */

/*     //just_a_function(tmp, av[1], ".backtic"); */
/*     backtick(".backtic", av[1], tmp); */
/* //    printf("%s\n", open_file(".backtic")); */
/* } */
