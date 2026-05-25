/*
** EPITECH PROJECT, 2025
** destroy.c
** File description:
** just a file
*/

#include "../include/struct.h"

void draw_2(sfRenderWindow *window, sfSprite *background_1,
    sfSprite *start)
{
    sfRenderWindow_drawSprite(window, background_1, NULL);
    sfRenderWindow_drawSprite(window, start, NULL);
}

void destroy_1(sfSprite *background_1, sfSprite *start)
{
    sfSprite_destroy(background_1);
    sfSprite_destroy(start);
}
