/*
** EPITECH PROJECT, 2025
** create
** File description:
** create
*/

#include "../include/my_enemies.h"

enemy_t *create_enemy(const char *texture_path, sfVector2f start_pos)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    enemy->texture = sfTexture_createFromFile(texture_path, NULL);
    enemy->sprite = sfSprite_create();
    enemy->position = start_pos;
    enemy->animation_clock = sfClock_create();
    enemy->current_frame = 0;
    enemy->frame_count = 4;
    enemy->speed = 100.0f;

    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    sfSprite_setScale(enemy->sprite, (sfVector2f){1.0f, 1.0f}); 

    sfIntRect rect = {0, 0, 152, 209};
    sfSprite_setTextureRect(enemy->sprite, rect);
    sfSprite_setPosition(enemy->sprite, enemy->position);
    return enemy;
}

enemy_t **create_enemies(const char *texture_path, sfVector2f *positions, int count)
{
    enemy_t **enemies = malloc(sizeof(enemy_t*) * count);

    if (!enemies)
        return NULL;
    for (int i = 0; i < count; i++) {
        enemies[i] = create_enemy(texture_path, positions[i]);
        if (!enemies[i]) {
            for (int j = 0; j < i; j++) {
                sfSprite_destroy(enemies[j]->sprite);
                sfTexture_destroy(enemies[j]->texture);
                sfClock_destroy(enemies[j]->animation_clock);
                free(enemies[j]);
            }
            free(enemies);
            return NULL;
        }
    }
    return enemies;
}

