/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** all structures used
*/

#ifndef STRUCTSWOLF3D_H
    #define STRUCTSWOLF3D_H

    #include "libs_wolf3d.h"

typedef struct window {
    sfRenderWindow *window;
    sfEvent event;
} win_t;

typedef struct opening {
    sfRectangleShape *rect_hider;
    sfTexture *epi_txtr;
    sfSprite *epi_sprt;
    sfMusic *epi_msc;
    sfTexture *shayanx_txtr;
    sfSprite *shayanx_sprt;
    sfMusic *shayanx_msc;
    sfMusic *shayanx_shoot;
    sfTexture *chaos_txtr;
    sfSprite *chaos_sprt;
    sfTexture *loading_txtr;
    sfSprite *loading_sprt;
    sfColor color;
    sfVector2f container;
    float angle;
    int i;
} intro_t;

typedef struct elements {
    bool const_btn;
    char btn_id;
    char *txr_path;
    char *snd_path;
    sfVector2f btn_siz;
    sfVector2f btn_pos;
    sfVector2f idle_scale;
    sfVector2f hover_scale;
} belm_t;

typedef struct button {
    bool idle;
    bool hover;
    bool selected;
    bool selected_hover;
    bool const_button;
    char button_id;
    sfTexture *button_texture;
    sfSprite *button_sprite;
    sfVector2i button_size;
    sfVector2f button_scales[2];
    sfVector2f position;
    sfMusic *clicked_music;
    struct button *next;
} btn_t;

typedef struct screen {
    int id;
    sfTexture *back_txtr;
    sfSprite *back_sprt;
    btn_t *buttons;
    struct screen *next;
} scrnstp_t;

typedef struct comparers {
    int previous_fps_limit;
    int pre_msc;
    int pre_snd;
    int pre_win;
    int pre_ratio;
} comp_t;

typedef struct player {
    float x;
    float y;
    float angle;
}player_t;

typedef struct settings {
    sfVideoMode window_size;
    sfVector2f ratio;
    int window_i;
    int fps_limit;
    bool show_fps;
    int music_volume;
    int sound_volume;
    bool prs_spk;
    bool l_hnd;
    float rot_sblt;
} set_t;


typedef struct variables {
    int fps_limit;
    int fps;
    sfClock *game_clock;
    sfTime time;
    float seconds;
    sfVideoMode window_size;
    bool is_fullscreen;
    int window_i;
    scrnstp_t *current_screen;
    sfMusic *main_hovered;
    int music_volume;
    int sound_volume;
    bool p_spk;
    bool l_hnd;
    float rot_sblt;
    sfRectangleShape *volume_level;
    sfFont *font_1;
    sfText *text;
    char text_cont[100];
    bool show_fps;
    sfVector2f ratio;
    bool exit;
    bool start_game;
    int i;
    bool ok_settings;
} global_t;

#endif
