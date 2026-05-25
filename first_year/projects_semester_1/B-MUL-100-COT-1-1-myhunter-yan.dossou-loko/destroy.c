/*
** EPITECH PROJECT, 2024
** destroy.c
** File description:
** intermediate function
*/

#include "my.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include <SFML/System/Vector2.h>

void draw(sfRenderWindow *window, sfSprite *my_duck,
    sfSprite *game, sfVector2f my_pos)
{
    sfSprite_setPosition(my_duck, my_pos);
    sfRenderWindow_drawSprite(window, game, NULL);
    sfRenderWindow_drawSprite(window, my_duck, NULL);
}

void draw_2(sfRenderWindow *window, sfSprite *background_1,
    sfSprite *start)
{
    sfRenderWindow_drawSprite(window, background_1, NULL);
    sfRenderWindow_drawSprite(window, start, NULL);
}

void destroy_1(sfSprite *background_1, sfSprite *start)
{
    sfTexture *texture_2 = sfTexture_createFromFile("Button_start.png", NULL);
    sfTexture *texture_1 = sfTexture_createFromFile("DUCK HUNT.png", NULL);

    sfTexture_destroy(texture_2);
    sfTexture_destroy(texture_1);
    sfSprite_destroy(background_1);
    sfSprite_destroy(start);
}
