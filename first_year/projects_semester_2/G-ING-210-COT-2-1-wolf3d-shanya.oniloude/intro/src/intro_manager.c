/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** manages intro
*/

#include "../include/wolf3d.h"

void introductor(sfRenderWindow *window, intro_t *intro)
{
    if (global.i == -3)
        epi_shower(window, intro);
    if (global.i == -2)
        shayanx_shower(window, intro);
    if (global.i == -1)
        loading_shower(window, intro);
    return;
}

void intro_skipper(sfEvent event, intro_t *intro)
{
    if (global.i < -1) {
        get_time();
        if (global.seconds >= 2.0 && event.key.code == sfKeySpace) {
            sfMusic_stop(intro->epi_msc);
            sfMusic_stop(intro->shayanx_msc);
            sfClock_restart(global.game_clock);
            global.i += 1;
            intro->i = 0;
        }
    }
    return;
}
