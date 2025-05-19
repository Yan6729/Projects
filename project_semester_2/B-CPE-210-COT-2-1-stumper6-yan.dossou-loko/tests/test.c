
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/stumper.h"

void redirect_stdout(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(utils, my_isalpha) {
    cr_assert_eq(my_isalpha('a'), 1);
    cr_assert_eq(my_isalpha('Z'), 1);
    cr_assert_eq(my_isalpha('1'), 0);
    cr_assert_eq(my_isalpha('_'), 0);
}

Test(utils, my_is_digit) {
    cr_assert_eq(my_is_digit('0'), 1);
    cr_assert_eq(my_is_digit('9'), 1);
    cr_assert_eq(my_is_digit('a'), 0);
}

Test(utils, is_positive_integer) {
    cr_assert_eq(is_positive_integer("123"), 0);
    cr_assert_eq(is_positive_integer("0"), 0);
    cr_assert_eq(is_positive_integer("-5"), 84);
    cr_assert_eq(is_positive_integer("12a"), 84);
    cr_assert_eq(is_positive_integer(""), 84);
}

Test(game, init_and_free) {
    dict_t dict = {.word = malloc(sizeof(char*)), .count = 1};
    dict.word[0] = strdup("test");
    
    game_t game;
    init_game(&game, &dict, 5);
    
    cr_assert_not_null(game.dev);
    cr_assert_not_null(game.trouv);
    cr_assert_eq(game.len_dev, 4);
    cr_assert_eq(game.try, 5);
    cr_assert_str_eq(game.trouv, "****");
    
    free_game(&game);
    free_dictionary(&dict);
}

Test(game, process_guess) {
    game_t game = {
        .dev = strdup("test"),
        .trouv = strdup("****"),
        .len_dev = 4,
        .try = 5,
        .car = 0
    };
    cr_assert_eq(process_guess(&game, 't'), 1);
    cr_assert_str_eq(game.trouv, "t**t");
    cr_assert_eq(game.car, 2);
    cr_assert_eq(process_guess(&game, 'x'), 0);
    cr_assert_eq(game.try, 4);
    
    free_game(&game);
}

Test(interface, display_game_state, .init = redirect_stdout) {
    game_t game = {
        .trouv = "t**t",
        .try = 3
    };
    
    display_game_state(&game);
    fflush(stdout);
    
    cr_assert_stdout_eq_str("t**t\nTries: 3\n\n");
}

Test(integration, full_game_win, .init = redirect_stdout) {
    dict_t dict = {.word = malloc(sizeof(char*)), .count = 1};
    dict.word[0] = strdup("test");
    
    FILE* f = fopen("test_input.txt", "w+");
    fprintf(f, "t\ne\ns\n");
    rewind(f);
    stdin = f;
    
    game_t game;
    init_game(&game, &dict, 10);
    play_game(&game);
    
    cr_assert(is_game_won(&game));
    
    fclose(f);
    free_game(&game);
    free_dictionary(&dict);
}
