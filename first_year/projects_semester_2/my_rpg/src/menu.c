/*
** EPITECH PROJECT, 2025
** fghjk
** File description:
** ytrew
*/

#include "../include/my_rpg.h"

void init_menu(Menu_t *menu)
{
    menu->rect_back = (sfFloatRect){580, 540, 300, 70};
    menu->rect_help = (sfFloatRect){580, 370, 300, 70};
    menu->state = 0;
    if (!init_window(&menu->win) || !load_textures(&menu->menu_tex, &menu->settings_tex, &menu->help_tex))
        exit(84);
    setup_button(&menu->buttons.btn_start, menu->menu_tex, (sfIntRect){436, 731, 140, 50}, (sfVector2f){505, 755});
    setup_button(&menu->buttons.btn_settings, menu->menu_tex, (sfIntRect){675, 730, 150, 50}, (sfVector2f){750, 755});
    setup_button(&menu->buttons.btn_quit, menu->menu_tex, (sfIntRect){907, 730, 100, 50}, (sfVector2f){965, 755});
    setup_button(&menu->buttons.btn_back, menu->settings_tex, (sfIntRect){580, 540, 300, 70}, (sfVector2f){733, 573});
    setup_button(&menu->buttons.btn_help, menu->settings_tex, (sfIntRect){580, 370, 300, 70}, (sfVector2f){733, 410});
    menu->backgrounds.menu = sfSprite_create();
    menu->backgrounds.settings = sfSprite_create();
    menu->backgrounds.help = sfSprite_create();
    sfSprite_setTexture(menu->backgrounds.menu, menu->menu_tex, sfTrue);
    sfSprite_setTexture(menu->backgrounds.settings, menu->settings_tex, sfTrue);
    sfSprite_setTexture(menu->backgrounds.help, menu->help_tex, sfTrue);
}

void handle_events(Menu_t *menu)
{
    sfEvent event;
    sfVector2i m;

    while (sfRenderWindow_pollEvent(menu->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(menu->win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            menu->state = 0;
        if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
            m = sfMouse_getPositionRenderWindow(menu->win);
            if (menu->state == 0) {
                if (is_mouse_over(&menu->buttons.btn_start, menu->win))
                    loop(menu->win);
                if (is_mouse_over(&menu->buttons.btn_settings, menu->win))
                    menu->state = 1;
                if (is_mouse_over(&menu->buttons.btn_quit, menu->win))
                    sfRenderWindow_close(menu->win);
            } else if (menu->state == 1) {
                if (sfFloatRect_contains(&menu->rect_back, m.x, m.y))
                    menu->state = 0;
                else if (sfFloatRect_contains(&menu->rect_help, m.x, m.y))
                    menu->state = 2;
            }
        }
    }
}

void update_hover(Menu_t *menu)
{
    if (menu->state == 0) {
        sfSprite_setScale(menu->buttons.btn_start.sprite,
            is_mouse_over(&menu->buttons.btn_start, menu->win) ? menu->buttons.btn_start.scale_hover : menu->buttons.btn_start.scale_normal);
        sfSprite_setScale(menu->buttons.btn_settings.sprite,
            is_mouse_over(&menu->buttons.btn_settings, menu->win) ? menu->buttons.btn_settings.scale_hover : menu->buttons.btn_settings.scale_normal);
        sfSprite_setScale(menu->buttons.btn_quit.sprite,
            is_mouse_over(&menu->buttons.btn_quit, menu->win) ? menu->buttons.btn_quit.scale_hover : menu->buttons.btn_quit.scale_normal);
    } else if (menu->state == 1) {
        sfSprite_setScale(menu->buttons.btn_help.sprite,
            is_mouse_over(&menu->buttons.btn_help, menu->win) ? menu->buttons.btn_help.scale_hover : menu->buttons.btn_help.scale_normal);
        sfSprite_setScale(menu->buttons.btn_back.sprite,
            is_mouse_over(&menu->buttons.btn_back, menu->win) ? menu->buttons.btn_back.scale_hover : menu->buttons.btn_back.scale_normal);
    }
}

void draw_menu(Menu_t *menu)
{
    sfRenderWindow_clear(menu->win, sfBlack);
    if (menu->state == 0) {
        sfRenderWindow_drawSprite(menu->win, menu->backgrounds.menu, NULL);
        sfRenderWindow_drawSprite(menu->win, menu->buttons.btn_start.sprite, NULL);
        sfRenderWindow_drawSprite(menu->win, menu->buttons.btn_settings.sprite, NULL);
        sfRenderWindow_drawSprite(menu->win, menu->buttons.btn_quit.sprite, NULL);
    } else if (menu->state == 1) {
        sfRenderWindow_drawSprite(menu->win, menu->backgrounds.settings, NULL);
        sfRenderWindow_drawSprite(menu->win, menu->buttons.btn_help.sprite, NULL);
        sfRenderWindow_drawSprite(menu->win, menu->buttons.btn_back.sprite, NULL);
    } else if (menu->state == 2) {
        sfRenderWindow_drawSprite(menu->win, menu->backgrounds.help, NULL);
    }
    sfRenderWindow_display(menu->win);
}

void handle_menu(Menu_t *menu)
{
    sfMusic *music = play_music_loop("son/son.mp3");
    
    while (sfRenderWindow_isOpen(menu->win)) {
        handle_events(menu);
        update_hover(menu);
        draw_menu(menu);
    }
    sfMusic_destroy(music);
}
