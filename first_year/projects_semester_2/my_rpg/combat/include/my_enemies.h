/*
** EPITECH PROJECT, 2025
** bn
** File description:
** dbn
*/

#ifndef MY_ENEMIES
   #include <SFML/Graphics.h>
   #include <SFML/Audio.h>
   #include <SFML/System.h>
   #include <sys/stat.h>
   #include <string.h>
   #include <fcntl.h>
   #include <unistd.h>
   #include <stdlib.h>
   #include <stdio.h>
   #include <stdbool.h>
   #include <math.h>
   #define MY_ENEMIES



#include <SFML/Graphics.h>

typedef struct enemy_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f velocity;
    int direction;
    sfTexture *texture_right;   // marche droite
    sfTexture *texture_left; 
    sfClock *animation_clock;
    int current_frame;
    int frame_count;
    float speed;
    int is_alive;
} enemy_t;

typedef struct player_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f size;      // Hitbox du joueur (largeur, hauteur)
    int hp;               // Points de vie
    int attack_power;     // Puissance d'attaque (exemple)
} player_t;


enemy_t *create_enemy(const char *texture_path, sfVector2f start_pos);
void update_enemy(enemy_t *enemy, float delta_time);
void draw_enemy(sfRenderWindow *window, enemy_t *enemy);
void destroy_enemy(enemy_t *enemy);
int is_player_in_range(enemy_t *enemy, sfVector2f player_pos, float vision_radius);
int is_colliding_with_player(enemy_t *enemy, sfFloatRect player_bounds);
void move_enemy_towards(enemy_t *enemy, sfVector2f player_pos, float delta_time);
void destroy_enemy(enemy_t *enemy);
enemy_t *create_enemy(const char *texture_path, sfVector2f start_pos);
enemy_t **create_enemies(const char *texture_path, sfVector2f *positions, int count);
int check_collision_simple(float x1, float y1, float w1, float h1,
float x2, float y2, float w2, float h2);
void start_combat(player_t *player, enemy_t *enemy);
void start_combat_simple(int enemy_id);
#endif
