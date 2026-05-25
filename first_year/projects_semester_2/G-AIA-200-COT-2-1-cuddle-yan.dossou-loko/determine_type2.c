/*
** EPITECH PROJECT, 2025
** determine_type2.c
** File description:
** just a file
*/

#include "include/dataframe.h"

int check_num_of_point(char *str)
{
    int b = 0;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == '.')
            b++;
    }
    return b;
}

int is_float(char *str)
{
    if (check_num_of_point(str) != 1)
        return 0;
    for (int a = 0; str[a] != '\0'; a++) {
        if ((str[a - 1] >= 48 && str[a - 1] <= 57) && str[a] == '.' &&
        (str[a + 1] >= 48 && str[a + 1] <= 57)) {
        return 1;
        }
    }
    return 0;
}

int is_boal(char *str)
{
    if (strcmp(str, "true") || strcmp(str, "false")) {
        return 1;
    }
    return 0;
}
