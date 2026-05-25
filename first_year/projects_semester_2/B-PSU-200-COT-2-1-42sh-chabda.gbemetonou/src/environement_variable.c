/*
** EPITECH PROJECT, 2026
** B-PSU-200-COT-2-1-42sh-chabda.gbemetonou
** File description:
** environement_variable
*/

#include "../include/shell.h"

void execute_with_envronment(char *lines, shell_t *tmp)
{
    char **tab = my_split(lines, " \t");
    int size = count_arg(tab, 0);
    char **new_tab = malloc(sizeof(char *) * size + 1);

    if (!new_tab)
        return;
    for (int a = 0; tab[a] != NULL; a++) {
        if (!strstr(tab[a], "$")) {
            new_tab[a] = my_strdup(tab[a], 0);
        } else {
            new_tab[a] = my_getenv_list(tmp->list, my_strdup(tab[a], 1));
        }
    }
    new_tab[size] = NULL;
    char **tab_alias = verify_alias(tmp, new_tab);
    is_builtins_cmd(tmp, tab_alias, new_tab, tmp->env);
    if (check_build_command(tab_alias, &tmp->cmp->hist))
        tmp->status = get_pid(tab_alias, tmp->env);
    free_line(NULL, NULL, NULL, new_tab);
    free_line(NULL, NULL, NULL, tab_alias);
}
