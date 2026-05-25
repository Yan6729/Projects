/*
** EPITECH PROJECT, 2025
** scripting.c
** File description:
** just a function
*/

#include "../include/shell.h"


int handle_shebang(char *path, char **tab)
{
    char *buf = open_file(path);
    char **tampon = strtowordarray(buf, "\n");
    char *shebang = my_strdup(tampon[0], 2);
    char **tab_2 = strtowordarray(shebang, " \t");
    char path1[1024];
    char **new = NULL;
    char *nex_s = NULL;

    if (!tampon || tampon[0][0] != '#' || tampon[0][1] != '!')
        return 0;
    if (strstr(shebang, "env")) {
        nex_s = my_strndup(tab_2[0], 0, strlen(tab_2[0]) - strlen("env"));
        strcpy(path1, nex_s);
        strcat(path1, tab_2[1]);
    } else
        strcpy(path1, my_strdup(shebang, 0));
    new = trans_cmd(path1, tab, 0);
    execv(cleanstr(path1, 0), new);
    error_exec(path);
    return 1;
}

void decoup_2(char **tab, char **env, char *path)
{
    char **new = NULL;
    struct stat buffer;

    if (stat(path, &buffer) == 0 && (buffer.st_mode & S_IXUSR)) {
        new = trans_cmd("/bin/sh", tab, 0);
        execv("/bin/sh", new);
    } else {
        execve(path, tab, env);
        error_exec(path);
        exit(EXIT_FAILURE);
    }
}

int handle_text_or_elf(char *path, char **tab, char **env)
{
    if (is_text(path) == 1) {
        execve(path, tab, env);
        error_exec(path);
        exit(EXIT_FAILURE);
    } else if (path[0] == '.' && path[1] == '/') {
        decoup_2(tab, env, path);
    }
}
