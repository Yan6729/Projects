/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** checks buttons
*/

#include "../include/wolf3d.h"

/*
if (tmp->button_id == 7) {
    system("open https://github.com/YannAnge-NextGen/ShayanX-Sector42_Genesis
    2> .errors");
    return (0);
}
if (tmp->button_id == 8) {
    system("open https://www.youtube.com/ 2> .errors");
    return (0);
}
*/

int main_button_action(btn_t *btn, scrnstp_t **screens)
{
    if (btn->button_id == 1) {
        global.exit = 1;
        global.start_game = 1;
        return (1);
    }
    if (btn->button_id == 4) {
        screen_switching(btn, screens, 41);
        return (1);
    }
    if (btn->button_id == 5) {
        screen_switching(btn, screens, 50);
        return (1);
    }
    if (btn->button_id == 6) {
        global.exit = 1;
        return (0);
    }
    return (0);
}
