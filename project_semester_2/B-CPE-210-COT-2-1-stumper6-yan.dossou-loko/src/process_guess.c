/*
** EPITECH PROJECT, 2025
** process_guess.c
** File description:
** just a file
*/

#include "../include/stumper.h"

int process_guess(game_t *game, char guess)
{
    int found = 0;

    for (int i = 0; i < game->len_dev; i++) {
        if (handle_underscore_guess(game, i, guess) == 0)
            found = 1;
        if (handle_regular_guess(game, i, guess) == 0)
            found = 1;
    }
    if (found == 0)
        handle_incorrect_guess(game, guess);
    return found;
}
