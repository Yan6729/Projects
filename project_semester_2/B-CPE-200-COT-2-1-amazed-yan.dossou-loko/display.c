/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** dispay
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

int display1(char **recup, char *filepath)
{
    int count = 0;
    int count2 = 0;
    int count1 = 0;

    if (recup == NULL)
        return 84;
    if (is_int(recup, 0) != my_strlen(recup[0]))
        return 84;
    for (int i = 1; recup[i] != NULL; i++) {
        if ((my_strcmp(recup[i], "##start") == 0)
        && (verif_data(recup, i + 1, 3) != 84))
            count1++;
        if (my_strcmp(recup[i], "##end") == 0
        && (verif_data(recup, i + 1, 3) != 84))
            count++;
        if (verif_data(recup, i, 3) != 84)
            count2++;
    }
    if (count1 != 1 || count != 1 || count2 == 0)
        return 84;
}

int verif_id1(char **tab, char **tab1, int i)
{
    int count = 0;

    for (int l = 0; tab1[l] != NULL; l++) {
        if (my_strcmp(tab1[l], tab[i]) == 0)
            count++;
    }
    if (count != 1)
        return 84;
    return 0;
}

int verif_id(char **tab, char **tab1)
{
    int count = 0;

    for (int l = 0; tab[l] != NULL; l++) {
        if (remove_comment(tab, l) == 1)
            continue;
        count = verif_id1(tab, tab1, l);
        if (count == 84)
            return 84;
    }
    return 0;
}

int error_tunnel2(char **tab)
{
    for (int l = 0; tab[l] != NULL; l++) {
        if (error_tunnel(tab, l) == 84)
            return 84;
    }
    return 0;
}

int display2(char **recup, int i)
{
    char **tab = NULL;
    char **tab1 = NULL;
    int integer = 0;
    int count = 0;

    if (verif_data(recup, i, 3) != 84) {
        if (recup[i][0] == '#')
            i++;
        else {
            tab = my_str_to_word_array(recup[i], ' ');
            tab1 = my_str_to_word_array(recup[i], ' ');
            if (verif_id(tab, tab1) == 84)
                return 84;
        }
    } else {
        tab = my_str_to_word_array(recup[i], ' ');
        if (error_tunnel2(tab) == 84)
            return 84;
    }
}
