/*
** EPITECH PROJECT, 2025
** test wolf3d
** File description:
** window
*/

#include "../include/wolf3d.h"

void full_loading(sfRenderWindow *window, intro_t *intro)
{
    if (intro->i == 2) {
        sfRenderWindow_drawRectangleShape(window, intro->rect_hider, NULL);
        sfRenderWindow_drawSprite(window, intro->loading_sprt, NULL);
        get_time();
        if (global.seconds >= 2.5) {
            global.i += 1;
            intro->i = -1;
            intro_elements_destroy(intro);
        }
    }
    return;
}

void rect_load_init(intro_t *intro)
{
    if (intro->i == 0) {
        sfRectangleShape_setSize(intro->rect_hider, (SFV2F){0, 10});
        sfRectangleShape_setPosition(intro->rect_hider, (SFV2F){70, 1006});
        sfRectangleShape_setFillColor(intro->rect_hider, sfWhite);
        intro->i = 1;
    }
    return;
}

void manage_loading(intro_t *intro)
{
    intro->container = sfRectangleShape_getSize(intro->rect_hider);
    intro->angle = sfSprite_getRotation(intro->loading_sprt) - (rand() % 5);
    if (intro->container.x < 1780)
        intro->container.x += (rand() % 23 == 0) ? rand() % 1000 : 0;
    if (intro->container.x >= 1780) {
        intro->container.x = 1780;
        intro->i = 2;
        sfClock_restart(global.game_clock);
    }
    return;
}

void loading_shower(sfRenderWindow *window, intro_t *intro)
{
    full_loading(window, intro);
    get_time();
    if (intro->i != 2 && intro->i != -1 && global.seconds >= 2.0) {
        rect_load_init(intro);
        manage_loading(intro);
        sfRectangleShape_setSize(intro->rect_hider, intro->container);
        sfSprite_setRotation(intro->loading_sprt, intro->angle);
        sfRenderWindow_drawRectangleShape(window, intro->rect_hider, NULL);
        sfRenderWindow_drawSprite(window, intro->loading_sprt, NULL);
    }
    return;
}
