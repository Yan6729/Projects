/*
** EPITECH PROJECT, 2025
** test wolf3d
** File description:
** window
*/

#include "../include/wolf3d_2.h"

void render_frame(game_t *game, float dt)
{
    update_particles(game->ps, dt);
    sfRenderWindow_clear(game->win.window, sfBlack);
    draw_floor_and_ceiling(game->win.window);
    cast_all_rays(game->win.window, *game->player,
    game->wall_texture, game->door_texture);
    handle_player_input(game->player);
    next_frame(game->player->inventory[game->player->current_weapon]);
    if (game->flashlight.enabled)
        draw_darkness_overlay(game->win.window);
    draw_flashlight(game->win.window, game);
    draw_hud(game->win.window, game->player, game->font);
    draw_weapon(game->win.window,
    game->player->inventory[game->player->current_weapon], 950, 820);
    draw_particles(game->win.window, game->ps);
    handle_weapon_switch(game->player, game->win.event);
    draw_blood_effect(game->win.window, game->player);
    draw_minimap(game->win.window, *game->player);
    sfRenderWindow_display(game->win.window);
}

void cut_handle_pause(game_t *game, int pause_result)
{
    if (pause_result == 0) {
        game->is_paused = false;
        return;
    }
    if (pause_result == 1) {
        restart_game(game->player);
        game->is_paused = false;
        return;
    }
    if (pause_result == 2) {
        sfRenderWindow_close(game->win.window);
        return;
    }
}

void handle_pause_menu(game_t *game)
{
    int pause_result = 0;

    if (sfKeyboard_isKeyPressed(sfKeyEscape) && !game->is_paused) {
        game->is_paused = true;
        pause_result = handle_pause(game->win.window);
        cut_handle_pause(game, pause_result);
    }
}
