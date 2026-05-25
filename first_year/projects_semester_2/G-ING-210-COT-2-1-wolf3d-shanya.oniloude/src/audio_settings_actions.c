/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** checks buttons
*/

#include "../include/wolf3d.h"

int audio_button_actions_1(btn_t *btn, scrnstp_t **screens)
{
    if (btn->button_id == 8) {
        global.p_spk = 1;
        return (0);
    }
}

int audio_button_actions(btn_t *btn, scrnstp_t **screens)
{
    if (change_settings_option(screens, btn, 41, 43) == 1)
        return (1);
    if (btn->button_id == 4) {
        global.music_volume -= (global.music_volume > 0) ? 5 : 0;
        return (1);
    }
    if (btn->button_id == 5) {
        global.music_volume += (global.music_volume < 100) ? 5 : 0;
        return (1);
    }
    if (btn->button_id == 6) {
        global.sound_volume -= (global.sound_volume > 0) ? 5 : 0;
        return (1);
    }
    if (btn->button_id == 7) {
        global.sound_volume += (global.sound_volume < 100) ? 5 : 0;
        return (1);
    }
    audio_button_actions_1(btn, screens);
    return (0);
}
