/*
** EPITECH PROJECT, 2025
** create_tab.c
** File description:
** just a file
*/

#include "crocus.h"

void six_t(int row, int col, char **tab, char c)
{
    if ((row == 0 || row == 4) && (col == 1 || col == 2 || col == 3))
        tab[row][col] = c;
    if ((col == 0) && (row == 1 || row == 3))
        tab[row][col] = c;
    if ((col == 4) && (row == 3))
        tab[row][col] = c;
    if ((col == 0 || col == 1 || col == 2 || col == 3) && (row == 2))
        tab[row][col] = c;
}

void sept_t(int row, int col, char **tab, char c)
{
    if ((row == 0))
        tab[row][col] = c;
    if (row == 4 && col == 1)
        tab[row][col] = c;
    if (col == 4 && row == 1)
        tab[row][col] = c;
    if (col == 3 && row == 2)
        tab[row][col] = c;
    if (col == 2 && row == 3)
        tab[row][col] = c;
}

void huit_t(int row, int col, char **tab, char c)
{
    if ((row == 0 || row == 4) && (col == 1 || col == 2 || col == 3))
        tab[row][col] = c;
    if ((col == 0 || col == 4) && (row == 1 || row == 3))
        tab[row][col] = c;
    if ((col == 1 || col == 2 || col == 3) && (row == 2))
        tab[row][col] = c;
}

void neuf_t(int row, int col, char **tab, char c)
{
    if ((row == 0 || row == 4) && (col == 1 || col == 2 || col == 3))
        tab[row][col] = c;
    if ((col == 4) && (row == 1 || row == 3))
        tab[row][col] = c;
    if ((col == 0) && (row == 1))
        tab[row][col] = c;
    if ((col == 1 || col == 2 || col == 3 || col == 4) && (row == 2))
        tab[row][col] = c;
}

char **create_tab(char c, char d)
{
    char **tab = NULL;

    if (c >= 58 || c <= 47)
        exit(84);
    tab = malloc(sizeof(char *) * 6);
    for (int a = 0; a < 5; a++)
        tab[a] = malloc(sizeof(char) * 6);
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            tab[row][col] = ' ';
            condition(d, c, row, col, tab);
        }
        tab[row][5] = '\0';
    }
    tab[5] = NULL;
    return tab;
}
