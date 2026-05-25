/*
** EPITECH PROJECT, 2025
** shoot
** File description:
** shoot
*/
#include "../include/wolf3d_2.h"
void animate(weapon_t *w)
{
    sfVector2f offset = {5, 0};

    sfSprite_move(w->sprite, offset);
}

sfColor get_weapon_color(int weapon_id)
{
    switch (weapon_id) {
    case 0:
        return sfColor_fromRGB(255, 0, 0);
    case 1:
        return sfColor_fromRGB(255, 255, 0);
    case 2:
        return sfColor_fromRGB(255, 165, 0);
    default:
        return sfWhite;
    }
}

void shoot(player_t *player, particlesystem_t *ps)
{
    weapon_t *w = player->inventory[player->current_weapon];
    sfColor effect_color;
    sfVector2f origin;

    if (w->ammo <= 0)
        return;
    w->ammo--;
    animate(w);
    w->is_shooting = true;
    sfSound_play(player->inventory[player->current_weapon]->shoot_sound);
    sfClock_restart(w->anim_clock);
    effect_color = get_weapon_color(player->current_weapon);
    origin = (sfVector2f){960, 540};
    spawn_particles(ps, origin, 20, effect_color);
}
