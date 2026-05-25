/*
** EPITECH PROJECT, 2025
** intermediate.c
** File description:
** just a file
*/

#include "../include/shell.h"

char *verify_value_of_alias(alias_t **list, char *value)
{
    alias_t *tmp = *list;

    for (tmp; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->alias, value) == 0) {
            return tmp->value;
        } else {
            continue;
        }
    }
    return value;
}

alias_t *add_alias(char **tab_2, alias_t *list)
{
    char *alias = cleanstr(tab_2[1], 0);
    char *value = NULL;
    char *n_val = NULL;
    char **new_l = NULL;
    char **new_l2 = NULL;
    char *real = NULL;

    if (tab_2[2] == NULL || alias == NULL)
        return list;
    real = concatenate(tab_2, 2);
    new_l = trans_cmd(tab_2[2], tab_2, 3);
    n_val = verify_value_of_alias(&list, new_l[0]);
    new_l2 = trans_cmd(n_val, new_l, 1);
    value = concatenate(new_l2, 0);
    add_b(&list, alias, value, real);
    return list;
}

void print_alias(alias_t *list, char *alias)
{
    alias_t *cmp = list;

    for (cmp; cmp != NULL; cmp = cmp->next) {
        if (strcmp(alias, cmp->alias) == 0)
            print("stdout", "%s\n", cmp->illusion);
    }
}

void is_alias(char **tab, shell_t *tmp, char **env)
{
    if (strcmp(tab[0], "unalias") == 0 && tab[1] != NULL)
        tmp->al = unalias(tmp, tab[1]);
    if (strcmp(tab[0], "alias") == 0 && tab[1] != NULL
        && tab[2] != NULL) {
        tmp->al = add_alias(tab, tmp->al);
        return;
    }
    if (strcmp(tab[0], "alias") == 0 && tab[1] != NULL
        && tab[2] == NULL) {
        print_alias(tmp->al, tab[1]);
        return;
    }
    if (strcmp(tab[0], "alias") == 0 && tab[1] == NULL) {
        disp_b(&tmp->al);
        return;
    }
    if (strcmp(tab[0], "repeat") == 0) {
        repeat(tmp, tab);
        return;
    }
}

void boucle_fun(shell_t *tmp)
{
    change_alias(tmp);
    if (!tmp)
        return;
    for (tmp->a = 0; tmp->tab[tmp->a] != NULL; tmp->a++) {
        recup_func(tmp, tmp->env, tmp->tab[tmp->a]);
    }
    free_line(tmp->buffer, NULL, tmp->tab, NULL);
}
