/*
** EPITECH PROJECT, 2025
** fghj
** File description:
** fgh
*/

#include "../../include/shell.h"

int my_is_sep(char c, int choice)
{
    if (choice == 0) {
        if (c == ' ' || c == '\t' || c == '\n' || c == '\f')
            return 1;
        else
            return 0;
    }
    if (choice == 1) {
        if (c == '!')
            return 1;
        else
            return 0;
    }
}

char *input_man(char *input, int i)
{
    while (input[i] != '\0') {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
        i++;
    }
}

void intercept(char *input, int i, int *j)
{
    if (*j > 0 && input[*j - 1] != ' ') {
        input[*j] = ' ';
        (*j)++;
    }
}

char *cleanstr(char *input, int choice)
{
    int i = 0;
    int j = 0;

    if (input == NULL)
        return NULL;
    input_man(input, i);
    for (i = 0; my_is_sep(input[i], choice); i++);
    for (; input[i] != '\0'; i++) {
        if (my_is_sep(input[i], choice)) {
            intercept(input, i, &j);
        } else {
            input[j] = input[i];
            j++;
        }
    }
    if (j > 0 && input[j - 1] == ' ')
        j--;
    input[j] = '\0';
    return input;
}
