/*
** EPITECH PROJECT, 2024
** game_animate.c
** File description:
** function that help me to animate my function
*/
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include <SFML/System/Vector2.h>

void animate_sprite(sfSprite *my_duck, int frame_count)
{
    sfIntRect area = sfSprite_getTextureRect(my_duck);

    area.left = (area.left + 110) % 330;
    if (area.left >= frame_count * 110)
        area.left = 0;
    sfSprite_setTextureRect(my_duck, area);
}

sfClock *duck_speed(sfClock *clock, sfSprite *my_duck, float seconds)
{
    sfTime time;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.15) {
        animate_sprite(my_duck, 3);
        sfClock_restart(clock);
    }
    return clock;
}

sfSprite *draw_duck(char *filepath)
{
    sfSprite *my_duck = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfIntRect area = {0, 0, 110, 110};

    sfSprite_setTexture(my_duck, texture, sfTrue);
    sfSprite_setTextureRect(my_duck, area);
    return my_duck;
}

sfSprite *create_background_2(char *filepath)
{
    sfSprite *my_sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfVector2f my_pos = {0, 0};
    sfVector2f scale = {0.448, 0.6};

    sfSprite_setScale(my_sprite, scale);
    sfSprite_setPosition(my_sprite, my_pos);
    sfSprite_setTexture(my_sprite, texture, sfTrue);
    return my_sprite;
}
