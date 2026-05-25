/*
** EPITECH PROJECT, 2025
** bash_file_2.c
** File description:
** just a file
*/

#include "../../include/shell.h"

int in_list(alias_t **list, char *alias)
{
    alias_t *tmp = NULL;

    for (tmp = *list; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->alias, alias) == 0)
            return 1;
    }
    return 0;
}

void add_b(alias_t **list, char *alias, char *value, char *real)
{
    alias_t *tmp = *list;

    for (tmp; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->alias, alias) == 0) {
            tmp->value = my_strdup(value, 0);
            tmp->value[strlen(value)] = '\0';
            tmp->illusion = my_strdup(real, 0);
            return;
        } else {
            continue;
        }
    }
    add_bash(list, alias, value, real);
    return;
}

void refresh_illusion(alias_t **list, char *alias, char *value)
{
    char **str = NULL;
    alias_t *tmp = *list;
    char **str2 = NULL;

    for (tmp; tmp != NULL; tmp = tmp->next) {
        str = my_split(tmp->illusion, " \t");
        if (strcmp(str[0], alias) == 0) {
            str2 = trans_cmd(value, str, 1);
            tmp->value = my_strdup(concatenate(str2, 0), 0);
        } else {
            continue;
        }
    }
    free_line(NULL, NULL, str, str2);
}

void change_alias(shell_t *tmp)
{
    alias_t *cmp = tmp->al;

    for (cmp; cmp != NULL; cmp = cmp->next) {
        refresh_illusion(&cmp, cmp->alias, cmp->value);
    }
}
