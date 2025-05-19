/*
** EPITECH PROJECT, 2025
** verify_setenv.c
** File description:
** just a file
*/

#include "../include/mysh.h"

int check_digit(char c)
{
    if (c >= 48 || c <= 57)
        return 0;
    return 1;
}

int check_alpha(char c)
{
    if ((c >= 65 && c <= 90) ||
        (c >= 97 && c <= 122) || c == '_')
        return 0;
    return 1;
}

int verify_setenv(char *name)
{
    for (int a = 0; name[a] != '\0'; a++) {
        if (name[0] >= 48 && name[0] <= 57) {
            my_puts_2("setenv: Variable name must begin with a letter.\n");
            break;
            return 1;
        }
        if (check_digit(name[a]) == 1 || check_alpha(name[a]) == 1) {
            my_puts_2("setenv: Variable name must contain");
            my_puts_2("alphanumeric characters.\n");
            break;
            return 1;
        }
    }
    return 0;
}
