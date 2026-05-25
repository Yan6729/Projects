/*
** EPITECH PROJECT, 2025
** emacs
** File description:
** emacs
*/

#include "../include/my.h"

int tab_len(char **tab)
{
    int a = 0;

    for (; tab[a] != NULL; a++);
    return a;
}
