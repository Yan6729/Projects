/*
** EPITECH PROJECT, 2025
** test wolf3d
** File description:
** window
*/

#include "../include/wolf3d.h"

void show_fps(sfRenderWindow *window)
{
    if (global.i >= 0 && global.show_fps == 1) {
        sprintf(global.text_cont, "FPS : %d", global.fps);
        set_text(global.text_cont, global.font_1, 20, sfWhite);
        sfText_setPosition(global.text, (SFV2F){10, 10});
        sfRenderWindow_drawText(window, global.text, NULL);
    }
    return;
}
