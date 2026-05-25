/*
** EPITECH PROJECT, 2025
** timer
** File description:
** an intermediar function
*/

#include "struct.h"

void timer_init(char timer[6])
{
    if (timer[4] == 58 && timer[3] != 53) {
        timer[3]++;
        timer[4] = 48;
    }
    if (timer[4] == 58 && timer[3] == 53) {
        timer[1]++;
        timer[3] = 48;
        timer[4] = 48;
    }
    if (timer[1] == 58) {
        timer[0]++;
        timer[2] = 48;
        timer[3] = 48;
        timer[4] = 48;
    }
}

void text_create(char timer[6])
{
    sfFont *font = sfFont_createFromFile("arialceb.ttf");
    sfText *text;

    if (!font)
        return;
    text = sfText_create();
    sfText_setString(text, timer);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, (sfVector2f){1795, 0});
}

void duck_speed(sfClock *clock, sfText *text, char timer[6])
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 1.0) {
        timer[4]++;
        timer_init(timer);
        sfClock_restart(clock);
    }
}
