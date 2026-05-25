/*
** EPITECH PROJECT, 2025
** sdfghj
** File description:
** xcvbn
*/

#include "../include/my_rpg.h"

sfMusic *play_music_loop(const char *filepath)
{
    sfMusic *music = sfMusic_createFromFile(filepath);

    sfMusic_setVolume(music, 100);
    if (!music) {
        printf("Erreur de chargement de la musique\n");
        return NULL;
    }
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return music;
}

void play_intro(sfRenderWindow *window)
{
    char path[64];
    sfTexture *texture = NULL;
    sfSprite *sprite = sfSprite_create();
    sfClock *clock = sfClock_create();
    int current_frame = 1;
    int total_frames = 7;
    sfTime frame_delay = sfMilliseconds(5000);
    sfEvent event;
    sfMusic *music = play_music_loop("son/son 2.mp3");

    texture = sfTexture_createFromFile("texture/frame01.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(window) && current_frame <= total_frames) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        if (sfClock_getElapsedTime(clock).microseconds >= frame_delay.microseconds) {
            sfClock_restart(clock);
            current_frame++;
            if (current_frame > total_frames)
                break;
            snprintf(path, sizeof(path), "texture/frame0%d.png", current_frame);
            sfTexture_destroy(texture);
            texture = sfTexture_createFromFile(path, NULL);
            if (texture)
                sfSprite_setTexture(sprite, texture, sfTrue);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    sfClock_destroy(clock);
}

int main(void)
{
    Menu_t menu;

    init_menu(&menu);
    play_intro(menu.win);
    handle_menu(&menu);
    destroy_menu(&menu);
    return 0;
}
