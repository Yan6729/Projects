/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** A function who create array
*/

#include "../include/tail.h"

int count_lines(char const *str)
{
    int lines = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            lines++;
        }
    }
    return lines + 1;
}

int count_col(char const *str, int a)
{
    int j = a;

    for (; str[j] != '\n' && str[j] != '\0'; j++);
        return j;
}

char **split_array(char const *str)
{
    int i = 0;
    int j = 0;
    int b;
    int lines = count_lines(str);
    int col = 0;
    char **array = malloc(sizeof(char *) * (lines + 1));

    for (int a = 0; a < lines; a++) {
        col = count_col(&str[i], a);
        array[a] = malloc(sizeof(char) * (col + 1));
        for (b = 0; b < col; b++) {
            array[a][b] = str[j];
            j++;
        }
        array[a][b] = '\0';
        j++;
        i = j;
    }
    array[lines] = NULL;
    return array;
}
