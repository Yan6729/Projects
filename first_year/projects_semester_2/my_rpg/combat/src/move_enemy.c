/*
** EPITECH PROJECT, 2025
** dhj
** File description:
** djk
*/

#include "../include/my_enemies.h"

void move_enemy_towards(enemy_t *enemy, sfVector2f player_pos, float delta_time)
{
    sfVector2f direction = {
        player_pos.x - enemy->position.x,
        player_pos.y - enemy->position.y
    };
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {
        direction.x /= length;
        direction.y /= length;
        if (direction.x > 0)
            enemy->direction = 1;
        else
            enemy->direction = -1;
        enemy->position.x += direction.x * enemy->speed * delta_time;
        enemy->position.y += direction.y * enemy->speed * delta_time;
        float sprite_width = 152;
        float sprite_height = 209;
        if (enemy->position.x < 0)
            enemy->position.x = 0;
        if (enemy->position.x > 1920 - sprite_width)
            enemy->position.x = 1920 - sprite_width;
        if (enemy->position.y < 0)
            enemy->position.y = 0;
        if (enemy->position.y > 1080 - sprite_height)
            enemy->position.y = 1080 - sprite_height;
        sfSprite_setPosition(enemy->sprite, enemy->position);
    }
}
