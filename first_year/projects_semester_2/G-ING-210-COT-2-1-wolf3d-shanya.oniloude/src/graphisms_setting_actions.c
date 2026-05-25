/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** checks buttons
*/

#include "../include/wolf3d.h"

int graphism_button_actions_1(btn_t *btn, scrnstp_t **screens)
{
    if (btn->button_id == 7) {
        buttons_desactivater(&((global.current_screen)->buttons), 8, 9);
        global.fps_limit = 30;
        return (0);
    }
    if (btn->button_id == 8) {
        buttons_desactivater(&((global.current_screen)->buttons), 7, 9);
        global.fps_limit = 60;
        return (0);
    }
    if (btn->button_id == 9) {
        buttons_desactivater(&((global.current_screen)->buttons), 7, 8);
        global.fps_limit = 100;
        return (0);
    }
    if (btn->button_id == 10) {
        global.show_fps = 1;
        return (0);
    }
}

int graphism_button_actions(btn_t *btn, scrnstp_t **screens)
{
    if (change_settings_option(screens, btn, 42, 43) == 1)
        return (1);
    if (btn->button_id == 4) {
        buttons_desactivater(&((global.current_screen)->buttons), 5, 6);
        change_window_size(1, (SFVM){960, 540, 32}, 0, (SFV2F){0.5, 0.5});
        return (0);
    }
    if (btn->button_id == 5) {
        buttons_desactivater(&((global.current_screen)->buttons), 4, 6);
        change_window_size(2, (SFVM){1920, 1080, 32}, 0, (SFV2F){1, 1});
        return (0);
    }
    if (btn->button_id == 6) {
        buttons_desactivater(&((global.current_screen)->buttons), 4, 5);
        change_window_size(3, (SFVM){1920, 1080, 32}, 1, (SFV2F){1, 1});
        return (0);
    }
    graphism_button_actions_1(btn, screens);
    return (0);
}
