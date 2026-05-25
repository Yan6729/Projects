/*
** EPITECH PROJECT, 2025
** dhj
** File description:
** dhjks
*/

#include "../include/my_enemies.h"

int is_player_in_range(enemy_t *enemy, sfVector2f player_pos, float vision_radius)
{
    float dx = player_pos.x - enemy->position.x;
    float dy = player_pos.y - enemy->position.y;
    float distance = sqrt(dx * dx + dy * dy);
    return distance < vision_radius;
}
int is_colliding_with_player(enemy_t *enemy, sfFloatRect player_bounds)
{
    sfFloatRect enemy_bounds = sfSprite_getGlobalBounds(enemy->sprite);
    return sfFloatRect_intersects(&enemy_bounds, &player_bounds, NULL);
}

int check_collision_simple(float x1, float y1, float w1, float h1,
                           float x2, float y2, float w2, float h2)
{
    return (x1 < x2 + w2) &&
           (x1 + w1 > x2) &&
           (y1 < y2 + h2) &&
           (y1 + h1 > y2);
}
