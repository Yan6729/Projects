/*
** EPITECH PROJECT, 2025
** pause
** File description:
** pause
*/

#include "../include/wolf3d_2.h"

void restart_game(player_t *player)
{
    generate_map();
    player->x = TILE_SIZE * 3.5f;
    player->y = TILE_SIZE * 3.5f;
    player->angle = 0.0f;
    player->health = 100;
    player->score = 0;
    player->is_hurt = 0;
    player->hurt_alpha = 0;
    player->current_weapon = 1;
    for (int i = 0; i < 3; i++)
        if (player->inventory[i]) {
            player->inventory[i]->ammo = player->inventory[i]->max_ammo;
            player->inventory[i]->current_frame = 0;
            sfClock_restart(player->inventory[i]->anim_clock);
            player->inventory[i]->frame_rect.left = 0;
            sfSprite_setTextureRect(player->inventory[i]->sprite,
    player->inventory[i]->frame_rect);
        }
}

pause_menu_t *init_pause_menu(void)
{
    pause_menu_t *menu = malloc(sizeof(pause_menu_t));
    const char *labels[] = {"Continuer", "Recommencer", "Quitter"};

    menu->font = sfFont_createFromFile("maps/Super Thick.otf");
    menu->options = malloc(sizeof(sfText *) * 3);
    for (int i = 0; i < 3; i++) {
        menu->options[i] = sfText_create();
        sfText_setFont(menu->options[i], menu->font);
        sfText_setString(menu->options[i], labels[i]);
        sfText_setCharacterSize(menu->options[i], 40);
        sfText_setPosition(menu->options[i], (sfVector2f){500, 300 + i * 70});
        sfText_setFillColor(menu->options[i], sfWhite);
    }
    menu->selected = 0;
    return menu;
}

int cut_display(int visible, pause_menu_t *menu, int i)
{
    if (visible)
        sfText_setFillColor(menu->options[i], sfYellow);
    else
        sfText_setFillColor(menu->options[i], sfTransparent);
}

void display_pause_menu(sfRenderWindow *win,
    pause_menu_t *menu, sfClock *clock)
{
    sfRectangleShape *overlay = sfRectangleShape_create();
    float time = 0.0;
    int visible = 0;

    sfRectangleShape_setSize(overlay, (sfVector2f){1280, 720});
    sfRectangleShape_setFillColor(overlay, sfColor_fromRGBA(0, 0, 0, 150));
    sfRenderWindow_drawRectangleShape(win, overlay, NULL);
    sfRectangleShape_destroy(overlay);
    time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    for (int i = 0; i < 3; i++) {
        if (i == menu->selected) {
            visible = ((int)(time * 2) % 2);
            cut_display(visible, menu, i);
        } else {
            sfText_setFillColor(menu->options[i], sfWhite);
        }
        sfRenderWindow_drawText(win, menu->options[i], NULL);
    }
}

void update_pause_menu(pause_menu_t *menu, sfEvent event)
{
    if (event.type == sfEvtKeyPressed)
        update_me(menu, event);
}
