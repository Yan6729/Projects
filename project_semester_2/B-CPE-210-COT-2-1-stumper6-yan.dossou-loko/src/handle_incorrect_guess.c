/*
** EPITECH PROJECT, 2025
** handle_incorrect_guess.c
** File description:
** just a file
*/

#include "../include/stumper.h"

void handle_incorrect_guess(game_t *game, char guess)
{
    game->try--;
    printf("%c: n'est pas dans ce mot\n", guess);
}
