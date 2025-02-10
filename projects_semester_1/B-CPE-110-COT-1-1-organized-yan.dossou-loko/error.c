/*
** EPITECH PROJECT, 2024
** error.c
** File description:
** error case gestionary
*/

#include "shell.h"
#include <string.h>
#include <stdlib.h>

int error(char *str, char *src)
{
    char *str1 = "ACTUATOR";
    char *str2 = "DEVICE";
    char *str3 = "SENSOR";
    char *str4 = "WIRE";
    char *str5 = "PROCESSOR";

    if (my_strcmp2(str, str1) == 0 ||
        my_strcmp2(str, str2) == 0 ||
        my_strcmp2(str, str3) == 0)
        return 1;
    if (my_strcmp2(str, str4) == 0 ||
        my_strcmp2(str, str5) == 0 ||
        src != NULL || src[0] != '\0' || src[0] != ' ')
        return 1;
    else
        return 0;
}

int error_two(char *str)
{
    char *str1 = "TYPE";
    char *str2 = "ID";
    char *str3 = "NAME";

    if (my_strcmp2(str, str1) == 0 ||
        my_strcmp2(str, str2) == 0 ||
        my_strcmp2(str, str3) == 0)
        return 1;
    else
        return 0;
}
