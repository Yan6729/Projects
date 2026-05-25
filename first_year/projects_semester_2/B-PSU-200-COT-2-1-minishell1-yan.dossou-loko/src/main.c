/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** that's my main function
*/

#include "../include/mysh.h"

void free_list(env_t *env)
{
    env_t *tmp = env;

    for (tmp; tmp != NULL; tmp = tmp->next) {
        free(tmp->name);
        free(tmp->value);
        free(tmp);
    }
}

char *stdin_rec(env_t **list)
{
    char *buffer = NULL;
    size_t size = 0;

    if (getline(&buffer, &size, stdin) == -1) {
        free_list(*list);
        my_puts("exit\n");
        exit(EXIT_SUCCESS);
    }
    return buffer;
}

int loop_1(int ac, char **av, char **env)
{
    char *buffer = NULL;
    env_t *list = copy_env(env);
    char **content = NULL;
    char *line;

    while (1) {
        print_dir(ac, av, env);
        buffer = stdin_rec(&list);
        line = my_strndup(buffer, 0, my_strlen(buffer) - 1);
        content = strtowordarray(line, " \t");
        if (!content || !content[0])
            continue;
        is_builtins_cmd(content, &list, env);
        if (check_build_command(content))
            get_pid(content, env);
        free_line(buffer, line, content);
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
