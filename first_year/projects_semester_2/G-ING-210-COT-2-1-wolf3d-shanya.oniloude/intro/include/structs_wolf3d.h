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
    int fps_limit;
    int fps;
    sfClock *game_clock;
    sfTime time;
    float seconds;
    sfVideoMode window_size;
    int i;
} global_t;

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


typedef struct player {
    float x;
    float y;
    float angle;
}player_t;
#endif
