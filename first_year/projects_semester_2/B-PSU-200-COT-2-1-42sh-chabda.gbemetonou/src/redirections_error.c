/*
** EPITECH PROJECT, 2025
** redirection_error.c
** File description:
** just a file
*/

#include "../include/shell.h"


int simple_l_error(char *line, char c, int fd)
{
    char stc[] = {c, '\0'};
    char *str = cleanstr(line, 0);
    char **red = strtowordarray(str, stc);

    if (fd < 0) {
        print("stderr", "%s: No such file or directory.\n", red[1]);
        return 1;
    }
    return 0;
}

int simple_error(char *line, char c)
{
    char stc[] = {c, '\0'};
    char *str = cleanstr(line, 0);
    char **red = strtowordarray(str, stc);

    if (str[0] == c && str[1] != '\0') {
        print("stderr", "Invalid null command.\n");
        return 1;
    }
    if (red[0] == NULL && red[1] == NULL || red[1] == NULL) {
        print("stderr", "Missing name for redirect.\n");
        return 1;
    }
    return 0;
}

int pipe_error(char *line, char c)
{
    char stc[] = {c, '\0'};
    char *str = cleanstr(line, 0);
    char **red = strtowordarray(str, stc);

    if (str[0] == c && str[1] != '\0') {
        print("stderr", "Invalid null command.\n");
        return 1;
    }
    if (red[0] == NULL && red[1] == NULL || red[1] == NULL) {
        print("stderr", "Invalid null command.\n");
        return 1;
    }
    return 0;
}

int advenced_error(char *line, char c)
{
    char stc[] = {c, c, '\0'};
    char *str = cleanstr(line, 0);
    char **red = strtowordarray(str, stc);

    if (str[0] == c && str[1] == c && str[2] != '\0') {
        print("stderr", "Invalid null command.\n");
        return 1;
    }
    if (red[0] == NULL && red[1] == NULL || red[1] == NULL) {
        print("stderr", "Missing name for redirect.\n");
        return 1;
    }
    return 0;
}

void create_file(char **str, int start, int end)
{
    char *name = NULL;

    for (int a = start; a < end; a++) {
        name = my_split(str[a], " ")[0];
        open(name, O_CREAT | O_RDWR, 0775);
    }
    free(name);
}
