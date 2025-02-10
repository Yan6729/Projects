/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** my_code root
*/

#include "my.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include <SFML/System/Vector2.h>


int menu(int ac, char **av)
{
    sfVideoMode mode = {800, 600, 64};
    sfUint32 sf = {sfClose | sfResize};
    sfRenderWindow *window = sfRenderWindow_create(mode, "My_hunter !", sf, 0);
    sfEvent event = {0};
    sfSprite *background_1 = create_background("DUCK HUNT.png");
    sfSprite *start = start_button("Button_start.png");

    while (sfRenderWindow_isOpen(window)) {
        if (manage_events(window, event))
            return 0;
    sfRenderWindow_clear(window, sfBlack);
    draw_2(window, background_1, start);
    sfRenderWindow_display(window);
    }
    destroy_1(background_1, start);
    sfRenderWindow_destroy(window);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        menu(ac, av);
    } else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        usage(ac, av);
    } else {
        return (84);
    }
}
