/*
** EPITECH PROJECT, 2025
** emacs
** File description:
** emacs
*/

#include "../include/my.h"

ign_t *fridge_2(ign_t *list, char *cmd)
{
    char **tab = str_array(cmd, ' ');

    if (strcmp(tab[0], "make") == 0 && (strcmp(tab[1], "pasta") != 0
        && strcmp(tab[1], "pizza") != 0)) {
        my_putchar('\'', 2);
        my_puts(tab[1], 2);
        my_puts("': unknow meel.\n", 2);
        return list;
    }
    if (strncmp(cmd, "addToFridge ", strlen("addToFridge ")) == 0) {
        addtofridge(list, cmd);
        return list;
    }
    if (strcmp(cmd, "make pasta") == 0) {
        make_pasta(list);
        return list;
    }
    if (strcmp(cmd, "make pizza") == 0) {
        make_pizza(list);
        return list;
    }
}

ign_t *fridge(ign_t *list, char *cmd)
{
    if (strcmp(cmd, "exit") == 0) {
        free(cmd);
        save(list);
        free(list);
        exit(0);
    }
    if (strcmp(cmd, "disp fridge") == 0) {
        disp_frigide(list);
        return list;
    }
    fridge_2(list, cmd);
    if (strcmp(cmd, "exit") != 0 && strcmp(cmd, "disp fridge") != 0
        && strncmp(cmd, "make ", strlen("make ")) != 0
        && strncmp(cmd, "addToFridge ", strlen("addToFridge ")) != 0) {
        my_putchar('\'', 2);
        my_puts(cmd, 2);
        my_puts("': Invalid operation\n", 2);
    }
    return list;
}
