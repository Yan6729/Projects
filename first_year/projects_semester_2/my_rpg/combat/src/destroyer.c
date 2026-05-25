/*
** EPITECH PROJECT, 2025
** detroyer.c
** File description:
** dstroy
*/

#include "../include/my_enemies.h"

void destroy_enemy(enemy_t *enemy)
{
    sfSprite_destroy(enemy->sprite);
    sfTexture_destroy(enemy->texture);
    sfClock_destroy(enemy->animation_clock);
    free(enemy);
}

