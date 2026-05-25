/*
** EPITECH PROJECT, 2025
** loop.c
** File description:
** just a loop file
*/

#include "../include/shell.h"

void exit_status_2(char *str)
{
    if (strcmp(str, "exit") == 0) {
        exit(EXIT_SUCCESS);
    }
}

int loop_3(int ac, char **av, char **env)
{
    shell_t *tmp = rempli_struct(ac, av, env);
    char *clone = NULL;

    data = tmp->list;
    signal(SIGINT, handle_signal);
    if (tmp->cmp->count)
        tmp->num = tmp->cmp->count + 1;
    separation_bash(&tmp->al, ".42shrc", env);
    for (int a = 0; a < 1; a++) {
        tmp->buffer = stdin_rec(tmp, file_histor(".history_save", env));
        if (cleanstr(tmp->buffer, 0)[0] != '\0') {
            clone = my_strdup(tmp->buffer, 0);
            add_h(&tmp->cmp->hist, cleanstr(clone, 1), tmp->num);
            tmp->num++;
        }
        tmp->tab = strtowordarray(tmp->buffer, ";");
        boucle_fun(tmp);
    }
    return 0;
}

int loop_2(int ac, char **av, char **env)
{
    shell_t *tmp = rempli_struct(ac, av, env);
    char *clone = NULL;

    data = tmp->list;
    signal(SIGINT, handle_signal);
    if (tmp->cmp->count)
        tmp->num = tmp->cmp->count + 1;
    separation_bash(&tmp->al, ".42shrc", env);
    while (1) {
        print("stdout", "> ");
        tmp->buffer = stdin_rec(tmp, file_histor(".history_save", env));
        if (cleanstr(tmp->buffer, 0)[0] != '\0') {
            clone = my_strdup(tmp->buffer, 0);
            add_h(&tmp->cmp->hist, cleanstr(clone, 1), tmp->num);
            tmp->num++;
        }
        tmp->tab = strtowordarray(tmp->buffer, ";");
        boucle_fun(tmp);
    }
    return 0;
}

int loop_4(int ac, char **av, char **env)
{
    shell_t *tmp = rempli_struct(ac, av, env);

    signal(SIGINT, handle_signal_2);
    while (1) {
        print("stdout", "> ");
        tmp->buffer = stdin_rec(tmp, file_histor(".history_save", env));
    }
    free(tmp->buffer);
}
