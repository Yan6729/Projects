/*
** EPITECH PROJECT, 2024
** circle.c
** File description:
** an intermediar function
*/

#include "struct.h"

sfCircleShape *circle(double a, double b, double d)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f pos = {a + 15 - d, b + 15 - d};

    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setRadius(circle, d);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfCyan);
    sfCircleShape_setOutlineThickness(circle, 0.8);
    return circle;
}

sfCircleShape *circle_2(double a, double b, double d)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f pos = {a - (d / 7), b - (d / 8)};

    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setRadius(circle, d);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 0.8);
    return circle;
}
