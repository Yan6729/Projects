/*
** EPITECH PROJECT, 2024
** str_to_word_array
** File description:
** str to word array
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"

int handle_first_space(char *str)
{
    int i = 0;
    int a = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\t' && str[i] != ' ') {
            a = i;
            break;
        }
    }
    return a;
}

int separt(int i, char *str)
{
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    return i - 1;
}

int is_space(char c, char signe)
{
    int count = 0;

    if (c == signe)
        return 0;
    else
        return 1;
}

int clean_str1(char *str, int a)
{
    int j = 0;

    for (int i = a; str[i] != '\0'; i++) {
        if (i > 1 && (is_space(str[i], ' ') == 0
        || (((is_space(str[i - 1], '\t') == 1
        && (is_space(str[i], '\t') == 0)))))) {
            i = separt(i, str);
            str[j] = ' ';
            j++;
        } else {
            str[j] = str[i];
            j++;
        }
    }
    return j;
}

int clean_str(char *str)
{
    int j = 0;
    int a = handle_first_space(str);

    j = clean_str1(str, a);
    if (j > 0 && (is_space(str[j - 1], ' ') == 0
    || is_space(str[j - 1], '\t') == 0
    || is_space(str[j - 1], '\n') == 0)) {
        j--;
    }
    str[j] = '\0';
}
