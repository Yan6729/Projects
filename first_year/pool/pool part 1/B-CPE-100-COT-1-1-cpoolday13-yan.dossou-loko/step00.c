/*
** EPITECH PROJECT, 2024
** step02.c
** File description:
** step02.c
*/

#include <SFML/Graphics.h>

static sfRenderWindow * create_renderwindow(unsigned int x, unsigned int y, unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};

    return (sfRenderWindow_create(video_mode, title, sfResize | sfClose, NULL));
}
int main(void)
{
    sfRenderWindow *window = create_renderwindow(800, 400, 120, "Let's draw !");
    sfEvent event;
    sfTexture *my_texture = sfTexture_createFromFile("my ing.jpeg", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfVector2f my_pos = {0, 50};
    sfVector2f scale = {0.25, 0.25};

    sfSprite_setScale(my_sprite, scale);
    sfSprite_setPosition(my_sprite, my_pos);
    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
	while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, my_sprite, NULL);
	sfRenderWindow_display(window);

    }
}
