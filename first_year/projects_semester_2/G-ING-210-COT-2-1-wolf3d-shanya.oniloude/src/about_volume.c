/*
** EPITECH PROJECT, 2025
** test wolf3d
** File description:
** window
*/

#include "../include/wolf3d.h"

void volume_sizer(SFRW window, int volume, int *pre_vol, SFV2F pos)
{
    sfRectangleShape_setSize(global.volume_level,
        ratior((757 * volume) / 100, 12));
    sfRectangleShape_setPosition(global.volume_level, pos);
    sfRenderWindow_drawRectangleShape(window, global.volume_level, NULL);
    sprintf(global.text_cont, "%d", volume);
    set_text(global.text_cont, global.font_1, (50 * global.ratio.x), sfBlack);
    sfText_setPosition(global.text,
        (SFV2F){(1620 * global.ratio.x), (pos.y - (25 * global.ratio.x))});
    sfRenderWindow_drawText(window, global.text, NULL);
    return;
}

void set_sound_volume(btn_t **buttons)
{
    for (btn_t *tmp = *buttons; tmp != NULL; tmp = tmp->next)
        sfMusic_setVolume(tmp->clicked_music, global.sound_volume);
    return;
}

void volume_applier(scrnstp_t **screens, int pre_msc, int pre_snd)
{
    if (pre_snd != global.sound_volume) {
        sfMusic_setVolume(global.main_hovered, global.sound_volume);
        for (scrnstp_t *tmp = *screens; tmp != NULL; tmp = tmp->next)
            set_sound_volume(&(tmp->buttons));
    }
    return;
}
