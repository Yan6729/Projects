/*
** EPITECH PROJECT, 2025
** step4.c
** File description:
** just the step4 of the bootstrap
*/

#include "my.h"

int count_arg(int ac, char **av, char **env)
{
    int b = 0;
    char **tab = my_strwrldarray(av[1]);

    for (int a = 0; tab[a] != NULL; a++)
        b++;
    return (b - 1);
}

int get_pid(int ac, char **av, char **env)
{
    char **tab = my_strwrldarray(av[1]);
    int a = fork();
    int pid[2] = {0, 0};
    int statut;

    if (a == -1)
        exit(84);
    if (a != 0) {
        my_puts("PID: ");
        my_put_nbr(pid[0] = getpid());
    } else {
        my_puts("\nChild PID: ");
        my_put_nbr(pid[1] = getpid());
        my_putchar('\n');
        if (execve(tab[0], tab, env) == -1)
            exit(84);
    }
    waitpid(pid[1], &statut, 0);
    return statut;
}

int main(int ac, char **av, char **env)
{
    int d;
    int a = count_arg(ac, av, env);
    char **tab = my_strwrldarray(av[1]);

    my_puts("Program name: ");
    my_puts(tab[0]);
    my_putchar('\n');
    my_puts("Nb args: ");
    my_put_nbr(a);
    my_putchar('\n');
    d = get_pid(ac, av, env);
    my_puts("Program terminated.\n");
    if (WIFEXITED(d))
        my_puts("Status: OK\n");
    else if (WIFSIGNALED(d))
        my_puts("Status: Segmentation fault\n");
}
