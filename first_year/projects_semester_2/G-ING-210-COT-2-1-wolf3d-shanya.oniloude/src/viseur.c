/*
** EPITECH PROJECT, 2025
** vi
** File description:
** seur
*/

#include "../include/wolf3d_2.h"
void draw_crosshair(sfRenderWindow *window)
{
    sfRectangleShape *vert = sfRectangleShape_create();
    sfRectangleShape *horz = sfRectangleShape_create();
    sfVector2f center = {WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f};

    sfRectangleShape_setSize(vert, (sfVector2f){2, 20});
    sfRectangleShape_setFillColor(vert, sfWhite);
    sfRectangleShape_setPosition(vert, (sfVector2f)
    {center.x - 1, center.y - 10});
    sfRectangleShape_setSize(horz, (sfVector2f){20, 2});
    sfRectangleShape_setFillColor(horz, sfWhite);
    sfRectangleShape_setPosition(horz, (sfVector2f)
    {center.x - 10, center.y - 1});
    sfRenderWindow_drawRectangleShape(window, vert, NULL);
    sfRenderWindow_drawRectangleShape(window, horz, NULL);
    sfRectangleShape_destroy(vert);
    sfRectangleShape_destroy(horz);
}
