/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** checks buttons
*/

#include "../include/wolf3d.h"

int controls_button_actions_1(btn_t *btn, scrnstp_t **screens)
{
    if (btn->button_id == 7) {
        buttons_desactivater(&((global.current_screen)->buttons), 6, 8);
        global.rot_sblt = 1.5;
        return (0);
    }
    if (btn->button_id == 8) {
        buttons_desactivater(&((global.current_screen)->buttons), 6, 7);
        global.rot_sblt = 2.0;
        return (0);
    }
}

int controls_button_actions(btn_t *btn, scrnstp_t **screens)
{
    if (change_settings_option(screens, btn, 41, 42) == 1)
        return (1);
    if (btn->button_id == 4) {
        buttons_desactivater(&((global.current_screen)->buttons), 5, 5);
        global.l_hnd = 1;
        return (0);
    }
    if (btn->button_id == 5) {
        buttons_desactivater(&((global.current_screen)->buttons), 4, 4);
        global.l_hnd = 0;
        return (0);
    }
    if (btn->button_id == 6) {
        buttons_desactivater(&((global.current_screen)->buttons), 7, 8);
        global.rot_sblt = 1.0;
        return (0);
    }
    controls_button_actions_1(btn, screens);
    return (0);
}
