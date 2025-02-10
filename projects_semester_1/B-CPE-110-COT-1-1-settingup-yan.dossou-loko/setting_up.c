/*
** EPITECH PROJECT, 2024
** setting_up.c
** File description:
** function taht open and read a file
*/
#include <unistd.h>
#include "my.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

char **setting_up(int ac, char **av)
{
    char **str;
    char **src;

    if (ac == 2) {
        str = my_open_file(ac, av);
        return str;
    } else if (ac == 3) {
        src = generator(ac, av);
        return src;
    }
}

int main(int ac, char **av)
{
    int a;
    char **stc = setting_up(ac, av);
    int file;
    char d[45] = "Sorry, this file doesn't exist\n";

    if (ac == 1)
        return 84;
    file = open(av[1], O_RDONLY);
    if (file <= 0) {
        write(1, d, 45);
        return 84;
    }
    for (a = 0; stc[a] != NULL; a++)
        my_putstr(stc[a]);
    for (a = 0; stc[a] != NULL; a++)
        free(stc[a]);
}
