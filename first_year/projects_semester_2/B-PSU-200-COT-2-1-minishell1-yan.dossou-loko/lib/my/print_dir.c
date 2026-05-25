/*
** EPITECH PROJECT, 2025
** print_dir.c
** File description:
** just a function
*/

#include "../../include/mysh.h"

void print_dir(int ac, char **av, char **env)
{
    char src[UCHAR_MAX];
    char *str;

    if (isatty(0)) {
        str = getcwd(src, UCHAR_MAX);
        if (str == NULL)
            exit(84);
        my_puts("\033[1;34m");
        my_puts(str);
        my_puts("\033[1;37m");
        my_puts("$> ");
        my_puts("\033[0;37m");
    }
}
