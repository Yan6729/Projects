/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** checks buttons
*/

#include "../include/wolf3d.h"

int credits_button_actions(btn_t *btn, scrnstp_t **screens)
{
    if (back_button_clicked(screens, btn, 0))
        return (1);
    return (0);
}
