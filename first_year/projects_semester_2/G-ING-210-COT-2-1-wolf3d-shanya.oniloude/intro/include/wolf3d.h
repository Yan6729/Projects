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
    #define SFRW sfRenderWindow*
    #define SFVM sfVideoMode
    #define SFV2F sfVector2f

extern global_t global;

global_t all_globals(void);
void my_framerate(void);

int get_time(void);
intro_t intro_maker(void);
void intro_elements_destroy(intro_t *intro);
void fader(sfSprite *sprt);
void epi_shower(sfRenderWindow *window, intro_t *intro);
void shayanx_shower(sfRenderWindow *window, intro_t *intro);
void loading_shower(sfRenderWindow *window, intro_t *intro);
void intro_skipper(sfEvent event, intro_t *intro);
void introductor(sfRenderWindow *window, intro_t *intro);

int game_window(void);

#endif
