/*
** EPITECH PROJECT, 2025
** emacs
** File description:
** emacs
*/

#include "../include/my.h"

int good_ingr(char *ing)
{
    if (strcmp(ing, "tomato") == 0 || strcmp(ing, "dough") == 0 ||
        strcmp(ing, "onion") == 0 || strcmp(ing, "pasta") == 0 ||
        strcmp(ing, "olive") == 0 || strcmp(ing, "pepper") == 0 ||
        strcmp(ing, "ham") == 0 || strcmp(ing, "cheese") == 0)
        return 1;
    return 0;
}

int possible_errors(char **sub_tab, char **tab)
{
    if (tab_len(sub_tab) != 2) {
        free_tab(tab);
        free_tab(sub_tab);
        exit(84);
    }
    if (good_ingr(sub_tab[0]) != 1 || atoi(sub_tab[1]) < 0) {
        free_tab(tab);
        free_tab(sub_tab);
        exit(84);
    }
    return 0;
}

ign_t *create_list(ign_t *list)
{
    char *buf = open_file(".save");
    char **tab = str_array(buf, '\n');
    int len = tab_len(tab);
    char **sub_tab = NULL;
    int b = 0;

    if (len != 8) {
        free_tab(tab);
        exit(84);
    }
    for (int a = 0; tab[a] != NULL; a++) {
        sub_tab = tab_list(tab[a], 3, "=");
        possible_errors(sub_tab, tab);
        list[b].name = strdup(sub_tab[0]);
        list[b].qut = atoi(sub_tab[1]);
        b++;
        free_tab(sub_tab);
    }
    return list;
}
