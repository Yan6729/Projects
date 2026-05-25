/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** deletes all buttons
*/

#include "../include/wolf3d.h"

void buttons_remover(scrnstp_t *screens)
{
    btn_t *tmp = NULL;
    btn_t *cont = NULL;

    for (int i = 0; i < 1; i++) {
        tmp = screens[i].buttons;
        for (; tmp != NULL; tmp = cont) {
            cont = tmp->next;
            free(tmp->button_name);
            sfTexture_destroy(tmp->button_texture);
            sfSprite_destroy(tmp->button_sprite);
            sfMusic_destroy(tmp->clicked_music);
            free(tmp);
        }
    }
    return;
}
