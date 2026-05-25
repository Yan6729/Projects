/*
** EPITECH PROJECT, 2025
** addtofridge.c
** File description:
** just a file
*/

#include "../include/my.h"

ign_t *addtofridge(ign_t *frigide, char *cmp)
{
    char **tab = str_array(cmp, ' ');
    int nb = 0;

    if (frigide == NULL || tab == NULL || tab[2] == NULL)
        return frigide;
    nb = atoi(tab[2]);
    if (nb < 0)
        return frigide;
    for (int i = 0; i < 8; i++) {
        if (strcmp(frigide[i].name, tab[1]) == 0) {
            frigide[i].qut += nb;
            return frigide;
        }
    }
    my_putchar('\'', 2);
    my_puts(cmp, 2);
    my_puts("': Invalid operation\n", 2);
    return frigide;
}
