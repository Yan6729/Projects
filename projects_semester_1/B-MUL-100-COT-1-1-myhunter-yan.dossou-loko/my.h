/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** function that stock my function prototypes
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include <SFML/System/Vector2.h>

#ifndef MY_H
   #define MY_H

void destroy_1(sfSprite *background_1, sfSprite *start);
void draw_2(sfRenderWindow *window, sfSprite *background,
    sfSprite *start);
void draw(sfRenderWindow *window, sfSprite *my_duck,
    sfSprite *game, sfVector2f my_pos);
int manage_events(sfRenderWindow *window, sfEvent event);
sfSprite *create_background(char *filepath);
sfSprite *start_button(char *filepath);
int usage(int ac, char **av);
void my_putchar(char c);
int my_putstr(char const *str);
sfSprite *create_background_2(char *filepath);
sfSprite *draw_duck(char *filepath);
void animate_sprite(sfSprite *my_duck, int frame_count);
sfClock *duck_speed(sfClock *clock, sfSprite *my_duck, float seconds);
void click(sfMouseButtonEvent event);
void if_click(sfRenderWindow *window, sfEvent event);
void create_game(sfRenderWindow *window, sfEvent event, float seconds);

#endif
