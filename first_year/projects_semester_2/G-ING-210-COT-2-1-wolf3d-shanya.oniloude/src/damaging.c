/*
** EPITECH PROJECT, 2025
** damag
** File description:
** ing
*/
#include "../include/wolf3d_2.h"
void update_button_colors(button_t *retry, button_t *quit,
    sfVector2i mouse, int blink)
{
    sfColor base_retry = sfColor_fromRGB(100, 100, 255);
    sfColor hover_retry = sfColor_fromRGB(150, 150, 255);
    sfColor base_quit = sfColor_fromRGB(255, 100, 100);
    sfColor hover_quit = sfColor_fromRGB(255, 150, 150);
    sfBool over_retry = is_mouse_over(mouse, retry->position);
    sfBool over_quit = is_mouse_over(mouse, quit->position);

    sfRectangleShape_setFillColor(retry->shape, (over_retry && blink) ?
    hover_retry : base_retry);
    sfRectangleShape_setFillColor(quit->shape, (over_quit && blink) ?
    hover_quit : base_quit);
}

void draw_elements(sfRenderWindow *window, sfText *title,
    button_t *retry, button_t *quit)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawText(window, title, NULL);
    sfRenderWindow_drawRectangleShape(window, retry->shape, NULL);
    sfRenderWindow_drawText(window, retry->text, NULL);
    sfRenderWindow_drawRectangleShape(window, quit->shape, NULL);
    sfRenderWindow_drawText(window, quit->text, NULL);
    sfRenderWindow_display(window);
}

void destroy_all(sfText *title, button_t *retry,
    button_t *quit, sfClock *clock)
{
    sfText_destroy(title);
    sfRectangleShape_destroy(retry->shape);
    sfText_destroy(retry->text);
    sfRectangleShape_destroy(quit->shape);
    sfText_destroy(quit->text);
    sfClock_destroy(clock);
}

int handle_event(sfEvent *event, sfRenderWindow *window, gameovermenu_t *menu)
{
    sfVector2i mouse;

    if (event->type == sfEvtClosed)
        return 0;
    if (event->type == sfEvtMouseButtonPressed) {
        mouse = sfMouse_getPositionRenderWindow(window);
        if (is_mouse_over(mouse, menu->retry.position))
            return 1;
        if (is_mouse_over(mouse, menu->quit.position))
            return 0;
    }
    return -1;
}

int process_events(sfRenderWindow *window, gameovermenu_t *menu)
{
    sfEvent event;
    int res;

    while (sfRenderWindow_pollEvent(window, &event)) {
        res = handle_event(&event, window, menu);
        if (res != -1)
            return res;
    }
    return -1;
}
