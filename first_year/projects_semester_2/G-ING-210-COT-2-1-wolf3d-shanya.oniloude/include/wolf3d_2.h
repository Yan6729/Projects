/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** header
*/

#include "libs_wolf3d_2.h"
#include "structs_wolf3d_2.h"
#ifndef WOLF3D_H
    #define WOLF3D_H
    #define RWC sfRenderWindow_create
    #define TILE_SIZE 64
    #define MAP_WIDTH 80
    #define MAP_HEIGHT 50
    #define WINDOW_WIDTH 1920
    #define WINDOW_HEIGHT 1080
    #define FOV (M_PI / 3)
    #define NUM_RAYS 1920
    #define PLAYER_SPEED 10.0f
    #define WEAPON_FRAME_WIDTH 326
    #define WEAPON_FRAME_HEIGHT 594
    #define WEAPON_FRAME_COUNT 4
    #define WEAPON_ANIM_SPEED 10
    #define EMPTY 0
    #define WALL 1
    #define DOOR 2
    #define START_X 100
    #define START_Y 100
    #define OPEN_DOOR 3
    #define BOSS_TILE_X 10
    #define BOSS_TILE_Y	5
    #define BOSS_DOOR	9
extern int map[MAP_HEIGHT][MAP_WIDTH];
void show_game_over_screen(int *running);
int run_game_loop(void);
void init_player(player_t *player);
int is_wall(int x, int y);
void draw_minimap(sfRenderWindow *window, player_t player);
void draw_floor_and_ceiling(sfRenderWindow *window);
void handle_player_input(player_t *player);
void cast_all_rays(sfRenderWindow *window, player_t player,
    sfTexture *texture, sfTexture *door_texture);
int game_window_2(player_t player);
void generate_map(void);
void restart_game(player_t *player);
int is_door_in_front(player_t *player);
void open_door(player_t *player);
void draw_game(sfRenderWindow *window, player_t player,
    sfTexture *wall_texture, sfTexture *door_texture);
void draw_weapon(sfRenderWindow *window, weapon_t *weapon, int x, int y);
void handle_weapon_switch(player_t *player, sfEvent event);
void next_frame(weapon_t *weapon);
rayhit_t cast_single_ray(player_t player, float ray_angle);
void try_open_door(player_t *player);
void draw_hud(sfRenderWindow *window, player_t *player, sfFont *font);
void init_blood_overlay(screen_effects_t *effects);
void take_damage(screen_effects_t *effects, int damage);
void update_blood_overlay(screen_effects_t *effects);
void player_take_damage(player_t *player, int damage);
void draw_blood_effect(sfRenderWindow *window, player_t *player);
void animate(weapon_t *w);
void spawn_particles(particlesystem_t *ps,
    sfVector2f pos, int count, sfColor color);
particlesystem_t *create_particle_system(void);
void update_particles(particlesystem_t *ps, float delta_time);
int draw_game_over_menu(sfRenderWindow *window, sfFont *font);
bool handle_game_over_screen(sfRenderWindow *window, sfFont *font);
void restart_game(player_t *player);
win_t all_for_window(sfVideoMode size, char *title);
int handle_pause(sfRenderWindow *win);
void update_pause_menu(pause_menu_t *menu, sfEvent event);
void display_pause_menu(sfRenderWindow *win,
    pause_menu_t *menu, sfClock *clock);
pause_menu_t *init_pause_menu(void);
void draw_particles(sfRenderWindow *window, particlesystem_t *ps);
void shoot(player_t *player, particlesystem_t *ps);
void animate_weapon(weapon_t *w);
void trigger_shot(weapon_t *weapon);
void init_button(button_t *btn, sfFont *font, const char *str, sfVector2f pos);
void init_title(sfText **title, sfFont *font);
sfBool is_mouse_over(sfVector2i mouse, sfVector2f pos);
void update_and_draw(sfRenderWindow *window, gameovermenu_t *menu, int *blink);
int game_over_loop(sfRenderWindow *window, gameovermenu_t *menu);
void draw_elements(sfRenderWindow *window, sfText *title,
    button_t *retry, button_t *quit);
int handle_event(sfEvent *event, sfRenderWindow *window, gameovermenu_t *menu);
int process_events(sfRenderWindow *window, gameovermenu_t *menu);
void destroy_all(sfText *title, button_t *retry,
    button_t *quit, sfClock *clock);
void update_button_colors(button_t *retry, button_t *quit,
    sfVector2i mouse, int blink);
void restart_game(player_t *player);
int cut_display(int visible, pause_menu_t *menu, int i);
void display_pause_menu(sfRenderWindow *win,
    pause_menu_t *menu, sfClock *clock);
pause_menu_t *init_pause_menu(void);
void update_me(pause_menu_t *menu, sfEvent event);
void update_pause_menu(pause_menu_t *menu, sfEvent event);
float get_delta_time(sfClock *clock);
void handle_game_events(game_t *game);
void render_frame(game_t *game, float dt);
void handle_pause_menu(game_t *game);
weapon_t *load_weapon(const weapon_info_t *info);
void handle_weapon_switch(player_t *player, sfEvent event);
void draw_weapon(sfRenderWindow *window, weapon_t *weapon, int x, int y);
ray_params_t init_ray_params(player_t player, float ray_angle);
int dda_step(ray_params_t *p, int *side);
void calculate_distance(ray_params_t *p, int side, rayhit_t *result);
void perform_dda_loop(ray_params_t *p, int *side);
void calculate_hit_pos(ray_params_t *p, rayhit_t *result, player_t player);
void connect_rooms_with_doors(void);
void create_room(room_t r);
void divide(room_t r, int depth);
void carve_v_with_door(int y1, int y2, int x);
void carve_h_with_door(int x1, int x2, int y);
void carve_room(room_t r);
void draw_me(sfRectangleShape *tile, const int scale,
    sfRenderWindow *window, int y);
void init_map(void);
void carve_corridor_with_door(int a1, int a2, int fixed, bool horizontal);
void car(room_t r, int i);
void init_icons(game_t *game);
void draw_inventory(sfRenderWindow *window, game_t *game, player_t *player);
void destroy_icons(game_t *game);
void draw_crosshair(sfRenderWindow *window);
void update_crosshair(crosshair_t *crosshair, float dt);
void update_zoom(game_t *game);
void init_pickups(game_t *game);
void load_pickup_textures(sfTexture **textures);
void draw_pickups(game_t *game, sfRenderWindow *window);
void spawn_pickups_after_map(game_t *game);
int init_flashlight(game_t *game);
void draw_darkness_overlay(sfRenderWindow *window);
void draw_flashlight(sfRenderWindow *window, game_t *game);
int play_hangman_sfml(const char *dictionary_file);
void player_take_score(player_t *player, int point);
void load_boss_room(game_t *game, player_t *player);
void place_boss_door_random(void);
void draw_boss_door(sfRenderWindow *window);
void teleport_player_to_boss_door(player_t *player);
void init_boss(game_t *game);
void input(player_t *player, int result);
void draw_sprite(game_t *game, float sprite_x,
    float sprite_y, sfSprite *sprite);
#endif
