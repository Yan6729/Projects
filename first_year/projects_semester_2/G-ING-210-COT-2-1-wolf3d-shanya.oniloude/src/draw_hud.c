/*
** EPITECH PROJECT, 2025
** draw
** File description:
** hud
*/
#include "../include/wolf3d_2.h"
void draw_health_bar(hud_t *hud, player_t *player)
{
    sfRectangleShape *back = sfRectangleShape_create();
    sfRectangleShape *front = sfRectangleShape_create();
    sfVector2f pos = {WINDOW_WIDTH / 2 + 675, 1};
    sfVector2f back_size = {200, 20};
    sfVector2f front_size = {2 * player->health, 20};

    sfRectangleShape_setPosition(back, pos);
    sfRectangleShape_setSize(back, back_size);
    sfRectangleShape_setFillColor(back, sfColor_fromRGB(50, 50, 50));
    sfRectangleShape_setOutlineColor(back, sfWhite);
    sfRectangleShape_setOutlineThickness(back, 2);
    sfRectangleShape_setPosition(front, pos);
    sfRectangleShape_setSize(front, front_size);
    sfRectangleShape_setFillColor(front, sfRed);
    sfRenderWindow_drawRectangleShape(hud->window, back, NULL);
    sfRenderWindow_drawRectangleShape(hud->window, front, NULL);
    sfRectangleShape_destroy(back);
    sfRectangleShape_destroy(front);
}

void draw_text(hud_t *hud, sfVector2f pos, const char *str, sfColor color)
{
    sfText *text = sfText_create();

    if (!text || !hud || !hud->font)
        return;
    sfText_setFont(text, hud->font);
    sfText_setCharacterSize(text, 24);
    sfText_setFillColor(text, color);
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfRenderWindow_drawText(hud->window, text, NULL);
    sfText_destroy(text);
}

void draw_ammo(hud_t *hud, player_t *player)
{
    weapon_t *w;
    char ammo_str[64];
    sfVector2f ammo_pos;

    if (!player || !hud)
        return;
    w = player->inventory[player->current_weapon];
    if (!w)
        return;
    snprintf(ammo_str, sizeof(ammo_str), "Armes: %d/%d", w->ammo, w->max_ammo);
    ammo_pos = (sfVector2f){WINDOW_WIDTH - 200, 950};
    draw_text(hud, ammo_pos, ammo_str, sfWhite);
}

void draw_score(hud_t *hud, player_t *player)
{
    char score_str[32];
    sfVector2f score_pos;

    if (!player || !hud)
        return;
    snprintf(score_str, sizeof(score_str), "Score: %d", player->score);
    score_pos = (sfVector2f){30, 950};
    draw_text(hud, score_pos, score_str, sfYellow);
}

void draw_hud(sfRenderWindow *window, player_t *player, sfFont *font)
{
    hud_t hud = { window, font };

    draw_health_bar(&hud, player);
    draw_crosshair(window);
    draw_ammo(&hud, player);
    draw_score(&hud, player);
}
