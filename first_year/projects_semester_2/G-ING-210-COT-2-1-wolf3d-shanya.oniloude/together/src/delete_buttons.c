/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** deletes all buttons
*/

#include "../include/wolf3d.h"

void buttons_remover(scrnstp_t **screens)
{
    scrnstp_t *s_cont = NULL;
    btn_t *tmp = NULL;
    btn_t *b_cont = NULL;

    for (; *screens != NULL; *screens = s_cont) {
        s_cont = (*screens)->next;
        sfTexture_destroy((*screens)->back_txtr);
        sfSprite_destroy((*screens)->back_sprt);
        for (tmp = (*screens)->buttons; tmp != NULL; tmp = b_cont) {
            b_cont = tmp->next;
            //free(tmp->button_name);
            sfTexture_destroy(tmp->button_texture);
            sfSprite_destroy(tmp->button_sprite);
            sfMusic_destroy(tmp->clicked_music);
            free(tmp);
        }
        free(*screens);
    }
    return;
}
