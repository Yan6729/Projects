/*
** EPITECH PROJECT, 2025
** sort_word.c
** File description:
** solo stumper function
*/

#include "my.h"

char *sort_word(int ac, char **av)
{
    char **str = my_strwrdarray(av[1]);
    int a = 0;
    int b = 1;

    for (a = 0; str[a] != NULL && str[b] != NULL; a++, b++) {
	if (my_strcmp(str[a], str[b]) == -1) {
            my_putstr(str[a]);
            my_putchar(' ');
            my_putstr(str[b]);
        }
    }
    my_putchar('\n');
}

int main(int ac, char **av)
{
    sort_word(ac, av);
}
