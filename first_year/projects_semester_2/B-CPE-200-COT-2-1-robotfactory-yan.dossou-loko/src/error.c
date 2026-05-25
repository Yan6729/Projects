/*
** EPITECH PROJECT, 2025
** error_cases
** File description:
** error case
*/

#include "../B-CPE-200_op/op.h"
#include "../include/robot.h"

char *clean(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            str[i] = ' ';
        i++;
    }
    str[i] = '\0';
    return str;
}

char *parsing(char const *filepath)
{
    int x;
    struct stat sb;
    int fd;
    char *buffer;
    int i;

    if (stat(filepath, &sb) != -1)
        x = sb.st_size;
    buffer = (char *) malloc(sizeof(char) * x);
    fd = open(filepath, O_RDONLY);
    i = read(fd, buffer, x);
    close(fd);
    return buffer;
}

int check_file(char *filename)
{
    int i = my_strlen(filename);
    struct stat sb;
    char *buffer = NULL;
    char **tab = NULL;
    char *stock = NULL;
    int x = 0;

    if (filename[i - 1] != 's' || filename[i - 2] != '.') {
        my_puts_2("Usage: ./asm file_name[.s] ....\n");
        return 84;
    }
    buffer = parsing(filename);
    tab = my_split(buffer, "\t\n");
    if (check(filename, tab) == 84)
        return 84;
}
