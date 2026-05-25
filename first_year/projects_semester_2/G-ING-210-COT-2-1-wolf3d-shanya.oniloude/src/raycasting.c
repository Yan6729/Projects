/*
** EPITECH PROJECT, 2025
** raycasting
** File description:
** architect
*/

#include "../include/wolf3d_2.h"

sfSprite *create_wall_sprite(sprite_info_t info)
{
    sfSprite *sprite = sfSprite_create();
    sfIntRect rect = {
        .left = (int)(info.p.tex_pos * info.tex_size.x),
        .top = 0,
        .width = 1,
        .height = info.tex_size.y
    };
    sfVector2f pos = { info.x, info.y };
    sfVector2f scale = {
        info.p.width_factor * info.unit_width,
        info.p.wall_height / info.tex_size.y
    };

    sfSprite_setTexture(sprite, info.p.texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

void render_wall_column_with_texture(sfRenderWindow *window, render_params_t p)
{
    sfSprite *sprite;
    float unit_width = (float)WINDOW_WIDTH / NUM_RAYS;
    float x_offset = ((1.0f - p.width_factor) / 2.0f) * unit_width;
    float x = p.column * unit_width + x_offset;
    float y = (WINDOW_HEIGHT / 2.0f) - (p.wall_height / 2.0f);
    sprite_info_t info = { p, sfTexture_getSize(p.texture), x, y, unit_width };

    if (p.tex_pos >= 1.0f)
        p.tex_pos = 0.9999f;
    sprite = create_wall_sprite(info);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
}

void cast_all_rays(sfRenderWindow *window, player_t player,
    sfTexture *wall_texture, sfTexture *door_texture)
{
    float start_angle = player.angle - (FOV / 2);
    rayhit_t hit;
    float corrected;
    render_params_t params;

    for (int i = 0; i < NUM_RAYS; ++i) {
        player.ray_angle = start_angle + i * (FOV / (NUM_RAYS - 1));
        hit = cast_single_ray(player, player.ray_angle);
        corrected = hit.distance * cosf(player.ray_angle - player.angle);
        params = (render_params_t){
            .column = i,
            .wall_height = (TILE_SIZE / corrected) *
            ((WINDOW_WIDTH / 2) / tanf(FOV / 2)),
            .tex_pos = hit.tex_pos,
            .width_factor = (hit.block_type == DOOR) ?
            fmaxf(0.1f, 1.0f - hit.door_open_pos) : 1.0f,
            .texture = (hit.block_type == DOOR) ? door_texture : wall_texture
        };
        render_wall_column_with_texture(window, params);
    }
}

void try_move_player(player_t *player, float dx, float dy)
{
    float next_x = player->x + dx;
    float next_y = player->y + dy;

    if (!is_wall(next_x / TILE_SIZE, next_y / TILE_SIZE)) {
        player->x = next_x;
        player->y = next_y;
    }
}

void handle_player_input(player_t *player)
{
    float cos_a = cosf(player->angle);
    float sin_a = sinf(player->angle);

    if (sfKeyboard_isKeyPressed(sfKeyUp))
        try_move_player(player, cos_a * PLAYER_SPEED, sin_a * PLAYER_SPEED);
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        try_move_player(player, -cos_a * PLAYER_SPEED, -sin_a * PLAYER_SPEED);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        player->angle -= 0.05f;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        player->angle += 0.05f;
    if (sfKeyboard_isKeyPressed(sfKeyE))
        try_open_door(player);
}
