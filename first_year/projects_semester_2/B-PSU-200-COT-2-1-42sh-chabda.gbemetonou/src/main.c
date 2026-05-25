/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** that's my main function
*/

#include "../include/shell.h"

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

char *freer_writer(int ret, editor_t *editor)
{
    if (ret == 1)
        write(STDOUT_FILENO, "\n", 1);
    if (ret == -1) {
        free(editor->line);
        free(editor);
        return NULL;
    }
}

char *stdin_rec(shell_t *tmp, char *filename)
{
    dec_t cmp;
    editor_t *editor = init_line_editor(tmp->cmp);

    if (!editor)
        return NULL;
    editor->history_data = tmp->cmp;
    editor->current_history = NULL;
    enable_raw_mode();
    cmp.ret = process_keypress(editor);
    while (cmp.ret == 0) {
        refresh_line(editor);
        cmp.ret = process_keypress(editor);
    }
    disable_raw_mode();
    freer_writer(cmp.ret, editor);
    write_list(filename, tmp->cmp->hist);
    cmp.line = strdup(editor->line);
    free(editor->line);
    free(editor);
    return cmp.line;
}

int loop_1(int ac, char **av, char **env)
{
    shell_t *tmp = rempli_struct(ac, av, env);
    char *clone = NULL;

    data = tmp->list;
    signal(SIGINT, handle_signal);
    if (tmp->cmp->count)
        tmp->num = tmp->cmp->count + 1;
    separation_bash(&tmp->al, ".42shrc", env);
    while (1) {
        print_dir(tmp->list);
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

int main(int ac, char **av, char **env)
{
    if (ac == 1) {
        loop_1(ac, av, env);
    } else {
        if (strcmp(av[1], "-h") == 0)
            usage();
        if (strcmp(av[1], "-f") == 0)
            loop_2(ac, av, env);
        if (strcmp(av[1], "-t") == 0)
            loop_3(ac, av, env);
        if (strcmp(av[1], "-n") == 0)
            loop_4(ac, av, env);
        if (!strcmp(av[1], "-h") && !strcmp(av[1], "-f") &&
            !strcmp(av[1], "-t") && !strcmp(av[1], "-n"))
            exit(84);
    }
}
