/*
** EPITECH PROJECT, 2025
** bdn,
** File description:
** fdj
*/

#include "../include/my_enemies.h"

#include <stdlib.h>

void draw_enemy(sfRenderWindow *window, enemy_t *enemy)
{
    if (enemy->is_alive)
        sfRenderWindow_drawSprite(window, enemy->sprite, NULL);
}

void update_enemy(enemy_t *enemy, float delta_time)
{
    int frame_width = 152;
    int frame_height = 209;
    sfTime time = sfClock_getElapsedTime(enemy->animation_clock);
    float seconds = sfTime_asSeconds(time);
    int frame_y = (enemy->direction == -1) ? 209 : 0;
    sfIntRect rect = {
            enemy->current_frame * frame_width,
            frame_y,
            frame_width,
            frame_height
        };

    if (seconds > 0.15f) {
        enemy->current_frame = (enemy->current_frame + 1) % enemy->frame_count;
        sfSprite_setTextureRect(enemy->sprite, rect);
        sfClock_restart(enemy->animation_clock);
    }
}