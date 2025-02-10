/*
** EPITECH PROJECT, 2025
** other_window.c
** File description:
** an intyermediar file
*/

#include "mytop.h"

int two_window(void)
{
    WINDOW *haut;
    int a = 0;

    initscr();
    haut = subwin(stdscr, (LINES / 2) + 16, COLS, 8, 0);
    mvwprintw(haut, 1, 1, "Ceci est la fenetre du haut");
    endwin();
    return 0;
}
