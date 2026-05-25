/*
** EPITECH PROJECT, 2025
** damage
** File description:
** damage
*/
#include "../include/wolf3d_2.h"

void player_take_damage(player_t *player, int damage)
{
    player->health -= damage;
    if (player->health < 0)
        player->health = 0;
    player->is_hurt = 1;
    player->hurt_alpha = 150;
}

void draw_blood_effect(sfRenderWindow *window, player_t *player)
{
    if (!player->is_hurt)
        return;
    player->blood = sfRectangleShape_create();
    player->size = (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT};
    player->pos = (sfVector2f){0, 0};
    sfRectangleShape_setSize(player->blood, player->size);
    sfRectangleShape_setPosition(player->blood, player->pos);
    player->red = sfColor_fromRGBA(255, 0, 0, player->hurt_alpha);
    sfRectangleShape_setFillColor(player->blood, player->red);
    sfRenderWindow_drawRectangleShape(window, player->blood, NULL);
    player->hurt_alpha -= 5;
    if (player->hurt_alpha <= 0) {
        player->hurt_alpha = 0;
        player->is_hurt = 0;
    }
    sfRectangleShape_destroy(player->blood);
}

void init_button(button_t *btn, sfFont *font, const char *str, sfVector2f pos)
{
    btn->shape = sfRectangleShape_create();
    btn->text = sfText_create();
    btn->position = pos;
    sfRectangleShape_setSize(btn->shape, (sfVector2f){200, 50});
    sfRectangleShape_setPosition(btn->shape, pos);
    sfText_setFont(btn->text, font);
    sfText_setString(btn->text, str);
    sfText_setCharacterSize(btn->text, 24);
    sfText_setPosition(btn->text, (sfVector2f){pos.x + 60, pos.y + 10});
}

void init_title(sfText **title, sfFont *font)
{
    sfFloatRect bounds;

    *title = sfText_create();
    sfText_setString(*title, "Game Over");
    sfText_setFont(*title, font);
    sfText_setCharacterSize(*title, 64);
    bounds = sfText_getLocalBounds(*title);
    sfText_setPosition(*title, (sfVector2f)
    {WINDOW_WIDTH / 2 - bounds.width / 2, 100});
}

sfBool is_mouse_over(sfVector2i mouse, sfVector2f pos)
{
    return mouse.x >= pos.x && mouse.x <= pos.x + 200 &&
        mouse.y >= pos.y && mouse.y <= pos.y + 50;
}
