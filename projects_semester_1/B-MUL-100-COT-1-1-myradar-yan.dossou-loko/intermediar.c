/*
** EPITECH PROJECT, 2025
** intermediar.c
** File description:
** an intermediar function
*/

#include "struct.h"

sfSprite *map(char const *filepath)
{
    sfSprite *map = sfSprite_create();
    sfVector2f pos_g = {0, 0};
    sfVector2f scale = {1.79, 1.28};
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setScale(map, scale);
    sfSprite_setPosition(map, pos_g);
    sfSprite_setTexture(map, texture, sfTrue);
    return map;
}

int manage_events(file_t cmp)
{
    int c = 0;
    int d = 0;

    while (sfRenderWindow_pollEvent(cmp.window, &cmp.event)) {
        if (cmp.event.type == sfEvtClosed)
            sfRenderWindow_close(cmp.window);
    }
}

file_t structure(void)
{
    file_t cmp;

    cmp.sf = (sfUint32){sfClose | sfResize};
    cmp.mode = (sfVideoMode){1920, 1080, 120};
    cmp.window = sfRenderWindow_create(cmp.mode, "My_radar", cmp.sf, NULL);
    cmp.event;
    cmp.textp = sfTexture_createFromFile("plane.png", NULL);
    cmp.text = sfTexture_createFromFile("tower.png", NULL);
    cmp.plane = my_plane(cmp);
    cmp.backg = map("Map1.jpeg");
    cmp.tower = my_tower(cmp);
    return cmp;
}

void destroy(file_t cmp)
{
    sfSprite_destroy(cmp.backg);
    sfRectangleShape_destroy(cmp.rec);
    sfSprite_destroy(cmp.backg);
    sfSprite_destroy(cmp.plane);
    sfSprite_destroy(cmp.tower);
    sfTexture_destroy(cmp.textp);
    sfTexture_destroy(cmp.text);
    sfRenderWindow_destroy(cmp.window);
}

void tow_draw(tower_t *temp_1, tower_t *tow, file_t cmp)
{
    for (tow = temp_1; tow != NULL; tow = tow->next) {
        cmp.pos_t = (sfVector2f){tow->Xt, tow->Yt};
        cmp.circ = circle(tow->Xt, tow->Yt, tow->rad);
        sfRenderWindow_drawCircleShape(cmp.window, cmp.circ, NULL);
        sfSprite_setPosition(cmp.tower, cmp.pos_t);
        sfRenderWindow_drawSprite(cmp.window, cmp.tower, NULL);
    }
}
