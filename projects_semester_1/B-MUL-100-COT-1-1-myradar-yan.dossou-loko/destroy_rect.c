/*
** EPITECH PROJECT, 2024
** destroy_rect.c
** File description:
** destroy_rect.c
*/

#include "struct.h"

void des_left(sfRenderWindow *window, sfEvent event)
{
    sfRectangleShape **Left = left(window, event);

    sfRectangleShape_destroy(Left[0]);
    sfRectangleShape_destroy(Left[1]);
    sfRectangleShape_destroy(Left[2]);
    sfRectangleShape_destroy(Left[3]);
    free(Left);
}

void des_right(sfRenderWindow *window, sfEvent event)
{
    sfRectangleShape **Right = right(window, event);

    sfRectangleShape_destroy(Right[0]);
    sfRectangleShape_destroy(Right[1]);
    sfRectangleShape_destroy(Right[2]);
    sfRectangleShape_destroy(Right[3]);
    free(Right);
}

void des_mright(sfRenderWindow *window, sfEvent event)
{
    sfRectangleShape **Mright = middle_r(window, event);

    sfRectangleShape_destroy(Mright[0]);
    sfRectangleShape_destroy(Mright[1]);
    sfRectangleShape_destroy(Mright[2]);
    sfRectangleShape_destroy(Mright[3]);
    free(Mright);
}

void des_mleft(sfRenderWindow *window, sfEvent event)
{
    sfRectangleShape **Mleft = middle_l(window, event);

    sfRectangleShape_destroy(Mleft[0]);
    sfRectangleShape_destroy(Mleft[1]);
    sfRectangleShape_destroy(Mleft[2]);
    sfRectangleShape_destroy(Mleft[3]);
    free(Mleft);
}

void des_rec(sfRenderWindow *window, sfEvent event)
{
    des_mleft(window, event);
    des_mright(window, event);
    des_right(window, event);
    des_left(window, event);
}
