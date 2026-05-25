/*
** EPITECH PROJECT, 2025
** globbings_funt
** File description:
** function
*/

#include "../include/shell.h"

globbing_t stock_var(char *cmd)
{
    globbing_t cmp;

    cmp.globbuf;
    cmp.flags = 0;
    cmp.y = count_line(cmd);
    cmp.mapcmd2 = NULL;
    cmp.mapcmd = NULL;
    cmp.f = 0;
    cmp.d = 0;
    cmp.h = 0;
    cmp.state;
    cmp.pid;
    return cmp;
}

globbing_t complete_mapcmd(shell_t *tmp, char *cmd)
{
    globbing_t cmp = stock_var(cmd);
    int x = 0;

    cmp.mapcmd2 = verify_alias(tmp, my_split(cmd, " "));
    cmp.y = count_arg(cmp.mapcmd2, 0) - count_line(cmd);
    cmp.mapcmd = malloc(sizeof(char *) * cmp.y);
    for (x = 0; x < cmp.y; x++) {
        cmp.mapcmd[cmp.h] = strdup(cmp.mapcmd2[x]);
        cmp.h++;
    }
    return cmp;
}

void complete_pathv(globbing_t cmp)
{
    int d = 0;

    for (int x = 0; x < cmp.y; x++) {
        cmp.globbuf.gl_pathv[d] = cmp.mapcmd[x];
        d++;
    }
}
