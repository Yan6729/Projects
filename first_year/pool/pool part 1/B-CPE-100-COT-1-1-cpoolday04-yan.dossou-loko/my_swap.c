/*
** EPITECH PROJECT, 2024
** my_swap.c
** File description:
** my_swap.c
*/
#include <stdio.h>
#include <unistd.h>

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
