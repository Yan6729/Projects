/*
** EPITECH PROJECT, 2025
** rtyhj
** File description:
** sxdcfvgbhnm
*/

#include "../include/my_rpg.h"

void destroy_menu(Menu_t *menu)
{
    sfSprite_destroy(menu->backgrounds.menu);
    sfSprite_destroy(menu->backgrounds.settings);
    sfSprite_destroy(menu->backgrounds.help);
    sfSprite_destroy(menu->buttons.btn_start.sprite);
    sfSprite_destroy(menu->buttons.btn_settings.sprite);
    sfSprite_destroy(menu->buttons.btn_quit.sprite);
    sfSprite_destroy(menu->buttons.btn_help.sprite);
    sfSprite_destroy(menu->buttons.btn_back.sprite);
    sfTexture_destroy(menu->menu_tex);
    sfTexture_destroy(menu->settings_tex);
    sfTexture_destroy(menu->help_tex);
    sfRenderWindow_destroy(menu->win);
}
