/*
** EPITECH PROJECT, 2025
** mini
** File description:
** map
*/

#include "../include/wolf3d_2.h"
void carve_room(room_t r)
{
    for (int i = r.y; i < r.y + r.h; i++) {
        car(r, i);
    }
}

void draw_me(sfRectangleShape *tile, const int scale,
    sfRenderWindow *window, int y)
{
    sfVector2f pos;

    for (int x = 0; x < MAP_WIDTH; x++) {
        pos = (sfVector2f){x * scale, y * scale};
        sfRectangleShape_setPosition(tile, pos);
        sfRectangleShape_setSize(tile, (sfVector2f){scale, scale});
        if (is_wall(x, y) != 0)
            sfRectangleShape_setFillColor
                (tile, sfColor_fromRGB(100, 100, 100));
        else
            sfRectangleShape_setFillColor
                (tile, sfColor_fromRGB(200, 200, 200));
        sfRenderWindow_drawRectangleShape(window, tile, NULL);
    }
}
