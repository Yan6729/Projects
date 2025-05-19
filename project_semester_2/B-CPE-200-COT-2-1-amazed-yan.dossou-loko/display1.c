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

int remove_comment(char **line, int i)
{
    int count = 0;

    if (line[i][0] == '#') {
        if (line[i][1] != '#')
            return 1;
        if (line[i][1] == '#')
            return 2;
    }
    return 0;
}

int is_same_r(int i, char **tab, char **tab2)
{
    int count = 0;

    for (int l = 0; tab2[l] != NULL; l++) {
        if (my_strcmp(tab[i], tab2[l]) == 0)
            count++;
    }
    return count;
}
