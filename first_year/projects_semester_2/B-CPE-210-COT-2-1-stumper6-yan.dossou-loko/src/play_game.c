/*
** EPITECH PROJECT, 2025
** play_gamec
** File description:
** just a file
*/

#include "../include/stumper.h"

void play_game(game_t *game)
{
    char guess;

    while (game->try > 0 && !is_game_won(game)) {
        display_game_state(game);
        guess = get_valid_guess(game);
        if (guess == 84)
            continue;
        process_guess(game, guess);
    }
    display_game_state(game);
    if (is_game_won(game)) {
        printf("Congratulations!\n");
    } else {
        printf("You lost!\n");
    }
}
