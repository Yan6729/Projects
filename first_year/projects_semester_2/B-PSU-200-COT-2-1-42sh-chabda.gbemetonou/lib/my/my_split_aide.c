/*
** EPITECH PROJECT, 2025
** my_split_aide.c
** File description:
** just a file
*/

#include "../../include/shell.h"

tab_t *create_new(char *string, int is_sep, int len)
{
    tab_t *new = malloc(sizeof(tab_t));

    if (!new)
        return NULL;
    new->string = strndup(string, len);
    new->is_sep = is_sep;
    new->next = NULL;
    return new;
}

void add_tab(tab_t **list, tab_t *new_node)
{
    tab_t *tmp = NULL;

    if (!*list) {
        *list = new_node;
        return;
    }
    tmp = *list;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_node;
}

void decoup_tab(ind_t *cmp, char *str, const char *delim)
{
    if (str[cmp->i] == '\'' || str[cmp->i] == '"') {
        cmp->is_sep = 1;
        cmp->quote = str[cmp->i];
        cmp->i++;
        cmp->start = cmp->i;
        while (str[cmp->i] && str[cmp->i] != cmp->quote)
            cmp->i++;
    } else {
        cmp->quote = 0;
        cmp->start = cmp->i;
        while (str[cmp->i] && !is_delim(str[cmp->i], delim)
        && str[cmp->i] != '\'' && str[cmp->i] != '"')
            cmp->i++;
    }
}

tab_t *str_to_list(char *str, const char *delim)
{
    ind_t cmp = {0};

    while (str[cmp.i]) {
        cmp.is_sep = 0;
        while (str[cmp.i] && is_delim(str[cmp.i], delim)) {
            cmp.i++;
        }
        if (!str[cmp.i])
            break;
        decoup_tab(&cmp, str, delim);
        cmp.len = cmp.i - cmp.start;
        if (cmp.len > 0)
            add_tab(&cmp.list, create_new(&str[cmp.start],
            cmp.is_sep, cmp.len));
        if (cmp.quote && str[cmp.i] == cmp.quote)
            cmp.i++;
    }
    return cmp.list;
}

void free_litb(tab_t *list)
{
    tab_t *tmp;

    while (list) {
        tmp = list->next;
        free(list->string);
        free(list);
        list = tmp;
    }
}
