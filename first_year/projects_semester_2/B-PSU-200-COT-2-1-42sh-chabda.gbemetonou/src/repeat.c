/*
** EPITECH PROJECT, 2025
** repeat.c
** File description:
** just a function
*/

#include "../include/shell.h"

int verify_alias_2(alias_t **list, char *illusion)
{
    alias_t *tmp = *list;

    for (tmp; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->illusion, illusion) == 0) {
            return 1;
        } else {
            continue;
        }
    }
    return 0;
}

int verifie(shell_t *tmp, char *lines)
{
    char **tab = my_split(lines, " \t");
    char **n_val = verify_alias(tmp, tab);

    printf("alias:%s\nvalue:%s\n", tab[0], n_val[0]);
    if (verify_illusion(&tmp->al, strtowordarray(tab[0], " \t")[0]) == 1) {
        if (verify_alias_2(&tmp->al,
            strtowordarray(n_val[0], " \t")[0]) == 1) {
            print("stderr", "Alias loop.\n");
            return 1;
        }
    }
    return 0;
}

char *concatenate(char **tab, int ind)
{
    char *path = malloc(sizeof(char) * 1024);

    strcpy(path, tab[ind]);
    for (int a = ind + 1; tab[a] != NULL; a++) {
        strcat(path, " ");
        strcat(path, tab[a]);
    }
    return path;
}

int check_digit(char *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if (!isdigit(str[a])) {
            return 1;
        }
    }
    return 0;
}

void repeat(shell_t *tmp, char **tab)
{
    char **cmd = NULL;
    char *lines = NULL;
    int nb = 0;
    int a = 0;
    int nb2 = count_arg(tab, 0);

    if (nb2 < 3) {
        print("stderr", "%s: Too few arguments.\n", cleanstr(tab[0], 0));
        return;
    }
    if (check_digit(cleanstr(tab[1], 0)) == 1) {
        print("stderr", "%s: Badly formed number.\n", cleanstr(tab[0], 0));
        return;
    }
    cmd = trans_cmd(tab[2], tab, 3);
    nb = count_arg(cmd, 0);
    cmd[nb] = NULL;
    lines = concatenate(cmd, 0);
    for (a; a < atoi(cleanstr(tab[1], 0)); a++)
        recup_func(tmp, cmd, lines);
}
