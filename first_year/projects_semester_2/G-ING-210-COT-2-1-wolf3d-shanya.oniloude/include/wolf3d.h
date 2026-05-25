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
     #include "structs_wolf3d_2.h"

    #define RWC sfRenderWindow_create
    #define SFVM sfVideoMode
    #define SFV2F sfVector2f
    #define SFRW sfRenderWindow*

extern global_t global;

int run_game_loop(void);
global_t all_globals(set_t *settings);
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
void new_screen(scrnstp_t **screens, int id, char *txtr_path);
void change_screen(scrnstp_t **screens, scrnstp_t **relay, int id);
void reset_button(btn_t *btn);
void screen_switching(btn_t *btn, scrnstp_t **screens, int to_id);
int back_button_clicked(scrnstp_t **screens, btn_t *btn, int to_id);
int change_settings_option(scrnstp_t **screens, btn_t *btn, int op1, int op2);
int main_button_action(btn_t *btn, scrnstp_t **screens);
void buttons_desactivater(btn_t **buttons, int id_1, int id_2);
void first_positionner(scrnstp_t **screens);
void change_window_size(int win_i, SFVM win_size, bool is_fscrn, SFV2F ratio);
int graphism_button_actions(btn_t *btn, scrnstp_t **screens);
int audio_button_actions(btn_t *btn, scrnstp_t **screens);
int controls_button_actions(btn_t *btn, scrnstp_t **screens);
int credits_button_actions(btn_t *btn, scrnstp_t **screens);
void button_checker(btn_t **buttons, sfRenderWindow *win, scrnstp_t **screens);
sfVector2f ratior(float x, float y);
void main_menu_buttons(scrnstp_t **screens);
void settings_buttons(scrnstp_t **screens);
void credits_buttons(scrnstp_t **screens);
void set_text(const char *str, sfFont *font, int size, sfColor col);
void window_resizer(win_t *win, int *previous_window, scrnstp_t **screens);
void volume_sizer(SFRW window, int volume, int *pre_vol, SFV2F pos);
void volume_applier(scrnstp_t **screens, int pre_msc, int pre_snd);
void show_fps(sfRenderWindow *window);
void affect_settings_to_the_game(scrnstp_t **screens, set_t *settings);
void save_settings(set_t *settings);
set_t load_settings(void);
int game_window(set_t *settings);
char **parsing(char *line, const char *sep);
char *open_file(char const *filepath);
player_t init_player(float x, float y, float angle);

#endif
