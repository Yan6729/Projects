/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** first intro
*/

#include "../include/wolf3d.h"

void shoot_for_shayanx(intro_t *intro, float delay, int intro_i_pos)
{
    get_time();
    if (global.seconds >= delay && intro->i == intro_i_pos) {
        sfMusic_play(intro->shayanx_shoot);
        intro->i += 1;
    }
    return;
}

void hider_positioner(SFRW win, intro_t *intro, SFV2F r_size, SFV2F r_pos)
{
    sfRectangleShape_setSize(intro->rect_hider, r_size);
    sfRectangleShape_setPosition(intro->rect_hider, r_pos);
    sfRenderWindow_drawRectangleShape(win, intro->rect_hider, NULL);
    return;
}

void shooting_time(sfRenderWindow *win, intro_t *intro)
{
    shoot_for_shayanx(intro, 4.0, 2);
    if (intro->i == 3) {
        sfSprite_setTextureRect(intro->shayanx_sprt,
            (sfIntRect){435, 0, 655, 375});
        sfSprite_setPosition(intro->shayanx_sprt, (sfVector2f){850, 353});
    }
    shoot_for_shayanx(intro, 4.5, 3);
    if (intro->i == 4)
        hider_positioner(win, intro, (SFV2F){285, 80}, (SFV2F){852, 580});
    shoot_for_shayanx(intro, 5.5, 4);
    if (intro->i == 5)
        sfSprite_setTextureRect(intro->shayanx_sprt,
            (sfIntRect){435, 0, 655, 220});
    return;
}

void shayanx_animation(intro_t *intro)
{
    get_time();
    if (global.seconds >= 6.5) {
        intro->container = sfSprite_getPosition(intro->shayanx_sprt);
        (intro->container).x -= ((intro->container).x > 420) ? 5 : 0;
        sfSprite_setPosition(intro->shayanx_sprt, intro->container);
    }
    get_time();
    if (global.seconds >= 10) {
        fader(intro->shayanx_sprt);
        fader(intro->chaos_sprt);
        if (global.i == 0) {
            global.i = -1;
            intro->i = 0;
        }
    }
    return;
}

void shayanx_shower(sfRenderWindow *window, intro_t *intro)
{
    get_time();
    if (global.seconds >= 1.0) {
        if (intro->i == 0 || intro->i == 1) {
            sfMusic_play(intro->shayanx_msc);
            intro->i = 2;
        }
        if (intro->i == 5) {
            sfRenderWindow_drawSprite(window, intro->chaos_sprt, NULL);
            shayanx_animation(intro);
        }
        sfRenderWindow_drawSprite(window, intro->shayanx_sprt, NULL);
        if (intro->color.a < 255) {
            intro->color.a += 5;
            sfSprite_setColor(intro->shayanx_sprt, intro->color);
        }
        shooting_time(window, intro);
    }
    return;
}
