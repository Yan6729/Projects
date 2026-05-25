/*
** EPITECH PROJECT, 2025
** parenthesis.c
** File description:
** just a file
*/

#include "../../include/shell.h"

void usage(void)
{
    print("stdout", "USAGE:\n");
    print("stdout", "A recoding of a unix C encoding shell:\n");
    print("stdout", "    -n\ta shell who made nothing\n");
    print("stdout", "    -t\ta shell who made execution only one time\n");
    print("stdout", "    -f\ta shell who made execution but the prompt ");
    print("stdout", "was different\n", 1);
    print("stdout", "    the shell was only closing by \"Ctrl + D\"");
    print("stdout", "or \"exit\"\n");
}

int verifiparatheseis(char *str)
{
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            j++;
        if (str[i] == ')')
            j--;
    }
    if (j == 0)
        return 1;
    return 0;
}

void my_parentheseis(shell_t *tmp, char **env)
{
    char **table = NULL;

    if (verifiparatheseis(tmp->buffer) == 0) {
        my_puts("Syntax error: unmatched parentheses\n", 2);
        return;
    }
    table = my_strtok(cleanstr(tmp->buffer, 0), "()");
    for (int a = 0; table[a] != NULL; a++) {
        tmp->tab = strtowordarray(tmp->buffer, ";");
        boucle_fun(tmp);
    }
}
