/*
** EPITECH PROJECT, 2025
** create_tab.c
** File description:
** just a file
*/

#include "crocus.h"

void zero_t(int row, int col, char **tab, char c)
{
    if ((row == 0 || row == 4) && (col == 1 || col == 2 || col == 3))
        tab[row][col] = c;
    if ((col == 0 || col == 4) && (row == 1 || row == 2 || row == 3))
        tab[row][col] = c;
}

void un_t(int row, int col, char **tab, char c)
{
    if (col == 2 || col == 3)
        tab[row][col] = c;
    if (row == 4 && (col == 1 || col == 4))
        tab[row][col] = c;
    if (row == 1 && col == 0)
        tab[row][col] = c;
    if (row == 0 && col == 1)
        tab[row][col] = c;
}

void deux_t(int row, int col, char **tab, char c)
{
    if ((row == 0) && (col == 1 || col == 2 || col == 3))
        tab[row][col] = c;
    if ((row == 4))
        tab[row][col] = c;
    if ((col == 0 || col == 4) && (row == 1))
        tab[row][col] = c;
    if ((col == 3) && (row == 2))
        tab[row][col] = c;
    if ((col == 1) && (row == 3))
        tab[row][col] = c;
}

void trois_t(int row, int col, char **tab, char c)
{
    if ((row == 0 || row == 4) && (col == 0 || col == 1 ||
        col == 2 || col == 3))
        tab[row][col] = c;
    if ((col == 4) && (row == 1 || row == 3))
        tab[row][col] = c;
    if ((col == 1 || col == 2 || col == 3) && (row == 2))
        tab[row][col] = c;
    if ((col == 1 || col == 2 || col == 3) && (row == 2))
        tab[row][col] = c;
}

void quatre_t(int row, int col, char **tab, char c)
{
    if (row == 3)
        tab[row][col] = c;
    if (col == 3)
        tab[row][col] = c;
    if (row == 2 && col == 0)
        tab[row][col] = c;
    if (row == 1 && col == 1)
        tab[row][col] = c;
    if (row == 0 && col == 2)
        tab[row][col] = c;
}
