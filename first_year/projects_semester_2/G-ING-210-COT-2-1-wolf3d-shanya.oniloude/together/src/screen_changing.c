/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** screen change
*/

#include "../include/wolf3d.h"

void change_screen(scrnstp_t **screens, scrnstp_t **relay, int to_id)
{
    scrnstp_t *tmp = *screens;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->id == to_id) {
            *relay = tmp;
            break;
        }
    }
    return;
}

void reset_button(btn_t *btn)
{
    btn->idle = 1;
    btn->hover = 0;
    btn->selected = 0;
    return;
}

void screen_switching(btn_t *btn, scrnstp_t **screens, int to_id)
{
    reset_button(btn);
    change_screen(screens, &(global.current_screen), to_id);
    return;
}

int back_button_clicked(scrnstp_t **screens, btn_t *btn, int to_id)
{
    if (btn->button_id == 1) {
        screen_switching(btn, screens, to_id);
        return (1);
    }
    return (0);
}

int change_settings_option(scrnstp_t **screens, btn_t *btn, int op1, int op2)
{
    if (back_button_clicked(screens, btn, 0))
        return (1);
    if (btn->button_id == 2) {
        screen_switching(btn, screens, op1);
        return (1);
    }
    if (btn->button_id == 3) {
        screen_switching(btn, screens, op2);
        return (1);
    }
    return (0);
}
