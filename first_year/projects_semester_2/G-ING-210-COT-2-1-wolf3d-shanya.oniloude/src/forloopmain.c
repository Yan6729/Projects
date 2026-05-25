/*
** EPITECH PROJECT, 2025
** main
** File description:
** loop
*/
#include "../include/wolf3d_2.h"

win_t all_for_window(sfVideoMode size, char *title)
{
    win_t win;

    win.window = RWC(size, title, sfClose, NULL);
    return win;
}

float get_delta_time(sfClock *clock)
{
    sfTime elapsed = sfClock_restart(clock);

    return sfTime_asSeconds(elapsed);
}

void analyse_events(game_t *game)
{
    sfEvent *event = &game->win.event;

    if (event->type == sfEvtClosed)
        sfRenderWindow_close(game->win.window);
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeySpace)
        player_take_damage(game->player, 10);
    if (event->type == sfEvtMouseButtonPressed
        && event->mouseButton.button == sfMouseLeft)
        shoot(game->player, game->ps);
        if (event->type == sfEvtKeyPressed && event->key.code == sfKeyF)
        game->flashlight.enabled = !game->flashlight.enabled;
}

void handle_game_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->win.window, &game->win.event))
        analyse_events(game);
}
