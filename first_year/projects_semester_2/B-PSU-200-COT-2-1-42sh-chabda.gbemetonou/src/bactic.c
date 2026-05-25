/*
** EPITECH PROJECT, 2025
** inibitor
** File description:
** inibitor
*/

#include "../include/shell.h"

char *putslashzero(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = ' ';
            continue;
        }
    }
    str[i - 1] = '\0';
    return cleanstr(str, 0);
}

env_t *conditioninibitor(char *str, env_t *list, char *name, FILE *cmd_output)
{
    env_t *current = list;
    char *newline = NULL;

    if (str != NULL) {
        cmd_output = popen(str, "r");
        if (cmd_output != NULL) {
            char result[1024] = {0};
            read(fileno(cmd_output), result, sizeof(result));
            pclose(cmd_output);
            newline = putslashzero(result);
            return my_setenv(list, name, newline);
        }
    }
}

char *execute_backtick_command(char *cmd, char **env)
{
    FILE *pipe;
    char result[4096] = {0};
    char *newstr = NULL;

    pipe = popen(cmd, "r");
    if (!pipe)
        return NULL;
    read(fileno(pipe), result, sizeof(result));
    pclose(pipe);
    newstr = putslashzero(result);
    if (newstr == NULL)
        return NULL;
    return my_strndup(newstr, 0, strlen(newstr));
}

int my_inibitor(shell_t *tmp, char *str, char **env)
{
    int a = 0;

    if (strchr(str, '`') != NULL) {
        char **priori = my_strtok(cleanstr(str, 0), "`");
        int nb_parts = 0;
        for (nb_parts = 0; priori[nb_parts] != NULL; nb_parts++);
        char *new_cmd = my_strdup(priori[0], 0);
        
        for (int i = 1; i < nb_parts; i += 2) {
            if (priori[i] && strlen(priori[i]) > 0) {
                char *cmd_output = execute_backtick_command(priori[i], env);
                char *temp = new_cmd;
                new_cmd = malloc(sizeof(char) * (strlen(temp) + strlen(cmd_output) + 1));
                strcpy(new_cmd, temp);
                strcat(new_cmd, cmd_output);
                if (priori[i+1]) {
                    temp = new_cmd;
                    new_cmd = malloc(sizeof(char) * (strlen(temp) + strlen(priori[i+1]) + 1));
                    strcpy(new_cmd, temp);
                    strcat(new_cmd, priori[i+1]);
                }
            }
        }
        char **table = strtowordarray(cleanstr(new_cmd, 0), ";");
        history_t *hist = NULL;
        env_t *list = copy_env(env);
        for (int a = 0; table[a] != NULL; a++) {
            recup_func(tmp, env, table[a]);
        }
        return 1;
    }
    return 0;
}
