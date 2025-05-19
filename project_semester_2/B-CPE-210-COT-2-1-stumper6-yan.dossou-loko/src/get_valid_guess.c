/*
** EPITECH PROJECT, 2025
** get_valid_guess.c
** File description:
** just a file
*/

#include "../include/stumper.h"

char get_valid_guess(game_t *game)
{
    char input[100];

    while (1) {
        printf("Your letter: ");
        if (!fgets(input, sizeof(input), stdin))
            exit_with_error("Error reading input\n", 0);
        input[strcspn(input, "\n")] = '\0';
        if (strlen(input) == 0 || strlen(input) > 1) {
            game->try--;
            return 84;
        }
        if (my_isalpha(input[0]) || input[0] == '_')
            return input[0];
        game->try--;
        display_game_state(game);
    }
}
