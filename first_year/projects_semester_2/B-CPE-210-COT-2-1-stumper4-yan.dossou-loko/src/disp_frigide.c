/*
** EPITECH PROJECT, 2025
** disp_frigide.c
** File description:
** just a file
*/

#include "../include/my.h"

void disp_frigide(ign_t *frigide)
{
    if (frigide == NULL)
        return;
    for (int a = 0; a < 8; a++) {
        printf("%s = %d\n", frigide[a].name, frigide[a].qut);
    }
}
