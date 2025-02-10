/*
** EPITECH PROJECT, 2024
** rect.c
** File description:
** an intermediar function
*/

#include "struct.h"

sfRectangleShape *rect(int a, int b)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f size = {480, 270};
    sfVector2f pos = {a, b};

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfYellow);
    sfRectangleShape_setOutlineThickness(rect, 1.5);
    return rect;
}

sfRectangleShape *rect_1(file_t cmp, sfColor color)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f size = {20, 20};

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, cmp.pos_p);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, color);
    sfRectangleShape_setOutlineThickness(rect, 1.5);
    return rect;
}
