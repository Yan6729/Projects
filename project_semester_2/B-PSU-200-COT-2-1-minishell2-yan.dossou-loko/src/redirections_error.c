/*
** EPITECH PROJECT, 2025
** redirection_error.c
** File description:
** just a file
*/

#include "../include/mysh.h"


int simple_l_error(char *line, char c, int fd)
{
    char stc[] = {c, '\0'};
    char *str = cleanstr(line);
    char **red = strtowordarray(str, stc);

    if (fd < 0) {
        my_puts(red[1], 2);
        my_puts(": No such file or directory.\n", 2);
        return 1;
    }
    return 0;
}

int simple_error(char *line, char c)
{
    char stc[] = {c, '\0'};
    char *str = cleanstr(line);
    char **red = strtowordarray(str, stc);

    if (str[0] == c && str[1] != '\0') {
        my_puts("Invalid null command.\n", 2);
        return 1;
    }
    if (red[0] == NULL && red[1] == NULL || red[1] == NULL) {
        my_puts("Missing name for redirect.\n", 2);
        return 1;
    }
    return 0;
}

int pipe_error(char *line, char c)
{
    char stc[] = {c, '\0'};
    char *str = cleanstr(line);
    char **red = strtowordarray(str, stc);

    if (str[0] == c && str[1] != '\0') {
        my_puts("Invalid null command.\n", 2);
        return 1;
    }
    if (red[0] == NULL && red[1] == NULL || red[1] == NULL) {
        my_puts("Invalid null command.\n", 2);
        return 1;
    }
    return 0;
}

int advenced_error(char *line, char c)
{
    char stc[] = {c, c, '\0'};
    char *str = cleanstr(line);
    char **red = strtowordarray(str, stc);

    if (str[0] == c && str[1] == c && str[2] != '\0') {
        my_puts("Invalid null command.\n", 2);
        return 1;
    }
    if (red[0] == NULL && red[1] == NULL || red[1] == NULL) {
        my_puts("Missing name for redirect.\n", 2);
        return 1;
    }
    return 0;
}

void create_file(char **str, int start, int end)
{
    for (int a = start; a < end; a++) {
        open(cleanstr(str[a]), O_CREAT | O_RDWR, 0775);
    }
}
