/*
** EPITECH PROJECT, 2025
** cast
** File description:
** single
*/

#include "../include/wolf3d_2.h"

void init_side_dists(ray_params_t *p)
{
    if (p->rayDirX < 0)
        p->sideDistX = (p->rayPosX - p->mapX) * p->deltaDistX;
    else
        p->sideDistX = (p->mapX + 1.0f - p->rayPosX) * p->deltaDistX;
    if (p->rayDirY < 0)
        p->sideDistY = (p->rayPosY - p->mapY) * p->deltaDistY;
    else
        p->sideDistY = (p->mapY + 1.0f - p->rayPosY) * p->deltaDistY;
}

ray_params_t init_ray_params(player_t player, float ray_angle)
{
    ray_params_t p;

    p.rayDirX = cosf(ray_angle);
    p.rayDirY = sinf(ray_angle);
    p.rayPosX = player.x / TILE_SIZE;
    p.rayPosY = player.y / TILE_SIZE;
    p.mapX = (int)p.rayPosX;
    p.mapY = (int)p.rayPosY;
    p.deltaDistX = fabsf(1.0f / p.rayDirX);
    p.deltaDistY = fabsf(1.0f / p.rayDirY);
    p.stepX = (p.rayDirX < 0) ? -1 : 1;
    p.stepY = (p.rayDirY < 0) ? -1 : 1;
    init_side_dists(&p);
    return p;
}

int dda_step(ray_params_t *p, int *side)
{
    if (p->sideDistX < p->sideDistY) {
        p->sideDistX += p->deltaDistX;
        p->mapX += p->stepX;
        *side = 0;
        return 1;
    } else {
        p->sideDistY += p->deltaDistY;
        p->mapY += p->stepY;
        *side = 1;
        return 1;
    }
    return 0;
}

void perform_dda_loop(ray_params_t *p, int *side)
{
    while (1) {
        dda_step(p, side);
        if (is_wall(p->mapX, p->mapY))
            break;
    }
}

void calculate_distance(ray_params_t *p, int side, rayhit_t *result)
{
    if (side == 0)
        result->distance = (p->sideDistX - p->deltaDistX) * TILE_SIZE;
    else
        result->distance = (p->sideDistY - p->deltaDistY) * TILE_SIZE;
}
