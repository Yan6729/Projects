/*
** EPITECH PROJECT, 2024
** step02.c
** File description:
** step02.c
*/
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
int main(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {800, 600, 32};
    sfEvent event;
    sfUint8 *pixels;

    pixels = malloc(800 * 600 * 32 / 8);

    pixels[0] = 255;
    pixels[1] = 125;
    pixels[2] = 0;
    pixels[3] = 255;
    window = sfRenderWindow_create(video_mode, "Snake part01", sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
    while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
    }
}
