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
    box.is_fullscreen = 0;
    box.window_i = 2;
    box.main_hovered = sfMusic_createFromFile("snd/main_hov.mp3");
    box.music_volume = 50;
    box.sound_volume = 50;
    box.volume_level = sfRectangleShape_create();
    box.exit = 0;
    box.font_1 = sfFont_createFromFile("fonts/ChakraPetch-Regular.ttf");
    box.text = sfText_create();
    box.show_fps = 0;
    box.ratio = (SFV2F){1, 1};
    box.i = -3;
    sfRectangleShape_setFillColor(box.volume_level, sfWhite);
    return (box);
}
