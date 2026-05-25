/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** main
*/

#include "../include/wolf3d_2.h"

void show_game_over_screen(int *running)
{
    sfFont *font = sfFont_createFromFile("maps/Super Thick.otf");
    win_t temp_win = all_for_window((sfVideoMode)
    {WINDOW_WIDTH, WINDOW_HEIGHT, 64}, "Sector42: Genesis");

    *running = draw_game_over_menu(temp_win.window, font);
    sfRenderWindow_destroy(temp_win.window);
    sfFont_destroy(font);
}

int run_game_loop(void)
{
    int running = 1;
    player_t player;

    while (running) {
        generate_map();
        init_player(&player);
        if (game_window_2(player) == 1)
            show_game_over_screen(&running);
        else
            running = 0;
    }
    return 0;
}
