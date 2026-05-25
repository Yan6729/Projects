/*
** EPITECH PROJECT, 2025
** game
** File description:
** over
*/

#include "../include/wolf3d_2.h"

void update_and_draw(sfRenderWindow *window, gameovermenu_t *menu, int *blink)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (sfTime_asSeconds(sfClock_getElapsedTime(menu->clock)) > 0.3f) {
        *blink = !(*blink);
        sfClock_restart(menu->clock);
    }
    update_button_colors(&menu->retry, &menu->quit, mouse, *blink);
    draw_elements(window, menu->title, &menu->retry, &menu->quit);
}

int game_over_loop(sfRenderWindow *window, gameovermenu_t *menu)
{
    int blink = 1;
    int event_res;

    while (sfRenderWindow_isOpen(window)) {
        event_res = process_events(window, menu);
        if (event_res != -1)
            return event_res;
        update_and_draw(window, menu, &blink);
    }
    return 0;
}

int draw_game_over_menu(sfRenderWindow *window, sfFont *font)
{
    gameovermenu_t menu;
    int res = 0;

    init_title(&menu.title, font);
    init_button(&menu.retry, font, "Retry",
    (sfVector2f){WINDOW_WIDTH / 2 - 100, 250});
    init_button(&menu.quit, font, "Quit",
    (sfVector2f){WINDOW_WIDTH / 2 - 100, 350});
    menu.clock = sfClock_create();
    res = game_over_loop(window, &menu);
    sfClock_destroy(menu.clock);
    sfText_destroy(menu.title);
    sfRectangleShape_destroy(menu.retry.shape);
    sfText_destroy(menu.retry.text);
    sfRectangleShape_destroy(menu.quit.shape);
    sfText_destroy(menu.quit.text);
    return res;
}
