/*
** EPITECH PROJECT, 2025
** strtok
** File description:
** strtok
*/

#include "../../include/shell.h"

int my_countspeaceword(char *str)
{
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == ';' || str[i] == '\t'
        || str[i] == ':' || str[i] == '=' || str[i] == '|'
        || str[i] == '<' || str[i] == '>' || str[i] == '`'
        || str[i] == '(' || str[i] == ')')
            j++;
    }
    if (str[i] == '\0')
        j++;
    return j + 1;
}

char **my_strtok(char *str, char *separator)
{
    char *finalstr = NULL;
    char **table = NULL;
    int i = 0;
    char *clonestr = NULL;

    table = malloc(sizeof(char *) * my_countspeaceword(str));
    clonestr = strdup(str);
    finalstr = strtok(clonestr, separator);
    while (finalstr != NULL) {
        table[i] = finalstr;
        finalstr = strtok(NULL, separator);
        i++;
    }
    table[i] = NULL;
    return table;
}
