/*
** EPITECH PROJECT, 2025
** strtowordarry.c
** File description:
** just a file
*/

#include "../../include/robot.h"

int is_delim(char c, const char *delim)
{
    for (int i = 0; delim[i] != '\0'; i++) {
        if (c == delim[i])
            return 1;
    }
    return 0;
}

int count_words(char *str, const char *delim)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] != '\0' && is_delim(str[i], delim) == 1)
            i++;
        if (str[i] != '\0')
            count++;
        while (str[i] != '\0' && is_delim(str[i], delim) == 0)
            i++;
    }
    return count;
}

char **free_strtab(int k, char **tab)
{
    if (!tab[k]) {
        for (int l = 0; l < k; l++)
            free(tab[l]);
        free(tab);
        return NULL;
    }
}

index_t struct_val(char *str, const char *delim)
{
    index_t lib;

    lib.i = 0;
    lib.j = 0;
    lib.k = 0;
    lib.lig = count_words(str, delim);
    return lib;
}

char **my_split(char *str, const char *delim)
{
    index_t lib = struct_val(str, delim);
    char **tab = malloc(sizeof(char *) * (lib.lig + 1));

    for (lib.i = 0; str[lib.i] != '\0';) {
        while (str[lib.i] != '\0' && is_delim(str[lib.i], delim) == 1)
            lib.i++;
        if (str[lib.i] == '\0')
            break;
        lib.j = lib.i;
        while (str[lib.j] != '\0' && is_delim(str[lib.j], delim) == 0)
            lib.j++;
        tab[lib.k] = malloc(sizeof(char) * (lib.j - lib.i + 1));
        free_strtab(lib.k, tab);
        my_strncpy(tab[lib.k], &str[lib.i], lib.j - lib.i);
        tab[lib.k][lib.j - lib.i] = '\0';
        lib.k++;
        lib.i = lib.j;
    }
    tab[lib.k] = NULL;
    return tab;
}
