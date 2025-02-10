/*
** EPITECH PROJECT, 2024
** game_loop.c
** File description:
** function that contain the second boucle of my code
*/

#include "my.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include <SFML/System/Vector2.h>

sfSprite *my_target(sfRenderWindow *window, char *filepath)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfSprite *target = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfVector2f my_pos_target = {mouse.x - 50, mouse.y - 50};
    sfVector2f scale = {0.2, 0.2};

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_setScale(target, scale);
    sfSprite_setPosition(target, my_pos_target);
    sfSprite_setTexture(target, texture, sfTrue);
    return target;
}

int usage(int ac, char **av)
{
    my_putstr("     Duck Hunt est un jeu de tir en vue subjective dans ");
    my_putstr("lequel l'objectif est de toucher des cibles mouvantes ");
    my_putstr("en visant et tirant avec la souris. Chaque niveau ");
    my_putstr("consiste en un total de dix cibles à toucher. En ");
    my_putstr("fonction du mode de jeu choisi, une ou deux ");
    my_putstr("cibles apparaissent à l'écran et le joueur ");
    my_putstr("dispose de trois essais pour les toucher avant qu'");
    my_putstr("elles ne disparaissent. Le joueur doit réussir à ");
    my_putstr("tirer sur un certain nombre de cibles pour arriver ");
    my_putstr("au niveau suivant. Ainsi, l'échec se soldera par un game ");
    my_putstr("over mettant fin à la partie. La difficulté augmente au ");
    my_putstr("fur et à mesure que le joueur avance dans les niveaux.\n");
    my_putstr("\nGame create by Yan DOSSOU-LOKO, an Epitech Tek_1 student\n");
}

sfVector2f duck_killer(sfRenderWindow *window, sfMouseButtonEvent mouse,
    sfSprite *my_duck, sfVector2f my_pos)
{
    if (mouse.x >= my_pos.x && mouse.x <= my_pos.x + 110
        && mouse.y >= my_pos.y && mouse.y <= my_pos.y + 110) {
        my_pos.x = -180;
        my_pos.y = rand() % 200;
        sfSprite_setPosition(my_duck, my_pos);
    }
    return my_pos;
}

sfVector2f manage_events2(sfRenderWindow *window, sfEvent event,
    sfVector2f my_pos, sfSprite *my_duck)
{
    sfSprite *target = my_target(window, "my_target.png");

    sfRenderWindow_drawSprite(window, target, NULL);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            my_pos = duck_killer(window, event.mouseButton, my_duck, my_pos);
        }
    }
    return my_pos;
}

void create_game(sfRenderWindow *window, sfEvent event, float seconds)
{
    sfSprite *my_duck = draw_duck("my_duck.png");
    sfSprite *game = create_background_2("paysage.jpeg");
    sfVector2f my_pos = {0, 0};
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window)) {
        my_pos.x += 1.0;
        clock = duck_speed(clock, my_duck, seconds);
        if (my_pos.x >= 800) {
            my_pos.x = -110;
            my_pos.y = rand() % 200;
        }
        draw(window, my_duck, game, my_pos);
        my_pos = manage_events2(window, event, my_pos, my_duck);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(my_duck);
    sfSprite_destroy(game);
}
