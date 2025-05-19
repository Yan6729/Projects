/*
** EPITECH PROJECT, 2025
** determine_type.c
** File description:
** just a file
*/

#include "include/dataframe.h"

int is_int(char *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if (isdigit(str[a])) {
            continue;
        } else {
            return 0;
        }
    }
    return 1;
}

int is_int_2(char *str)
{
    for (int a = 1; str[a] != '\0'; a++) {
        if (str[0] == '-' && isdigit(str[a])) {
            continue;
        } else {
            return 0;
        }
    }
    return 1;
}

int check_digit(char *str)
{
    int b = 0;

    for (int a = 0; str[a] != '\0'; a++) {
        if (isdigit(str[a])) {
            b++;
        }
    }
    return b;
}

int check_alpha_other(char *str)
{
    int b = 0;

    for (int a = 0; str[a] != '\0'; a++) {
        if (isalpha(str[a]) || isspace(str[a])) {
            b++;
        }
    }
    return b;
}

int is_string(char *str)
{
    int a = check_alpha_other(str);
    int b = check_digit(str);
    int c = check_num_of_point(str);

    if (strcmp(str, "true") == 0 || strcmp(str, "false") == 0) {
        return 0;
    }
    if (c >= 2) {
        return 1;
    }
    if ((a != 0 && b == 0) || (a != 0 && b != 0)) {
        return 1;
    }
    return 0;
}
