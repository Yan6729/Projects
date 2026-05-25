/*
** EPITECH PROJECT, 2025
** globbings
** File description:
** function
*/

#include "../include/shell.h"

int count_line(char *cmd)
{
    int i = 0;
    int nb = 0;

    for (i = 0; cmd[i] != '\0'; i++) {
        if (cmd[i] == '*' || cmd[i] == '?' || cmd[i] == '[')
            nb++;
    }
    return nb;
}

globbing_t check_globbings(char *cmd, globbing_t cmp)
{
    for (int i = 0; cmp.mapcmd2[i] != NULL; i++) {
        if (strchr(cmp.mapcmd2[i], '*') || strchr(cmp.mapcmd2[i], '?')
            || strchr(cmp.mapcmd2[i], '[')) {
            glob(cmp.mapcmd2[i], GLOB_DOOFFS | 0, NULL, &cmp.globbuf);
            complete_pathv(cmp);
            execvp(cmp.mapcmd[0], &cmp.globbuf.gl_pathv[0]);
            globfree(&cmp.globbuf);
        }
    }
}

void globbings(shell_t *tmp, char *cmd)
{
    globbing_t cmp = complete_mapcmd(tmp, cmd);

    cmp.pid = fork();
    if (cmp.pid == 0) {
        cmp.globbuf.gl_offs = cmp.y;
            check_globbings(cmd, cmp);
    } else
        waitpid(cmp.pid, &cmp.state, 0);
}
