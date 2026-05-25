/*
** EPITECH PROJECT, 2025
** test wolf3d
** File description:
** window
*/

#include "../include/wolf3d.h"

void set_text(const char *str, sfFont *font, int size, sfColor col)
{
    sfText_setString(global.text, str);
    sfText_setFont(global.text, font);
    sfText_setColor(global.text, col);
    sfText_setCharacterSize(global.text, size);
    return;
}
