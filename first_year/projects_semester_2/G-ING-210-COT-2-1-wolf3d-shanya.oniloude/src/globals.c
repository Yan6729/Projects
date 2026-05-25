/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** all global variables
*/

#include "../include/wolf3d.h"

void all_globals_1(global_t *box)
{
    box->p_spk = 0;
    box->l_hnd = 1;
    box->rot_sblt = 1.0;
    box->volume_level = sfRectangleShape_create();
    box->exit = 0;
    box->start_game = 0;
    box->font_1 = sfFont_createFromFile("fonts/ChakraPetch-Regular.ttf");
    box->text = sfText_create();
    box->show_fps = 0;
    box->i = -3;
    box->ok_settings = 0;
    return;
}

global_t all_globals(set_t *settings)
{
    global_t box;

    box.fps_limit = 60;
    box.fps = 60;
    box.game_clock = sfClock_create();
    box.seconds = 0;
    box.window_size = settings->window_size;
    box.ratio = settings->ratio;
    box.is_fullscreen = 0;
    box.window_i = settings->window_i;
    box.main_hovered = sfMusic_createFromFile("snd/main_hov.mp3");
    box.music_volume = 50;
    box.sound_volume = 50;
    all_globals_1(&box);
    sfRectangleShape_setFillColor(box.volume_level, sfWhite);
    return (box);
}
