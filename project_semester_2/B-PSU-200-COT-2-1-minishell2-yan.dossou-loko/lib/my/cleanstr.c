/*
** EPITECH PROJECT, 2025
** fghj
** File description:
** fgh
*/

#include "../../include/mysh.h"

int my_is_sep(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\f')
        return 1;
    else
        return 0;
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

char *cleanstr(char *input)
{
    int i = 0;
    int j = 0;

    if (input == NULL)
        return NULL;
    input_man(input, i);
    for (i = 0; my_is_sep(input[i]); i++);
    for (; input[i] != '\0'; i++) {
        if (my_is_sep(input[i])) {
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
