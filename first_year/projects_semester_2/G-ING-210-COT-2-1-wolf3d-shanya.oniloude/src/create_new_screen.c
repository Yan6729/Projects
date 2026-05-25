/*
** EPITECH PROJECT, 2025
** test wolf3d
** File description:
** window
*/

#include "../include/wolf3d.h"

void add_screen_to_list(scrnstp_t **screens, scrnstp_t *new_screen)
{
    scrnstp_t *tmp = *screens;

    if (*screens == NULL)
        *screens = new_screen;
    else {
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = new_screen;
    }
    return;
}

void new_screen(scrnstp_t **screens, int id, char *txtr_path)
{
    scrnstp_t *new_screen = malloc(sizeof(scrnstp_t));
    scrnstp_t *tmp = NULL;

    new_screen->id = id;
    new_screen->back_txtr = sfTexture_createFromFile(txtr_path, NULL);
    new_screen->back_sprt = sprt_create(new_screen->back_txtr, (SFV2F){0, 0});
    new_screen->buttons = NULL;
    new_screen->next = NULL;
    add_screen_to_list(screens, new_screen);
    return;
}
