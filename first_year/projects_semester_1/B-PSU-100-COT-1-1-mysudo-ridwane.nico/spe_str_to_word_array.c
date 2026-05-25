/*
** EPITECH PROJECT, 2024
** str_to_word_array
** File description:
** one word in one array
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void my_free(char **str)
{
    for (int i = 1; str[i] != NULL; i++) {
        free(str[i]);
    }
    free(str);
}

int analyse_str2(char c)
{
    if (c > 64 && c < 91 || c > 96 && c < 123 || c > 47 && c < 58) {
    return 1;
    } else if (c == ':') {
    return 0;
    }
}

int count_words2(char const *str)
{
    int num = 0;

    for (int i = 0; str[i] != '\0'; i++) {
    if (analyse_str2(str[i]) == 1 && analyse_str2(str[i + 1]) == 0)
    num++;
    }
    return num;
}

char **spe_str_to_word_array(char const *str)
{
    int len = 0;
    int j = 0;
    int nbr = count_words2(str);
    char **src = (char **)malloc((nbr + 1) * sizeof(char *));

    for (int i = 0; i < strlen(str); i++) {
    if (analyse_str2(str[i]))
    len++;
    if (analyse_str2(str[i]) && analyse_str2(str[i + 1]) == 0) {
        src[j] = (char *)malloc((len + 1) * sizeof(char));
        strncpy(src[j], &str[i - len + 1], len);
        src[j][len] = '\0';
    len = 0;
    j++;
    }
    }
    src[j] = NULL;
    return src;
}
