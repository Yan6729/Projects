/*
** EPITECH PROJECT, 2025
** draw
** File description:
** draw
*/

#include "../include/wolf3d_2.h"

void next_frame(weapon_t *weapon)
{
    if (!weapon->is_shooting)
        return;
    if (sfTime_asMilliseconds
        (sfClock_getElapsedTime(weapon->anim_clock)) > WEAPON_ANIM_SPEED) {
        weapon->current_frame++;
        if (weapon->current_frame >= weapon->frame_count) {
            weapon->current_frame = 0;
            weapon->is_shooting = false;
        }
        weapon->frame_rect.left = weapon->current_frame
        * weapon->frame_rect.width;
        sfSprite_setTextureRect(weapon->sprite, weapon->frame_rect);
        sfClock_restart(weapon->anim_clock);
    }
}

void init_player(player_t *player)
{
    weapon_info_t infos[3] = {
        {"Knife", "maps/couteau.png", 4, 250, 250, 20, 5, "snd/couteau.mp3"},
        {"Gun", "maps/pistolet.png", 4, 260, 220, 20, 20,
    "snd/intro_shoot.mp3"},
        {"Grenade", "maps/paralysant.png", 4, 220, 220, 20, 40, "snd/tran.mp3"}
    };

    player->x = TILE_SIZE * 3.5f;
    player->y = TILE_SIZE * 3.5f;
    player->angle = 0.0f;
    for (int i = 0; i < 3; i++) {
        player->inventory[i] = load_weapon(&infos[i]);
    }
    player->current_weapon = 1;
    player->health = 100;
    player->score = 20;
}

void draw_floor_and_ceiling(sfRenderWindow *window)
{
    sfRectangleShape *floor = sfRectangleShape_create();
    sfVector2f size = {WINDOW_WIDTH, WINDOW_HEIGHT / 2};

    sfRectangleShape_setSize(floor, size);
    sfRectangleShape_setPosition(floor, (sfVector2f){0, WINDOW_HEIGHT / 2});
    sfRectangleShape_setFillColor(floor, sfColor_fromRGB(50, 50, 50));
    sfRenderWindow_drawRectangleShape(window, floor, NULL);
    sfRectangleShape_destroy(floor);
}

void draw_minimap(sfRenderWindow *window, player_t player)
{
    const int scale = 4;
    sfRectangleShape *tile = sfRectangleShape_create();
    sfCircleShape *player_circle = sfCircleShape_create();
    sfVector2f pos;

    for (int y = 0; y < MAP_HEIGHT; y++) {
        draw_me(tile, scale, window, y);
    }
    sfCircleShape_setRadius(player_circle, 3);
    sfCircleShape_setFillColor(player_circle, sfRed);
    sfCircleShape_setPosition(player_circle,
    (sfVector2f)
    {player.x / TILE_SIZE * scale - 3, player.y / TILE_SIZE * scale - 3});
    sfRenderWindow_drawCircleShape(window, player_circle, NULL);
    sfRectangleShape_destroy(tile);
    sfCircleShape_destroy(player_circle);
}

void generate_map(void)
{
    room_t initial = {1, 1, MAP_WIDTH - 2, MAP_HEIGHT - 2};

    init_map();
    divide(initial, 5);
    connect_rooms_with_doors();
}
