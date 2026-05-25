/*
** EPITECH PROJECT, 2025
** my_isalpha.c
** File description:
** just a file
*/

#include "../include/stumper.h"

int my_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
