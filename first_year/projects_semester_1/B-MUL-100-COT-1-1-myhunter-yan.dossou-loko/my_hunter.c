/*
** EPITECH PROJECT, 2024
** window_display.c
** File description:
** display a window
*/
#include "my.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include <SFML/System/Vector2.h>

void if_click(sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse;
    float seconds;

    if (event.type == sfEvtMouseButtonPressed) {
        mouse = sfMouse_getPositionRenderWindow(window);
        if (mouse.x >= 286 && mouse.x <= 460 &&
            mouse.y >= 203 && mouse.y <= 300) {
            create_game(window, event, seconds);
        }
    }
}

sfSprite *start_button(char *filepath)
{
    sfSprite *button_start = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfVector2f my_pos_start = {280, 180};
    sfVector2f scale = {0.3, 0.5};

    sfSprite_setScale(button_start, scale);
    sfSprite_setPosition(button_start, my_pos_start);
    sfSprite_setTexture(button_start, texture, sfTrue);
    return button_start;
}

sfSprite *create_background(char *filepath)
{
    sfSprite *my_sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfVector2f my_pos = {0, 0};
    sfVector2f scale = {0.87, 1.12};

    sfSprite_setScale(my_sprite, scale);
    sfSprite_setPosition(my_sprite, my_pos);
    sfSprite_setTexture(my_sprite, texture, sfTrue);
    return my_sprite;
}

int manage_events(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return 1;
        }
        if_click(window, event);
    }
    return 0;
}
