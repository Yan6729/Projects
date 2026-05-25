/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** my_putstr.c
*/
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"
int my_putstr(char const *str)
{
    int a;

    a = 0;
    while (str[a] != '\0') {
        a++;
    }
}
