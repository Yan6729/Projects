/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** my_strcmp
*/

#include <string.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;
    int difference;

    for (; s1[i] != '\0' || s2[j] != '\0'; i++) {
        if (s1[i] != s2[j]) {
            difference = s1[i] - s2[j];
            return difference;
        }
        j++;
    }
    return 0;
}
