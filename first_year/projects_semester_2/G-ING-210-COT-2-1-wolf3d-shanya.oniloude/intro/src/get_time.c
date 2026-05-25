/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** header
*/

#include "../include/wolf3d.h"

int get_time(void)
{
    global.time = sfClock_getElapsedTime(global.game_clock);
    global.seconds = global.time.microseconds / 1000000.0;
    return (0);
}
