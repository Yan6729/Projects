/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** all global variables
*/

#include "../include/wolf3d.h"

global_t all_globals(void)
{
    global_t box;

    box.fps_limit = 60;
    box.fps = 60;
    box.game_clock = sfClock_create();
    box.seconds = 0;
    box.window_size = (SFVM){1920, 1080, 32};
    box.i = -3;
    return (box);
}
