/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** first intro
*/

#include "../include/wolf3d.h"

void fader(sfSprite *sprt)
{
    sfColor color;

    color = sfSprite_getColor(sprt);
    color.a -= (color.a > 0) ? 5 : 0;
    sfSprite_setColor(sprt, color);
    if (color.a == 0) {
        global.i += 1;
        sfClock_restart(global.game_clock);
    }
    return;
}

void epi_shower(sfRenderWindow *window, intro_t *intro)
{
    SFV2F pos = sfSprite_getPosition(intro->epi_sprt);

    sfRenderWindow_drawSprite(window, intro->epi_sprt, NULL);
    sfRenderWindow_drawRectangleShape(window, intro->rect_hider, NULL);
    pos.y -= (pos.y > (444 * global.ratio.y)) ? (3 * global.ratio.y) : 0;
    sfSprite_setPosition(intro->epi_sprt, pos);
    if (pos.y <= (445 * global.ratio.y) && intro->i == 0) {
        sfMusic_play(intro->epi_msc);
        intro->i = 1;
    }
    get_time();
    if (global.seconds >= 4.0)
        fader(intro->epi_sprt);
    return;
}
