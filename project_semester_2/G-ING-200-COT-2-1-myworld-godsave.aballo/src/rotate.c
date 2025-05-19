/*
** EPITECH PROJECT, 2025
** rotate.c
** File description:
** just a function
*/

#include "../include/struct.h"

sfVector2f **rotate(int x, int y, int z, double β)
{
    int xB;
    int xO;
    int yB;
    int yO;

    x = (xB - xO) * cos (β) + (yB - yO) * sin (β) + xO;
    y = - (xB - xO) * sin (β) + (yB - yO) * cos (β) + yO;
}

