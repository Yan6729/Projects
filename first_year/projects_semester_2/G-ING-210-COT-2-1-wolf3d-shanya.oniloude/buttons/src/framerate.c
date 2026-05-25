/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** game framerate
*/

#include "../include/wolf3d.h"

void my_framerate(void)
{
    static int first = 1;
    static sfClock *clock;
    static int fps = 0;
    sfTime elapsed;

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        global.fps = fps;
        fps = 0;
        sfClock_restart(clock);
    } else
        fps++;
}
