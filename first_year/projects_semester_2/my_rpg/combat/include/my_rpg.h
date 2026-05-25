/*
** EPITECH PROJECT, 2025
** my_rpg.h
** File description:
** just a file
*/

#ifndef MY_RPG
   #include <SFML/Graphics.h>
   #include <SFML/Audio.h>
   #include <sys/stat.h>
   #include <string.h>
   #include <fcntl.h>
   #include <unistd.h>
   #include <stdlib.h>
   #include <stdio.h>
   #include <stdbool.h>
   #include <math.h>
   #define MY_RPG

typedef struct player_s {
    int x;
    int y;
} player_t;

typedef struct param_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;
    sfUint32 sf;
    player_t player;
} param_t;

void window_loop(param_t *param);
#endif
