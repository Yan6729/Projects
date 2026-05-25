/*
** EPITECH PROJECT, 2025
** pause
** File description:
** menu
*/

#include "../include/wolf3d_2.h"

void destroy_pause_menu(pause_menu_t *menu)
{
    sfFont_destroy(menu->font);
    for (int i = 0; i < 3; i++)
        sfText_destroy(menu->options[i]);
    free(menu->options);
    free(menu);
}

int handle_window_close(sfRenderWindow *win, pause_menu_t *menu,
    sfClock *blink, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(win);
        return 2;
    }
    return -1;
}

int handle_key_pressed(sfRenderWindow *win, pause_menu_t *menu,
    sfClock *blink, sfEvent event)
{
    int selected = 0;

    if (event.type != sfEvtKeyPressed)
        return -1;
    if (event.key.code == sfKeyEscape) {
        return 0;
    }
    update_pause_menu(menu, event);
    if (event.key.code == sfKeyEnter) {
        selected = menu->selected;
        return selected;
    }
    return -1;
}

int process_event(sfRenderWindow *win, pause_menu_t *menu, sfClock *blink)
{
    sfEvent event;
    int res = -1;

    while (sfRenderWindow_pollEvent(win, &event)) {
        res = handle_window_close(win, menu, blink, event);
        if (res != -1)
            return res;
        res = handle_key_pressed(win, menu, blink, event);
        if (res != -1)
            return res;
    }
    return -1;
}

int handle_pause(sfRenderWindow *win)
{
    pause_menu_t *menu = init_pause_menu();
    sfClock *blink = sfClock_create();
    int res = -1;

    while (sfRenderWindow_isOpen(win)) {
        res = process_event(win, menu, blink);
        if (res != -1)
            break;
        sfRenderWindow_clear(win, sfBlack);
        display_pause_menu(win, menu, blink);
        sfRenderWindow_display(win);
    }
    destroy_pause_menu(menu);
    sfClock_destroy(blink);
    return res != -1 ? res : 2;
}
