/*
** EPITECH PROJECT, 2025
** game
** File description:
** loop
*/

#include "../include/wolf3d_2.h"

int init_resources(game_t *game)
{
    init_flashlight(game);
    game->win = all_for_window((sfVideoMode)
    {WINDOW_WIDTH, WINDOW_HEIGHT, 64}, "Sector42: Genesis");
    game->wall_texture = sfTexture_createFromFile("maps/1.png", NULL);
    game->door_texture = sfTexture_createFromFile("maps/Porte.png", NULL);
    game->font = sfFont_createFromFile("maps/Super Thick.otf");
    game->ps = create_particle_system();
    game->clock = sfClock_create();
    game->is_paused = false;
    if (!game->font || !game->wall_texture || !game->door_texture)
        return 84;
    sfRenderWindow_setFramerateLimit(game->win.window, 60);
    return 0;
}

sfMusic *play_music_loop(const char *filepath)
{
    sfMusic *music = sfMusic_createFromFile(filepath);

    if (!music) {
        printf("Erreur de chargement de la musique\n");
        return NULL;
    }
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return music;
}

void cleanup_resources(game_t *game)
{
    sfTexture_destroy(game->wall_texture);
    sfTexture_destroy(game->door_texture);
    sfFont_destroy(game->font);
    sfRenderWindow_destroy(game->win.window);
    sfClock_destroy(game->clock);
}

int game_loop(game_t *game)
{
    float dt = 0.0f;
    sfMusic *music = play_music_loop("snd/son.mp3");

    while (sfRenderWindow_isOpen(game->win.window)) {
        handle_game_events(game);
        dt = get_delta_time(game->clock);
        render_frame(game, dt);
        handle_pause_menu(game);
        if (game->player->health == 0)
            return 1;
    }
    sfMusic_destroy(music);
    return 0;
}

int game_window_2(player_t player)
{
    game_t game;
    weapon_t weapon;
    int result = 0;

    game.player = &player;
    game.weapon = &weapon;
    if (init_resources(&game) != 0)
        return 84;
    result = game_loop(&game);
    cleanup_resources(&game);
    return result;
}
