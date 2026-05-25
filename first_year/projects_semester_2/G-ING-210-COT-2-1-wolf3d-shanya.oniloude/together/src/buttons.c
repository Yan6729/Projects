/*
** EPITECH PROJECT, 2025
** test wolf3d
** File description:
** buttons
*/

#include "../include/wolf3d.h"

void button_bases(btn_t *nb)
{
    sfIntRect area = {0, 0, nb->button_size.x, nb->button_size.y};
    SFV2F center = {(nb->button_size.x / 2), (nb->button_size.y / 2)};

    sfSprite_setTexture(nb->button_sprite, nb->button_texture, true);
    sfSprite_setTextureRect(nb->button_sprite, area);
    sfSprite_setScale(nb->button_sprite, nb->button_scales[0]);
    sfSprite_setOrigin(nb->button_sprite, center);
    sfSprite_setPosition(nb->button_sprite, nb->position);
    return;
}

void add_button_to_list(btn_t **buttons, btn_t *new_button)
{
    btn_t *tmp = *buttons;

    if (*buttons == NULL)
        *buttons = new_button;
    else {
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = new_button;
    }
    return;
}

void button_adder(btn_t **buttons, belm_t *elm)
{
    btn_t *new_button = malloc(sizeof(btn_t));

    new_button->idle = 1;
    new_button->hover = 0;
    new_button->selected = 0;
    new_button->selected_hover = 0;
    new_button->const_button = elm->const_btn;
    new_button->button_id = elm->btn_id;
    new_button->button_texture = sfTexture_createFromFile(elm->txr_path, NULL);
    new_button->button_sprite = sfSprite_create();
    new_button->button_size = (sfVector2i){(elm->btn_siz).x, (elm->btn_siz).y};
    new_button->button_scales[0] = elm->idle_scale;
    new_button->button_scales[1] = elm->hover_scale;
    new_button->position = elm->btn_pos;
    new_button->clicked_music = sfMusic_createFromFile(elm->snd_path);
    new_button->next = NULL;
    button_bases(new_button);
    add_button_to_list(buttons, new_button);
    return;
}

void buttons_step(btn_t *tmp, sfIntRect *area, int left, int i)
{
    area->left = left;
    sfSprite_setScale(tmp->button_sprite, tmp->button_scales[i]);
    return;
}

void buttons_displayer(btn_t **buttons, sfRenderWindow *win)
{
    sfIntRect area;

    for (btn_t *tmp = *buttons; tmp != NULL; tmp = tmp->next) {
        area = sfSprite_getTextureRect(tmp->button_sprite);
        if (tmp->idle == 1)
            buttons_step(tmp, &area, 0, 0);
        if (tmp->hover == 1)
            buttons_step(tmp, &area, tmp->button_size.x, 1);
        if (tmp->selected == 1)
            buttons_step(tmp, &area, (tmp->button_size.x * 2), 0);
        if (tmp->const_button == 1 && tmp->selected_hover == 1)
            buttons_step(tmp, &area, (tmp->button_size.x * 3), 1);
        sfSprite_setTextureRect(tmp->button_sprite, area);
        sfRenderWindow_drawSprite(win, tmp->button_sprite, NULL);
    }
    return;
}
