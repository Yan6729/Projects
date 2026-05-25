/*
** EPITECH PROJECT, 2024
** step01.c
** File description:
** step01.c
*/

#include <SFML/Graphics.h>

int main(void)
{
    sfRenderWindow *window;
    sfVideoMode graphics = {800, 600};
    sfEvent evmt;

    window = sfRenderWindow_create(graphics, "Snake part01", sfClose | sfResize, NULL);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
    while (sfRenderWindow_pollEvent(window, &evmt))
            if (evmt.type == sfEvtClosed)
                sfRenderWindow_close(window);
    }
}
