/*
** EPITECH PROJECT, 2025
** test wolf3d
** File description:
** header
*/

#ifndef TEST_H
    #define TEST_H

    #include "libs_wolf3d.h"
    #include "structs_wolf3d.h"

    #define RWC sfRenderWindow_create
    #define SFTCFF sfTexture_createFromFile
    #define SFMCFF sfMusic_createFromFile
    #define SFVM sfVideoMode
    #define SFS sfSprite*
    #define SFV2 sfVector2f

extern global_t global;

//void button_adder(btn_t **buttons, char *txtr_name[4], SFV2 sz_pos_sc[4]);
void button_adder(btn_t **buttons, belm_t *elm);
void buttons_displayer(btn_t **buttons, sfRenderWindow *win);
void buttons_remover(scrnstp_t *screens);
void button_checker(btn_t **buttons, sfRenderWindow *window);
void my_framerate(void);
int game_window(void);
char **parsing(char *line, const char *sep);
char *open_file(char const *filepath);
player_t init_player(float x, float y, float angle);

#endif
