/*
** EPITECH PROJECT, 2025
** cut
** File description:
** pause
*/
#include "../include/wolf3d_2.h"
void update_me(pause_menu_t *menu, sfEvent event)
{
    if (event.key.code == sfKeyUp)
        menu->selected = (menu->selected + 2) % 3;
    else if (event.key.code == sfKeyDown)
        menu->selected = (menu->selected + 1) % 3;
}
