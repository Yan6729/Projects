/*
** EPITECH PROJECT, 2025
** vdbn
** File description:
** fhdj
*/

#include "../include/my_enemies.h"

int main(void)
{
    
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    sfClock *clock = sfClock_create();
    window = sfRenderWindow_create(mode, "My RPG", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRectangleShape *player = sfRectangleShape_create();
    sfVector2f player_pos = {400.0f, 300.0f};
    sfRectangleShape_setSize(player, (sfVector2f){50.0f, 50.0f});
    sfRectangleShape_setFillColor(player, sfBlue);
    sfRectangleShape_setPosition(player, player_pos);
    int enemy_count = 1;
    sfVector2f enemy_positions[] = {
        {100.f, 100.f}
        // {200.f, 300.f},
        // {400.f, 150.f}
    };
 
    float player_x = 960, player_y = 540;
    float player_w = 50, player_h = 50;

    //int enemy_count = 2;
    float enemy_x[2] = {100, 500};
    float enemy_y[2] = {300, 600};
    float enemy_w = 152, enemy_h = 209;
    enemy_t **enemies = create_enemies("assets/0.png", enemy_positions, enemy_count);
    if (!enemies) {
        sfRenderWindow_destroy(window);
        sfClock_destroy(clock);
        return 1;
    }
    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfTime time = sfClock_restart(clock);
        float delta_time = sfTime_asSeconds(time);
        sfVector2f move = {0.0f, 0.0f};
        float speed = 200.0f;
        if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyUp))
            move.y -= speed * delta_time;
        if (sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyDown))
            move.y += speed * delta_time;
        if (sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyLeft))
            move.x -= speed * delta_time;
        if (sfKeyboard_isKeyPressed(sfKeyD) || sfKeyboard_isKeyPressed(sfKeyRight))
            move.x += speed * delta_time;
        player_pos.x += move.x;
        player_pos.y += move.y;
        sfRectangleShape_setPosition(player, player_pos);
        for (int i = 0; i < enemy_count; i++) {
            update_enemy(enemies[i], delta_time);
            if (is_player_in_range(enemies[i], player_pos, 200.0f)) {
                move_enemy_towards(enemies[i], player_pos, delta_time);
            }
        }
        printf("Player: %.2f, %.2f\n", player_x, player_y);
for (int i = 0; i < enemy_count; i++) {
    printf("Enemy %d: %.2f, %.2f\n", i, enemy_x[i], enemy_y[i]);
    if (check_collision_simple(player_x, player_y, player_w, player_h,
                               enemy_x[i], enemy_y[i], enemy_w * 0.5f, enemy_h * 0.5f)) {
        printf("Combat lancé avec l'ennemi %d !\n", i);
    }
}
        for (int i = 0; i < enemy_count; i++) {
    if (check_collision_simple(player_x, player_y, player_w, player_h,
                               enemy_x[i], enemy_y[i], enemy_w, enemy_h)) {
        start_combat_simple(i);
    }
}

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawRectangleShape(window, player, NULL);
        for (int i = 0; i < enemy_count; i++) {
            sfRenderWindow_drawSprite(window, enemies[i]->sprite, NULL);
        }
        sfRenderWindow_display(window);
    }
    sfRectangleShape_destroy(player);
    for (int i = 0; i < enemy_count; i++) {
        sfSprite_destroy(enemies[i]->sprite);
        sfTexture_destroy(enemies[i]->texture);
        sfClock_destroy(enemies[i]->animation_clock);
        free(enemies[i]);
    }
    free(enemies);
    sfRenderWindow_destroy(window);
    sfClock_destroy(clock);
    return 0;
}
