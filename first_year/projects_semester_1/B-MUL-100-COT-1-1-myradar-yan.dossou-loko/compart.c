/*
** EPITECH PROJECT, 2024
** right_rect.c
** File description:
** an intermediar function
*/

#include "struct.h"

sfRectangleShape **left(sfRenderWindow *window, sfEvent event)
{
    sfRectangleShape *rec_1 = rect(0, 0);
    sfRectangleShape *rec_2 = rect(0, 272);
    sfRectangleShape *rec_3 = rect(0, 544);
    sfRectangleShape *rec_4 = rect(0, 816);
    sfRectangleShape **Left = malloc(sizeof(sfRectangleShape *) * 5);

    Left[0] = rec_1;
    Left[1] = rec_2;
    Left[2] = rec_3;
    Left[3] = rec_4;
    sfRenderWindow_drawRectangleShape(window, Left[0], NULL);
    sfRenderWindow_drawRectangleShape(window, Left[1], NULL);
    sfRenderWindow_drawRectangleShape(window, Left[2], NULL);
    sfRenderWindow_drawRectangleShape(window, Left[3], NULL);
    return Left;
}

sfRectangleShape **middle_l(sfRenderWindow *window, sfEvent event)
{
    sfRectangleShape *rec_1 = rect(482, 0);
    sfRectangleShape *rec_2 = rect(482, 272);
    sfRectangleShape *rec_3 = rect(482, 544);
    sfRectangleShape *rec_4 = rect(482, 816);
    sfRectangleShape **Mleft = malloc(sizeof(sfRectangleShape *) * 5);

    Mleft[0] = rec_1;
    Mleft[1] = rec_2;
    Mleft[2] = rec_3;
    Mleft[3] = rec_4;
    sfRenderWindow_drawRectangleShape(window, Mleft[0], NULL);
    sfRenderWindow_drawRectangleShape(window, Mleft[1], NULL);
    sfRenderWindow_drawRectangleShape(window, Mleft[2], NULL);
    sfRenderWindow_drawRectangleShape(window, Mleft[3], NULL);
    return Mleft;
}

sfRectangleShape **middle_r(sfRenderWindow *window, sfEvent event)
{
    sfRectangleShape *rec_1 = rect(964, 0);
    sfRectangleShape *rec_2 = rect(964, 272);
    sfRectangleShape *rec_3 = rect(964, 544);
    sfRectangleShape *rec_4 = rect(964, 816);
    sfRectangleShape **Mright = malloc(sizeof(sfRectangleShape *) * 5);

    Mright[0] = rec_1;
    Mright[1] = rec_2;
    Mright[2] = rec_3;
    Mright[3] = rec_4;
    sfRenderWindow_drawRectangleShape(window, Mright[0], NULL);
    sfRenderWindow_drawRectangleShape(window, Mright[1], NULL);
    sfRenderWindow_drawRectangleShape(window, Mright[2], NULL);
    sfRenderWindow_drawRectangleShape(window, Mright[3], NULL);
    return Mright;
}

sfRectangleShape **right(sfRenderWindow *window, sfEvent event)
{
    sfRectangleShape *rec_1 = rect(1446, 0);
    sfRectangleShape *rec_2 = rect(1446, 272);
    sfRectangleShape *rec_3 = rect(1446, 544);
    sfRectangleShape *rec_4 = rect(1446, 816);
    sfRectangleShape **Right = malloc(sizeof(sfRectangleShape *) * 5);

    Right[0] = rec_1;
    Right[1] = rec_2;
    Right[2] = rec_3;
    Right[3] = rec_4;
    sfRenderWindow_drawRectangleShape(window, Right[0], NULL);
    sfRenderWindow_drawRectangleShape(window, Right[1], NULL);
    sfRenderWindow_drawRectangleShape(window, Right[2], NULL);
    sfRenderWindow_drawRectangleShape(window, Right[3], NULL);
    return Right;
}

void rectangle(sfRenderWindow *window, sfEvent event)
{
    left(window, event);
    right(window, event);
    middle_r(window, event);
    middle_l(window, event);
}
