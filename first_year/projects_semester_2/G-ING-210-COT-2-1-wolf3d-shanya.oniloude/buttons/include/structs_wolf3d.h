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

typedef struct variables {
    int i;
    int fps_limit;
    int fps;
    int nb_screens;
    sfVideoMode window_size;
    sfMusic *main_hovered;
} global_t;

typedef struct player {
    float x;
    float y;
    float angle;
}player_t;

typedef struct elements
{
    bool const_btn;
    char *btn_name;
    char *txtr_path;
    char *snd_path;
    sfVector2f btn_size;
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
    char *button_name;
    sfTexture *button_texture;
    sfSprite *button_sprite;
    sfVector2i button_size;
    sfVector2f button_scales[2];
    sfVector2f position;
    sfMusic *clicked_music;
    struct button *next;
} btn_t;

typedef struct screen {
    btn_t *buttons;
} scrnstp_t;

#endif