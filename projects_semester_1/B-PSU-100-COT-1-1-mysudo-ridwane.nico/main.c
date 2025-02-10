/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main
*/

#include "my.h"
void usage(int ac, char **av)
{
    printf("   usage: ./my_sudo -h\n");
    printf("   usage: ./my_sudo [-ugEs] [command [args ...]]\n");
}

int main(int ac, char **av)
{
    if (ac > 3 && strcmp(av[1], "-u") == 0)
        user_command(av[2], av[3], &av[3]);
    if (ac > 3 && strcmp(av[1], "-g") == 0)
        grp_command(av[2], av[3], &av[3]);
    if ((ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && !av[1][2])) {
        usage(ac, av);
    } else if (ac == 1) {
        printf("   usage: ./my_sudo -h\n");
        return 84;
    } else {
        exec(av);
    }
}
