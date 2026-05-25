/*
** EPITECH PROJECT, 2025
** inventory
** File description:
** in
*/

#include "../include/wolf3d_2.h"

weapon_t *create_weapon_struct(const char *name, int max_ammo, int damage)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    weapon->anim_clock = sfClock_create();
    weapon->name = strdup(name);
    weapon->ammo = max_ammo;
    weapon->max_ammo = max_ammo;
    weapon->damage = damage;
    return weapon;
}

void setup_weapon_graphics(weapon_t *weapon, const char *texture_path,
    int frame_count, sfIntRect frame_rect)
{
    weapon->texture = sfTexture_createFromFile(texture_path, NULL);
    weapon->sprite = sfSprite_create();
    sfSprite_setTexture(weapon->sprite, weapon->texture, sfTrue);
    weapon->frame_count = frame_count;
    weapon->current_frame = 0;
    weapon->frame_rect = frame_rect;
    sfSprite_setTextureRect(weapon->sprite, frame_rect);
}

weapon_t *load_weapon(const weapon_info_t *info)
{
    weapon_t *weapon = create_weapon_struct
    (info->name, info->max_ammo, info->damage);
    sfIntRect rect = {0, 0, info->frame_width, info->frame_height};

    weapon->shoot_buffer = sfSoundBuffer_createFromFile(info->sound_path);
    weapon->shoot_sound = sfSound_create();
    sfSound_setBuffer(weapon->shoot_sound, weapon->shoot_buffer);
    setup_weapon_graphics(weapon, info->texture_path, info->frame_count, rect);
    return weapon;
}

void draw_weapon(sfRenderWindow *window, weapon_t *weapon, int x, int y)
{
    sfVector2f pos = {x, y};

    sfSprite_setPosition(weapon->sprite, pos);
    sfRenderWindow_drawSprite(window, weapon->sprite, NULL);
}

void handle_weapon_switch(player_t *player, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyNum1) {
            player->current_weapon = 0;
        }
        if (event.key.code == sfKeyNum2) {
            player->current_weapon = 1;
            return;
        }
        if (event.key.code == sfKeyNum3) {
            player->current_weapon = 2;
            return;
        }
    }
}
