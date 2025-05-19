/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** error
*/

#include <stdio.h>
#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int is_int(char **tab, int i)
{
    int count = 0;

    for (int l = 0; tab[i][l] != '\0'; l++) {
        if (tab[i][l] >= '0' && tab[i][l] <= '9')
            count++;
        else
            count = 0;
    }
    return count;
}

int line(char **tab, int nb)
{
    int i = 0;
    int count = 0;
    int integer = 0;

    for (i = 0; tab[i] != NULL; i++) {
        if (remove_comment(tab, i) == 1)
            continue;
        count++;
        integer = is_int(tab, i);
        if (integer != my_strlen(tab[i]))
            return 84;
    }
    if (count != nb)
        return 84;
    return 0;
}

int error_tunnel(char **tab, int i)
{
    int integer = 0;
    int count = 0;
    char **recup = NULL;

    for (int j = 0; tab[i][j] != '\0'; j++) {
        if (tab[i][j] == '-') {
            count++;
        }
    }
    if (count != 1)
        return 84;
    return 0;
}
