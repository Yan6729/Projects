/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** compare two charaters
*/

#include <stdio.h>

int my_strcmp(char *str1, char *str2)
{
    int a;
    int result = 0;

    for (a = 0; str1[a] != '\0' && str2[a] != '\0'; a++) {
        if (str1[a] < str2[a]) {
            result = -1;
            break;
        }
        if (str1[a] > str2[a]){
            result = 1;
            break;
        } else
            continue;
    }
    return result;
}
