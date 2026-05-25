/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** my_code root
*/

#include "../include/struct.h"

void if_click(sfRenderWindow *window, sfEvent event, int ac, char **av)
{
    sfVector2i mouse;
    float seconds;

    if (event.type == sfEvtMouseButtonPressed) {
        mouse = sfMouse_getPositionRenderWindow(window);
        if (mouse.x >= 879 && mouse.x <= 1065 &&
            mouse.y >= 529 && mouse.y <= 655) {
            loop(window, event, ac, av);
        }
    }
}

sfSprite *start_button(char *filepath)
{
    sfSprite *button_start = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfVector2f my_pos_start = {860, 520};
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
    sfVector2f scale = {1.5, 1.1};

    sfSprite_setScale(my_sprite, scale);
    sfSprite_setPosition(my_sprite, my_pos);
    sfSprite_setTexture(my_sprite, texture, sfTrue);
    return my_sprite;
}

int analyse_events(sfRenderWindow *window, sfEvent event, int ac, char **av)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return 1;
        }
        if_click(window, event, ac, av);
    }
    return 0;
}

int menu(int ac, char **av)
{
    sfVideoMode mode = {1920, 1080, 64};
    sfUint32 sf = {sfClose};
    sfRenderWindow *window = sfRenderWindow_create(mode, "My_world !", sf, 0);
    sfEvent event = {0};
    sfSprite *background_1 = create_background("background.jpg");
    sfSprite *start = start_button("Button_start.png");

    while (sfRenderWindow_isOpen(window)) {
        if (analyse_events(window, event, ac, av))
            return 0;
    sfRenderWindow_clear(window, sfBlack);
    draw_2(window, background_1, start);
    sfRenderWindow_display(window);
    }
    destroy_1(background_1, start);
    sfRenderWindow_destroy(window);
}
