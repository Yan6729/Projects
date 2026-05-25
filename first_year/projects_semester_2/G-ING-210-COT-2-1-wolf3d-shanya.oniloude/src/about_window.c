/*
** EPITECH PROJECT, 2025
** test wolf3d
** File description:
** window
*/

#include "../include/wolf3d.h"

sfVector2f ratior(float x, float y)
{
    return ((SFV2F){(x * global.ratio.x), (y * global.ratio.y)});
}

static void buttons_new_values(btn_t **buttons, float ratio)
{
    for (btn_t *tmp = *buttons; tmp != NULL; tmp = tmp->next) {
        (tmp->button_scales[0]).x *= ratio;
        (tmp->button_scales[0]).y *= ratio;
        (tmp->button_scales[1]).x *= ratio;
        (tmp->button_scales[1]).y *= ratio;
        (tmp->position).x *= ratio;
        (tmp->position).y *= ratio;
        sfSprite_setPosition(tmp->button_sprite, tmp->position);
    }
    return;
}

void buttons_repositioner(scrnstp_t **screens, int previous_window)
{
    if ((previous_window == 2 || previous_window == 3) &&
        global.window_i == 1) {
        for (scrnstp_t *tmp = *screens; tmp != NULL; tmp = tmp->next) {
            sfSprite_setScale(tmp->back_sprt, global.ratio);
            buttons_new_values(&(tmp->buttons), 0.5);
        }
    }
    if (previous_window == 1 && (global.window_i == 3 ||
        global.window_i == 2)) {
        for (scrnstp_t *tmp = *screens; tmp != NULL; tmp = tmp->next) {
            sfSprite_setScale(tmp->back_sprt, global.ratio);
            buttons_new_values(&(tmp->buttons), 2);
        }
    }
    return;
}

void first_positionner(scrnstp_t **screens)
{
    if (global.ok_settings == 1)
        buttons_repositioner(screens, 2);
    return;
}

void change_window_size(int win_i, SFVM win_size, bool is_fscreen, SFV2F ratio)
{
    global.window_i = win_i;
    global.window_size = win_size;
    global.is_fullscreen = is_fscreen;
    global.ratio = ratio;
    return;
}

void window_resizer(win_t *win, int *previous_window, scrnstp_t **screens)
{
    if (*previous_window != global.window_i) {
        sfRenderWindow_destroy(win->window);
        if (global.window_i == 3)
            win->window = RWC(global.window_size, "Sector42: Genesis",
                sfFullscreen, NULL);
        else
            win->window = RWC(global.window_size, "Sector42: Genesis",
                sfClose, NULL);
        sfRenderWindow_setFramerateLimit(win->window, global.fps_limit);
        buttons_repositioner(screens, *previous_window);
        *previous_window = global.window_i;
    }
    return;
}
