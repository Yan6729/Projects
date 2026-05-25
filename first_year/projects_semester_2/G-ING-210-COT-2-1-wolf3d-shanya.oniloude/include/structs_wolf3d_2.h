/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** all structures used
*/

#ifndef STRUCTSWOLF3D_H
    #define STRUCTSWOLF3D_H

    #include "libs_wolf3d_2.h"
    #define MAX_PARTICLES 1000
    #define MAX_PICKUPS 100
typedef enum {
    PICKUP_AMMO,
    PICKUP_HEALTH,
    PICKUP_KEY,
    PICKUP_TYPE_COUNT
} pickup_type_t;

typedef struct flashlight_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfBool enabled;
    sfVector2f sprite_size;
} flashlight_t;

typedef struct boss_s {
    float x;
    float y;
    sfSprite *sprite;
    sfTexture *texture;
    int is_alive;
} boss_t;

typedef struct {
    sfVector2f position;
    sfSprite *sprite;
    pickup_type_t type;
    int active;
} pickup_t;

typedef struct {
    sfVector2f position;
    float zoom;
} crosshair_t;

typedef struct window {
    sfRenderWindow *window;
    sfTexture *texture;
    sfEvent event;
    sfTexture *texture01;
    sfSprite *sprite;
    sfVector2f scalee;
    int tex_x;
    int tex_y;
    int draw_y;
    sfVertex pixel;
    sfColor color;
    float wall_height;
    float hit_x;
    float hit_y;
} win_t;

typedef struct {
    float distance;
    int block_type;
    float door_open_pos;
    float tex_pos;
    float hit_x;
    float hit_y;
    int side;
} rayhit_t;


typedef struct {
    char *name;
    sfTexture *texture;
    sfSprite *sprite;
    int frame_count;
    int damage;
    int current_frame;
    float frame_duration;
    sfIntRect frame_rect;
    sfClock *anim_clock;
    int ammo;
    int max_ammo;
    bool is_shooting;
    sfSound *shoot_sound;
    sfSoundBuffer *shoot_buffer;
} weapon_t;

typedef struct player {
    float x;
    float y;
    float angle;
    weapon_t *inventory[3];
    int current_weapon;
    float dirx;
    float diry;
    sfVector2f dir;
    float planex;
    float planey;
    int health;
    int score;
    int is_hurt;
    int hurt_alpha;
    sfRectangleShape *blood;
    sfVector2f size;
    sfVector2f pos;
    sfColor red;
    float ray_angle;
    crosshair_t crosshair;
}player_t;

typedef struct {
    sfRectangleShape *blood_overlay;
    int alpha;
} screen_effects_t;

typedef struct pause_menu_s {
    sfText **options;
    int selected;
    sfFont *font;
} pause_menu_t;

typedef struct particle {
    sfVector2f position;
    sfVector2f velocity;
    sfColor color;
    float life;
    float size;
} particle_t;

typedef struct {
    sfRectangleShape *shape;
    sfText *text;
    sfVector2f position;
} button_t;

typedef struct particlesystem {
    particle_t particles[MAX_PARTICLES];
    int count;
    sfVertexArray *vertices;
} particlesystem_t;

typedef struct {
    sfRenderWindow *window;
    sfFont *font;
} hud_t;

typedef struct {
    int x, y, w, h;
} room_t;

typedef struct {
    sfFont *font;
    sfText *text;
    sfRectangleShape *retry_button;
    sfText *retry_text;
    sfVector2f retry_pos;
    sfRectangleShape *quit_button;
    sfVector2f quit_pos;
    sfText *quit_text;
} reduce_t;

typedef struct {
    button_t retry;
    button_t quit;
    sfClock *clock;
    sfText *title;
} gameovermenu_t;

typedef struct {
    int column;
    float wall_height;
    float tex_pos;
    float width_factor;
    sfTexture *texture;
} render_params_t;

typedef struct {
    sfTexture *icons[3];
    sfSprite *sprites[3];
} weapon_icons_t;

typedef struct game_s {
    win_t win;
    sfView *view;
    player_t *player;
    weapon_t *weapon;
    particlesystem_t *ps;
    sfTexture *wall_texture;
    sfTexture *textures;
    sfTexture *door_texture;
    sfFont *font;
    sfClock *clock;
    bool is_paused;
    float zoom_level;
    sfBool is_zoomed;
    weapon_icons_t icons;
    sfRectangleShape *border;
    sfVector2f center;
    pickup_t pickups[MAX_PICKUPS];
    int pickup_count;
    flashlight_t flashlight;
    sfTexture *pickup_textures[PICKUP_TYPE_COUNT];
    int boss_door_unlocked;
    boss_t boss;
    int in_boss_room;
} game_t;

typedef struct {
    float rayDirX;
    float rayDirY;
    float rayPosX;
    float rayPosY;
    int mapX;
    int mapY;
    float deltaDistX;
    float deltaDistY;
    float sideDistX;
    float sideDistY;
    int stepX;
    int stepY;
} ray_params_t;


typedef struct {
    const char *name;
    const char *texture_path;
    int frame_count;
    int frame_width;
    int frame_height;
    int max_ammo;
    int damage;
    const char *sound_path;
} weapon_info_t;

typedef struct {
    render_params_t p;
    sfVector2u tex_size;
    float x;
    float y;
    float unit_width;
} sprite_info_t;


#endif
