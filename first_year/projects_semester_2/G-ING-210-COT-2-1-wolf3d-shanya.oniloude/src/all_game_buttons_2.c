/*
** EPITECH PROJECT, 2025
** test wolf3d
** File description:
** window
*/

#include "../include/wolf3d.h"

void credits_buttons(scrnstp_t **screens)
{
    scrnstp_t *tmp = NULL;

    new_screen(screens, 50, "img/bck_grnds/credits.jpg");
    change_screen(screens, &tmp, 50);
    button_adder(&(tmp->buttons), &(belm_t){0, 1, "img/btns/back.png",
        "snd/main_hov.mp3", {58, 58}, {298, 170}, {1, 1}, {1, 1}});
    return;
}
