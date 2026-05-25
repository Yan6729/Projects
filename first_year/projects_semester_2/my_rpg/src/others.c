/*
** EPITECH PROJECT, 2025
** werfghg
** File description:
** zsxc vb
*/

#include "../include/my_rpg.h"

int is_mouse_over(Button_t *btn, sfRenderWindow *win)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(btn->sprite);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);

    return sfFloatRect_contains(&bounds, mouse.x, mouse.y);
}

void setup_button(Button_t *btn, sfTexture *tex, sfIntRect rect, sfVector2f pos)
{
    btn->sprite = sfSprite_create();
    btn->rect = rect;
    btn->position = pos;
    btn->origin = (sfVector2f){rect.width / 2.0f, rect.height / 2.0f};
    btn->scale_normal = (sfVector2f){1.0f, 1.0f};
    btn->scale_hover = (sfVector2f){1.1f, 1.1f};
    sfSprite_setTexture(btn->sprite, tex, sfTrue);
    sfSprite_setTextureRect(btn->sprite, rect);
    sfSprite_setOrigin(btn->sprite, btn->origin);
    sfSprite_setPosition(btn->sprite, pos);
    sfSprite_setScale(btn->sprite, btn->scale_normal);
}

int init_window(sfRenderWindow **win)
{
    sfVideoMode mode = {1472, 832, 32};

    *win = sfRenderWindow_create(mode, "Menu RPG", sfClose, NULL);
    return 1;
}

int load_textures(sfTexture **menu, sfTexture **settings, sfTexture **help)
{
    *menu = sfTexture_createFromFile("texture/menu_rpg.jpg", NULL);
    *settings = sfTexture_createFromFile("texture/settings.png", NULL);
    *help = sfTexture_createFromFile("texture/help.png", NULL);
    return 1;
}
