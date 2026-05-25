/*
** EPITECH PROJECT, 2025
** ray
** File description:
** casting
*/

#include "../include/wolf3d_2.h"

void calculate_tex_pos(rayhit_t *result)
{
    float tex_x;

    if (result->side == 0)
        tex_x = fmodf(result->hit_y, TILE_SIZE) / TILE_SIZE;
    else
        tex_x = fmodf(result->hit_x, TILE_SIZE) / TILE_SIZE;
    result->tex_pos = tex_x;
}

rayhit_t cast_single_ray(player_t player, float ray_angle)
{
    rayhit_t result = {0};
    ray_params_t p = init_ray_params(player, ray_angle);
    int side;

    perform_dda_loop(&p, &side);
    calculate_distance(&p, side, &result);
    calculate_hit_pos(&p, &result, player);
    result.side = side;
    calculate_tex_pos(&result);
    return result;
}
