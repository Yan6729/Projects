/*
** EPITECH PROJECT, 2025
** stumper.h
** File description:
** just a file
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
    #include <ctype.h>
    #include <stdbool.h>
    #define MAX_WORD_LENGTH 100
    #define MAX_WORDS 1000
    #define DEFAULT_TRIES 10

typedef struct dict_s {
    char **word;
    int count;
} dict_t;

typedef struct game_s {
    char *dev;
    char *trouv;
    int len_dev;
    int try;
    int car;
} game_t;

void exit_with_error(const char *message, int code);
void free_dictionary(dict_t *dict);
void init_game(game_t *game, const dict_t *dict, int tries);
void free_game(game_t *game);
void display_game_state(const game_t *game);
int process_guess(game_t *game, char guess);
int is_game_won(const game_t *game);
void play_game(game_t *game);
char get_valid_guess(game_t *game);
int my_isalpha(int c);
int my_is_digit(char c);
FILE *open_file(char *filename);
int handle_underscore_guess(game_t *game, int i, char guess);
void handle_incorrect_guess(game_t *game, char guess);
int handle_regular_guess(game_t *game, int i, char guess);
int is_positive_integer(const char *str);
dict_t *recup(char *filename);

#endif
