/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** header
*/

#ifndef WOLF3D_H
    #define WOLF3D_H

    #include "libs_wolf3d.h"
    #include "structs_wolf3d.h"

    #define RWC sfRenderWindow_create
    #define SFVM sfVideoMode
    #define SFV2F sfVector2f
    #define SFRW sfRenderWindow*

extern global_t global;

global_t all_globals(void);
void framerate_limiter(SFRW window, int *previous_fps_limit);
void my_framerate(void);
int get_time(void);
intro_t intro_maker(void);
void intro_elements_destroy(intro_t *intro);
sfSprite *sprt_create(sfTexture *txtr, SFV2F pos);
void fader(sfSprite *sprt);
void epi_shower(sfRenderWindow *window, intro_t *intro);
void shayanx_shower(sfRenderWindow *window, intro_t *intro);
void loading_shower(sfRenderWindow *window, intro_t *intro);
void intro_skipper(sfEvent event, intro_t *intro);
void introductor(sfRenderWindow *window, intro_t *intro);
void button_adder(btn_t **buttons, belm_t *elm);
void buttons_displayer(btn_t **buttons, sfRenderWindow *win);
void buttons_remover(scrnstp_t **screens);
void change_screen(scrnstp_t **screens, scrnstp_t **relay, int id);
void reset_button(btn_t *btn);
void screen_switching(btn_t *btn, scrnstp_t **screens, int to_id);
int back_button_clicked(scrnstp_t **screens, btn_t *btn, int to_id);
int change_settings_option(scrnstp_t **screens, btn_t *btn, int op1, int op2);
void button_checker(btn_t **buttons, sfRenderWindow *win, scrnstp_t **screens);
int game_window(void);
char **parsing(char *line, const char *sep);
char *open_file(char const *filepath);
player_t init_player(float x, float y, float angle);

#endif
