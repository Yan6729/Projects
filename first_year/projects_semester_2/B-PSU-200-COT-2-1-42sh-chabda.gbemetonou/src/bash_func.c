/*
** EPITECH PROJECT, 2024
** Elementary
** File description:
** Map from file.
*/

#include "../include/shell.h"

void del_al(alias_t *current, alias_t **list, alias_t *prev)
{
    if (prev) {
        prev->next = current->next;
    } else {
        *list = current->next;
    }
    if (current->alias) {
        free(current->alias);
        current->alias = NULL;
    }
    if (current->value) {
        free(current->value);
        current->value = NULL;
    }
    free(current);
}

alias_t *unalias(shell_t *tmp, char *name)
{
    alias_t *current = tmp->al;
    alias_t *prev = NULL;

    while (current) {
        if (current->alias && name && strcmp(current->alias, name) == 0) {
            del_al(current, &tmp->al, prev);
            break;
        }
        prev = current;
        current = current->next;
    }
    return tmp->al;
}

char **trans_cmd(char *str, char **tab_2, int nb)
{
    char **tab_1 = strtowordarray(str, " ");
    int n = 0;
    int n_2 = 0;
    int c = 0;

    n = count_arg(tab_2, nb);
    n_2 = count_arg(tab_1, 0);
    tab_1 = realloc(tab_1, sizeof(char *) * (n + n_2 + 1));
    c = n_2;
    for (int a = nb; tab_2[a] != NULL; a++) {
        tab_1[c] = tab_2[a];
        c++;
    }
    tab_1[n_2 + n] = NULL;
    return tab_1;
}

char **verify_alias(shell_t *tmp, char **tab)
{
    int b = 0;
    char **cont;
    alias_t *list = NULL;

    for (list = tmp->al; list != NULL; list = list->next) {
        if (list->alias && tab[0] && strcmp(list->alias, tab[0]) == 0) {
            cont = trans_cmd(list->value, tab, 1);
            break;
        } else {
            cont = tab;
        }
    }
    return cont;
}

void free_al(alias_t *al)
{
    alias_t *current = al;
    alias_t *next = NULL;

    if (al == NULL)
        return;
    for (current; current != NULL; current = next) {
        next = current->next;
        if (current->alias != NULL) {
            free(current->alias);
            current->alias = NULL;
        }
        if (current->value != NULL && current->illusion != NULL) {
            free(current->value);
            free(current->illusion);
            current->value = NULL;
            current->illusion = NULL;
        }
        free(current);
    }
}
