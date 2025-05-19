/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** that's my main function
*/

#include "../include/mysh.h"

const env_t *data = NULL;

void free_list(env_t *env)
{
    env_t *current = env;
    env_t *next = NULL;

    if (env == NULL)
        return;
    if (env == data)
        data = NULL;
    for (current; current != NULL; current = next) {
        next = current->next;
        if (current->name != NULL) {
            free(current->name);
            current->name = NULL;
        }
        if (current->value != NULL) {
            free(current->value);
            current->value = NULL;
        }
        free(current);
    }
}

char *stdin_rec(env_t **list)
{
    char *line = NULL;
    char *buffer = NULL;
    size_t size = 0;
    history_t **liste;

    if (getline(&buffer, &size, stdin) == -1) {
        free_list(*list);
        my_puts("exit\n", 1);
        exit(EXIT_SUCCESS);
    }
    line = my_strndup(buffer, 0, my_strlen(buffer) - 1);
    free(buffer);
    return line;
}

int loop_1(int ac, char **av, char **env)
{
    char *buffer = NULL;
    env_t *list = copy_env(env);
    char **content = NULL;
    char **tab = NULL;

    data = list;
    signal(SIGINT, handle_signal);
    while (1) {
        print_dir(list);
        buffer = stdin_rec(&list);
        tab = strtowordarray(cleanstr(buffer), ";");
        recup_func(tab, content, list, env);
        free_line(buffer, NULL, NULL, NULL);
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    if (ac == 1) {
        loop_1(ac, av, env);
    } else {
        if (my_strcmp(av[1], "-f") == 0)
            loop_2(ac, av, env);
        if (my_strcmp(av[1], "-t") == 0)
            loop_3(ac, av, env);
        if (my_strcmp(av[1], "-n") == 0)
            loop_4(ac, av, env);
    }
}
