/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** just a file
*/

#include "../include/stumper.h"

int main(int argc, char *argv[])
{
    int tries = DEFAULT_TRIES;
    dict_t *dict;
    game_t game;

    if (argc < 2 || argc > 3)
        exit_with_error("Usage: ./hangman dictionary_file [tries]\n", 84);
    if (argc == 3) {
        tries = atoi(argv[2]);
        if (tries <= 0 || is_positive_integer(argv[2]) == 84)
            exit_with_error("Number of tries must be positive\n", 84);
    }
    dict = recup(argv[1]);
    if (dict->count == 0)
        exit_with_error("Dictionary is empty or invalid\n", 84);
    init_game(&game, dict, tries);
    play_game(&game);
    free_game(&game);
    free_dictionary(dict);
    return 0;
}
