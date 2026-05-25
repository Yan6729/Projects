/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** function heart
*/

#include "../B-CPE-200_op/op.h"
#include "../include/robot.h"

void usage(void)
{
    my_puts("USAGE\n");
    my_puts("./asm file_name[.s]\n");
    my_puts("DESCRIPTION\n");
    my_puts("file_name file in assembly language to be converted into");
    my_puts("file_name.cor, an executable in the Virtual Machine.\n");
}

int function(int ac, char **av)
{
    int b;
    int a;
    int file;
    int i = 0;
    struct stat size;

    stat(av[1], &size);
    b = size.st_size;
    if (b == 0)
        return 84;
    file = open(av[1], O_RDONLY);
    if (file <= 0) {
        my_puts_2("Error in function open: No such file or directory.\n");
        return 84;
    }
    i = check_file(av[1]);
    if (i != 0)
        return 84;
}

int main(int ac, char **av)
{
    int a = 0;

    if (ac == 1 || ac > 2) {
        my_puts_2("Usage: ./asm file_name[.s] ...\n");
        return 84;
    }
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        usage();
    } else if (ac == 2 && function(ac, av) != 84) {
        transcrip(av[1]);
    } else
        return 84;
    return a;
}
