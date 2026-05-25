/*
** EPITECH PROJECT, 2025
** checl_job_control.c
** File description:
** just a file
*/

#include "../include/shell.h"

int arr_size(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return i;
}

int check_job_control(char **tab)
{
    int nb = arr_size(tab) - 1;

    if (tab[nb][0] == '&') {
        tab[nb] = NULL;
        return 1;
    }
    return 0;
}
