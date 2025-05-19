/*
** EPITECH PROJECT, 2025
** game
** File description:
** game
*/

#include "connect4.h"

int to_fill2(char **tab, int i)
{
    for (int j = 0; tab[i][j] != '\0'; j++)
        if (tab[i][j] == '.')
            return 1;
    return 0;
}

int tot_fill(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        if (to_fill2(tab, i) == 1)
            return 1;
    printf("It's a tie, nobody wins.\n");
    return 0;
}

char change_player(char p, data_t data)
{
    if (p == data.p1)
        p = data.p2;
    else
        p = data.p1;
    return p;
}

int styre(data_t data, int i, int pos, char **tab)
{
    int tmp;

    if (tab[i][pos] == '.') {
        tmp = i;
    }
    return tmp;
}

char **game(char **tab, data_t data)
{
    int tmp = 0;
    char *a;
    char p = data.p1;
    int pos = 0;

    while (tot_fill(tab) != 0) {
        printf("Player %c, where do you want to play: ", p);
        scanf("%s", a);
        pos = atoi(a);
        if (pos > data.wight || pos < 1)
            continue;
        for (int i = data.height + 1; 0 < i; i--)
            tmp = styre(data, i, pos, tab);
        tab[tmp][pos] = p;
        affiche(data.wight, data.height, tab);
        p = change_player(p, data);
    }
}
