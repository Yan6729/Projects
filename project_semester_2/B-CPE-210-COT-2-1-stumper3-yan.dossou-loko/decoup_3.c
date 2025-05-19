/*
** EPITECH PROJECT, 2025
** create_tab.c
** File description:
** just a file
*/

#include "crocus.h"

void cinq_t(int row, int col, char **tab, char c)
{
    if ((row == 4) && (col == 0 || col == 1 || col == 2 || col == 3))
        tab[row][col] = c;
    if ((row == 0))
        tab[row][col] = c;
    if ((col == 0) && (row == 1))
        tab[row][col] = c;
    if ((col == 4) && (row == 3))
        tab[row][col] = c;
    if ((col == 0 || col == 1 || col == 2 || col == 3) && (row == 2))
        tab[row][col] = c;
}

void condition(char d, char c, int row, int col, char **tab)
{
    if (c == 48)
        zero_t(row, col, tab, d);
    if (c == 49)
        un_t(row, col, tab, d);
    if (c == 50)
        deux_t(row, col, tab, d);
    if (c == 51)
        trois_t(row, col, tab, d);
    if (c == 52)
        quatre_t(row, col, tab, d);
    if (c == 53)
        cinq_t(row, col, tab, d);
    if (c == 54)
        six_t(row, col, tab, d);
    if (c == 55)
        sept_t(row, col, tab, d);
    if (c == 56)
        huit_t(row, col, tab, d);
    if (c == 57)
        neuf_t(row, col, tab, d);
}
