/*
** EPITECH PROJECT, 2025
** loop.c
** File description:
** just a loop file
*/

#include "../include/mysh.h"

void exit_status_2(char *str)
{
    if (my_strcmp(str, "exit") == 0) {
        exit(EXIT_SUCCESS);
    }
}

int loop_3(int ac, char **av, char **env)
{
    char *buffer = NULL;
    env_t *list = copy_env(env);
    char **content = NULL;
    char **tab = NULL;

    signal(SIGINT, handle_signal_3);
    for (int a = 0; a < 1; a++) {
        buffer = stdin_rec(&list);
        tab = strtowordarray(buffer, ";");
        recup_func(tab, content, list, env);
        free_line(buffer, NULL, NULL, NULL);
    }
    free_list(list);
    return EXIT_SUCCESS;
}

int loop_2(int ac, char **av, char **env)
{
    char *buffer = NULL;
    env_t *list = copy_env(env);
    char **content = NULL;
    char **tab = NULL;

    signal(SIGINT, handle_signal_2);
    while (1) {
        my_puts("> ", 1);
        buffer = stdin_rec(&list);
        tab = strtowordarray(buffer, ";");
        recup_func(tab, content, list, env);
        free_line(buffer, NULL, NULL, NULL);
    }
    free_list(list);
    return 0;
}

int loop_4(int ac, char **av, char **env)
{
    env_t *list = copy_env(env);
    char *buffer;
    char **content;

    signal(SIGINT, handle_signal_2);
    while (1) {
        my_puts("> ", 1);
        buffer = stdin_rec(&list);
    }
    free(buffer);
}
