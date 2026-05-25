/*
** EPITECH PROJECT, 2025
** draw
** File description:
** draw
*/
#include "../include/wolf3d_2.h"

int map[MAP_HEIGHT][MAP_WIDTH];

int is_wall(int x, int y)
{
    if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT)
        return 1;
    return (map[y][x] != 0);
}

void calculate_hit_pos(ray_params_t *p, rayhit_t *result, player_t player)
{
    result->hit_x = player.x + result->distance * p->rayDirX;
    result->hit_y = player.y + result->distance * p->rayDirY;
    result->block_type = map[p->mapY][p->mapX];
    result->door_open_pos = 0.0f;
}

void try_open_door(player_t *player)
{
    int front_x = (player->x + cos(player->angle) * TILE_SIZE) / TILE_SIZE;
    int front_y = (player->y + sin(player->angle) * TILE_SIZE) / TILE_SIZE;

    if (map[front_y][front_x] == DOOR)
        map[front_y][front_x] = EMPTY;
}

void init_map(void)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
        for (int x = 0; x < MAP_WIDTH; x++)
            map[y][x] = WALL;
}

void car(room_t r, int i)
{
    for (int j = r.x; j < r.x + r.w; j++) {
        if (i >= 0 && i < MAP_HEIGHT && j >= 0 && j < MAP_WIDTH)
            map[i][j] = EMPTY;
    }
}

void carve_corridor_with_door(int a1, int a2, int fixed, bool horizontal)
{
    int door = a1 + rand() % (abs(a2 - a1) + 1);
    int min = fmin(a1, a2);
    int max = fmax(a1, a2);

    for (int i = min; i <= max; i++) {
        if (horizontal)
            map[fixed][i] = (i == door) ? DOOR : EMPTY;
        else
            map[i][fixed] = (i == door) ? DOOR : EMPTY;
    }
}
