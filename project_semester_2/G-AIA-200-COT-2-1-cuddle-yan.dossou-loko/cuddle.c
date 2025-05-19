/*
** EPITECH PROJECT, 2025
** cuddle.c
** File description:
** just a file for the bstrap
*/

#include "include/dataframe.h"

char **parsing(char const *filepath)
{
    int x;
    struct stat sb;
    int fd;
    char *buffer;
    int i;
    char **tab;

    if (stat(filepath, &sb) != -1)
        x = sb.st_size;
    buffer = (char *) malloc(sizeof(char) * x);
    fd = open(filepath, O_RDONLY);
    i = read(fd, buffer, x);
    close(fd);
    tab = my_split(buffer, "\n");
    free(buffer);
    return tab;
}

int count(const char *filename)
{
    char **tab = parsing(filename);
    int b = -1;

    for (int a = 0; tab[a] != NULL; a++) {
        b++;
    }
    return b;
}

int count_sep_char(char sep, const char *str)
{
    int b = 1;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == sep) {
            b++;
        }
    }
    return b;
}

dataframe_t *df_read_csv(const char *filename, const char *separator)
{
    char **content = parsing(filename);
    dataframe_t *newdata = malloc(sizeof(dataframe_t));
    char *line1 = content[0];

    newdata->nb_rows = count(filename);
    newdata->nb_columns = count_sep_char(separator[0], line1);
    newdata->column_names = my_split(line1, separator);
    newdata->list = NULL;
}
