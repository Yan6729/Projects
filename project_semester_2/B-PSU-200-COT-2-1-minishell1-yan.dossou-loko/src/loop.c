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
    char *line;

    for (int a = 0; a < 1; a++) {
        buffer = stdin_rec(&list);
        line = my_strndup(buffer, 0, my_strlen(buffer) - 1);
        content = strtowordarray(line, " \t");
        if (!content || !content[0])
            continue;
        is_builtins_cmd(content, &list, env);
        if (check_build_command(content))
            get_pid(content, env);
        free_line(NULL, line, content);
    }
    free_list(list);
    return EXIT_SUCCESS;
}

int loop_2(int ac, char **av, char **env)
{
    char *buffer = NULL;
    env_t *list = copy_env(env);
    char **content = NULL;
    char *line;

    while (1) {
        my_puts("> ");
        buffer = stdin_rec(&list);
        line = my_strndup(buffer, 0, my_strlen(buffer) - 1);
        content = strtowordarray(line, " \t");
        if (!content || !content[0])
            continue;
        is_builtins_cmd(content, &list, env);
        if (check_build_command(content))
            get_pid(content, env);
        free_line(NULL, line, content);
    }
    free_list(list);
    return 0;
}

int loop_4(int ac, char **av, char **env)
{
    env_t *list = copy_env(env);
    char *buffer;
    char **content;

    while (1) {
        my_puts("> ");
        buffer = stdin_rec(&list);
    }
    free(buffer);
}
