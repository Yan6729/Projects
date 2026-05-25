/*
** EPITECH PROJECT, 2025
** torche
** File description:
** torche
*/

#include "../include/wolf3d_2.h"

int init_flashlight(game_t *game)
{
    flashlight_t *f = &game->flashlight;

    f->texture = sfTexture_createFromFile("maps/torche.png", NULL);
    if (!f->texture)
        return 84;
    f->sprite = sfSprite_create();
    if (!f->sprite)
        return 84;
    sfSprite_setTexture(f->sprite, f->texture, sfTrue);
    f->enabled = sfFalse;
    return 0;
}

void destroy_flashlight(game_t *game)
{
    sfSprite_destroy(game->flashlight.sprite);
    sfTexture_destroy(game->flashlight.texture);
}

void draw_flashlight(sfRenderWindow *window, game_t *game)
{
    sfVector2f center;
    flashlight_t *f = &game->flashlight;
    sfVector2u tex_size = sfTexture_getSize(f->texture);

    if (!game->flashlight.enabled)
        return;
    center = (sfVector2f) {
    game->player->pos.x * TILE_SIZE - tex_size.x / 2.0f,
    game->player->pos.y * TILE_SIZE - tex_size.y / 2.0f
    };
    sfSprite_setPosition(f->sprite, center);
    sfRenderWindow_drawSprite(window, f->sprite, NULL);
}

void draw_darkness_overlay(sfRenderWindow *window)
{
    sfRectangleShape *darkness = sfRectangleShape_create();
    sfVector2f size = {(float)WINDOW_WIDTH, (float)WINDOW_HEIGHT};
    sfColor color;

    sfRectangleShape_setSize(darkness, size);
    color = sfColor_fromRGBA(0, 0, 0, 180);
    sfRectangleShape_setFillColor(darkness, color);
    sfRenderWindow_drawRectangleShape(window, darkness, NULL);
    sfRectangleShape_destroy(darkness);
}
