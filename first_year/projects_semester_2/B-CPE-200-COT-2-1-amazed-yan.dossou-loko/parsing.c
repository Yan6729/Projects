/*
** EPITECH PROJECT, 2025
** a-maze-d
** File description:
** parsing
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

int verif_data(char **recup, int i, int nb)
{
    char **tab;

    if (my_strncmp(recup[i], "#", 1) != 0) {
        tab = my_str_to_word_array(recup[i], ' ');
        if (line(tab, nb) == 84) {
            return 84;
        }
    }
    return 0;
}

char **recup_tab(char *file)
{
    char **tab = NULL;

    tab = my_str_to_word_array(file, '\n');
    for (int i = 0; tab[0][i] != '\0'; i++)
        if (tab[0][i] < '0' || tab[0][i] > '9')
            return NULL;
    return tab;
}

int display(char *filepath)
{
    char **recup = recup_tab(filepath);
    char **tab = NULL;

    if (display1(recup, filepath) == 84)
        return 84;
    for (int i = 1; recup[i] != NULL; i++) {
        if (display2(recup, i) == 84)
            return 84;
    }
}

char *r_stdin(void)
{
    char *buffer = NULL;
    size_t len = 0;
    static char cpy[1024];

    while (getline(&buffer, &len, stdin) != -1) {
        if (!buffer[0])
            return NULL;
        concat_strings(cpy, buffer);
    }
    return my_strdup(cpy);
}

int main(int ac, char **av)
{
    char *filepath = r_stdin();

    if (display(filepath) == 84)
        return 84;
}
