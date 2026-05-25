/*
** EPITECH PROJECT, 2025
** my_strstr.c
** File description:
** a system function
*/

#include "../../include/mysh.h"

char *my_strstr(char *str, char *to_find)
{
    int a = 0;
    int b = 0;

    for (a = 0; str[a] != '\0'; a++) {
        for (b = 0; to_find[b] && str[a + b] && str[a + b] == to_find[b]; b++);
        if (to_find[b] == '\0') {
            return (&str[a]);
        } else {
            b = 0;
        }
    }
    return NULL;
}
