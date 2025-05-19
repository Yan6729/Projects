/*
** EPITECH PROJECT, 2025
** Duo
** File description:
** Stumper.
*/

#include "../include/my.h"

void save(ign_t *list)
{
    FILE *fd = fopen(".save", "w+");

    if (fd == NULL)
        return;
    for (int a = 0; a < 8; a++) {
        fprintf(fd, "%s = %d\n", list[a].name, list[a].qut);
    }
    fclose(fd);
}
