/*
** EPITECH PROJECT, 2025
** v_command.c
** File description:
** just a file
*/

#include "../include/shell.h"

void recup_func_2(char *lines, shell_t *tmp, char **env)
{
    alias_t *alist = NULL;
    char **content = NULL;
    char **cont_2 = NULL;

    if (strstr(lines, "$"))
        execute_with_envronment(lines, tmp);
    if (!strstr(lines, ">>") && !strstr(lines, ">") &&
        strcmp(cleanstr(lines, 0), "echo $?") != 0
        && !strstr(lines, "|") && !strstr(lines, "<<")
        && !strstr(lines, "<") && !strstr(lines, "?")
        && !strstr(lines, "*") && !strstr(lines, "[")
        && !strstr(lines, "!") && !strstr(lines, "&&")
        && !strstr(lines, "||") && !strstr(lines, "$")) {
        content = my_split(lines, " \t");
        cont_2 = verify_alias(tmp, content);
        is_builtins_cmd(tmp, cont_2, content, env);
        if (check_build_command(cont_2, &tmp->cmp->hist))
            tmp->status = get_pid(cont_2, env);
    }
    free_line(NULL, NULL, NULL, cont_2);
}

void recup_func(shell_t *tmp, char **env, char *lines)
{
    if (strcmp(cleanstr(lines, 0), "echo $?") == 0) {
        printf("%d\n", tmp->status);
        return;
    }
    if (strstr(lines, "?") || strstr(lines, "*")
        || strstr(lines, "[")) {
        globbings(tmp, lines);
        return;
    }
    if (strstr(lines, "|") && !strstr(lines, "||")) {
        e_w_pipe(tmp, lines, env);
        return;
    }
    recup_func_3(lines, tmp, env);
    if (strstr(lines, "<<")) {
        left_double_redirection(tmp, lines, env);
        return;
    }
    recup_func_2(lines, tmp, env);
}

int check_alpha(char *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if ((str[a] >= 65 && str[a] <= 90) ||
            (str[a] >= 97 && str[a] <= 122) ||
            str[a] == '_' || (str[a] >= 48
            && str[a] <= 57)) {
            continue;
        } else {
            return 1;
        }
    }
    return 0;
}

void is_history(char **tab, char **tab_2, shell_t *tmp, char **env)
{
    if (tab == NULL)
        return;
    if (strcmp(tab[0], "exit") == 0 && tab[1] != NULL) {
        write_list(file_histor(".history_save", env), tmp->cmp->hist);
        print("stderr", "%s: Expression Syntax.\n", tab[0]);
    }
    if (strcmp(tab[0], "history") == 0)
        disp_h(&tmp->cmp->hist);
    is_alias(tab_2, tmp, env);
}

int verify_setenv(char *name)
{
    if (name == NULL)
        return 0;
    for (int a = 0; name[a] != '\0'; a++) {
        if (name[0] >= 48 && name[0] <= 57) {
            print("stderr", "setenv: Variable name must begin ");
            print("stderr", "with a letter.\n");
            return 1;
        }
        if (check_alpha(name) == 1) {
            print("stderr", "setenv: Variable name must contain");
            print("stderr", " alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}
